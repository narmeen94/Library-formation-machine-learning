import numpy as np
import time

# save theta to p5_params.npz that can be used by easynn
def save_theta(theta):
    f1_W, f1_b, f2_W, f2_b = theta

    np.savez_compressed("p5_params.npz", **{
        "f1.weight": f1_W,
        "f1.bias": f1_b,
        "f2.weight": f2_W,
        "f2.bias": f2_b
    })


# initialize theta using uniform distribution [-bound, bound]
# return theta as (f1_W, f1_b, f2_W, f2_b)
def initialize_theta(bound):
    f1_W = np.random.uniform(-bound, bound, (32, 784))
    f1_b = np.random.uniform(-bound, bound, 32)
    f2_W = np.random.uniform(-bound, bound, (10, 32))
    f2_b = np.random.uniform(-bound, bound, 10)
    return (f1_W, f1_b, f2_W, f2_b)


# forward:
#   x = Flatten(images)
#   g = Linear_f1(x)
#   h = ReLU(g)
#   z = Linear_f2(h)
# return (z, h, g, x)
def forward(images, theta):
    # number of samples
    N = images.shape[0]

    # unpack theta into f1 and f2
    f1_W, f1_b, f2_W, f2_b = theta

    # x = Flatten(images)
    x = images.astype(float).transpose(0,3,1,2).reshape((N, -1)) #-1 puts elements into single dimension

    # g = Linear_f1(x)
    g = np.zeros((N, f1_b.shape[0]))
    for i in range(N):
        g[i, :] = np.matmul(f1_W, x[i])+f1_b

    # h = ReLU(g)
    h = g*(g > 0)

    # z = Linear_f2(h)
    z = np.zeros((N, f2_b.shape[0]))
    for i in range(N):
        z[i, :] = np.matmul(f2_W, h[i])+f2_b

    return (z, h, g, x)


# backprop:
#   J = cross entropy between labels and softmax(z)
# return nabla_J
def backprop(labels, theta, z, h, g, x):
    # number of samples
    N = labels.shape[0]
    

    # unpack theta into f1 and f2
    f1_W, f1_b, f2_W, f2_b = theta

   # print("this is the number of samples: ")
   # print(N)
   # print("this is the shape of f1_W:"+str(f1_W.shape))
    # print("this is the shape of f1_b:"+str(f1_b.shape))
    # print("this is the shape of f2_W:"+str(f2_W.shape))
    # print("this is the shape of f2_b:"+str(f2_b.shape))
    # print("this is the shape of h:"+str(h.shape))
    # print("this is the shape of z:"+str(z.shape))
    # print("this is the shape of g:"+str(g.shape))

    # nabla_J consists of partial J to partial f1_W, f1_b, f2_W, f2_b
    p_f1_W = np.zeros(f1_W.shape)
    p_f1_b = np.zeros(f1_b.shape)
    p_f2_W = np.zeros(f2_W.shape)
    p_f2_b = np.zeros(f2_b.shape)

    for i in range(N):
        # compute the contribution to nabla_J for sample i

        # cross entropy and softmax
        #   compute partial J to partial z[i]
        #   scale by 1/N for averaging
        expz = np.exp(z[i]-max(z[i]))
        p_z = expz/sum(expz)/N
        p_z[labels[i]] -= 1/N
        #print("this is the shape of p_z:"+str(p_z.shape))

        # z = Linear_f2(h)
        #   compute partial J to partial h[i]
        #   accumulate partial J to partial f2_W, f2_b
        # ToDo: uncomment code below to add your own code
        f2_w_trans=np.transpose(f2_W)
        p_h = np.matmul(f2_w_trans,p_z)
        #p_f2_W += np.matmul(p_z.reshape(10,1),h[i,:]) #for each
        #p_f2_W += np.matmul(p_z,h[i,:])
        p_f2_W += np.matmul(p_z.reshape(10,1),h[i].reshape(1,32))
        p_f2_b += p_z
        #print("this is h[i]")
        #print(h[i])

        # h = ReLU(g)
        #   compute partial J to partial g[i]
        # ToDo: uncomment code below to add your own code
        p_g = 1*(g[i]>0)*p_h #applying step function since it is the derivative of Relu

        #np.zeros(p_g.shape[0])
        #print("the shape of p_g is:"+str(p_g.shape)) #(4,32)
        #print('the shape of x:'+str(x.shape))
        #print("the shape of p_h is:"+str(p_h.shape))

        # g = Linear_f1(x)
        #   accumulate partial J to partial f1_W, f1_b
        # ToDo: uncomment code below to add your own code
        p_f1_W += np.matmul(p_g.reshape(32,1),x[i].reshape(1,784))
        #p_f1_b += p_g[i,:]
        p_f1_b += p_g

    return (p_f1_W, p_f1_b, p_f2_W, p_f2_b)


# apply SGD to update theta by nabla_J and the learning rate epsilon
# return updated theta
def update_theta(theta, nabla_J, epsilon):
    # ToDo: modify code below as needed
    theta_out=tuple([epsilon*j for j in nabla_J]) #forming a tuple of all the things in nabla j*epsilon
    updated_theta=list(theta)
    for elem in range (len(theta_out)):
        updated_theta[elem]=theta[elem]-theta_out[elem] #the actual SGD equation
    


    #updated_theta = theta-epsilon*nabla_J
    return updated_theta


# ToDo: set numpy random seed to the last 8 digits of your CWID
np.random.seed(20492404)

# load training data and split them for validation/training
mnist_train = np.load("mnist_train.npz")
validation_images = mnist_train["images"][:1000]
validation_labels = mnist_train["labels"][:1000]
training_images = mnist_train["images"][1000:]
training_labels = mnist_train["labels"][1000:]

# hyperparameters
#bound = 1  # initial weight range
bound=0.01 #my tries #works great, all tests pass for bound 0.01
epsilon = 0.00001 # learning rate
#epsilon = 0.01 #my try
#batch_size = 4
batch_size = 1

# start training
start = time.time()
theta = initialize_theta(bound)
batches = training_images.shape[0]//batch_size
for epoch in range(10):
    indices = np.arange(training_images.shape[0])
    np.random.shuffle(indices)
    for i in range(batches):
        batch_images = training_images[indices[i*batch_size:(i+1)*batch_size]]
        batch_labels = training_labels[indices[i*batch_size:(i+1)*batch_size]]

        z, h, g, x = forward(batch_images, theta)
        nabla_J = backprop(batch_labels, theta, z, h, g, x)
        theta = update_theta(theta, nabla_J, epsilon)

    # check accuracy using validation examples
    z, _, _, _ = forward(validation_images, theta)
    pred_labels = z.argmax(axis = 1)
    count = sum(pred_labels == validation_labels)
    print("epoch %d, accuracy %.3f, time %.2f" % (
        epoch, count/validation_images.shape[0], time.time()-start))

# save the weights to be submitted
save_theta(theta)
