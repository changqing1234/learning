import numpy as np

np.random.seed(0)

class network:

    #初始化训练参数
    def __init__(self, input, label, learnRate=0.1, iteration=2000):
        self.input = input
        self.label = label
        self.learnRate = learnRate
        self.iteration = iteration


    #初始化参数矩阵
    def weight_matrix(self, input_size=2, hidden1_size=3, hidden2_size=2, output_size=1):
       
       self.weight_input_hidden1 = np.random.rand(hidden1_size, input_size)
       self.bias_input_hidden1 = np.ones((hidden1_size, 1))

       self.weight_hidden1_hidden2 = np.random.rand(hidden2_size, hidden1_size)
       self.bias_hidden1_hidden2 = np.ones((hidden2_size, 1))

       self.weight_hidden2_output = np.random.rand(output_size, hidden2_size)
       self.bias_hidden2_output = np.ones((output_size, 1))

    #计算激活函数
    def sigmoid(self, x):
        return 1/(1+np.exp(-x))

    #计算激活函数的导数
    def dsigmoid(self, x):
        return self.sigmoid(x) * (1-self.sigmoid(x))


    #前向传播，计算各个神经元的加权值和激活值
    def forward(self):

        #加权值
        self.sum_hidden1 = self.weight_input_hidden1.dot(self.input) + self.bias_input_hidden1

        #激活值
        self.activate_hidden1 = self.sigmoid(self.sum_hidden1)

        self.sum_hidden2 = self.weight_hidden1_hidden2.dot(self.activate_hidden1) + self.bias_hidden1_hidden2
        self.activate_hidden2 = self.sigmoid(self.sum_hidden2)

        self.sum_output =  self.weight_hidden2_output.dot(self.activate_hidden2) + self.bias_hidden2_output
        self.activate_output = self.sigmoid(self.sum_output)

    #反向传播，更新权值
    def backward(self):
        self.delta_output = self.label - self.activate_output
        self.delta_output = self.delta_output[0]


        for i in range(len(self.delta_output)):
            print('第%d轮训练'  %i)
            self.delta_hidden2 = (self.weight_hidden2_output.T) * (self.delta_output[i])
            self.delta_hidden1 = self.weight_hidden1_hidden2.T.dot(self.delta_hidden2)

            sum_hidden1 = self.sum_hidden1[:, i][:, None]
            input = self.input[:, i][None]

            sum_hidden2 = self.sum_hidden2[:, i][:, None]
            activate_hidden1 = self.activate_hidden1[:, i][None]

            sum_output = self.sum_output[:, i][:, None]
            activate_hidden2 = self.activate_hidden2[:, i][None]

            self.weight_input_hidden1 = self.weight_input_hidden1 + self.learnRate * self.delta_hidden1 * self.dsigmoid(sum_hidden1).dot(input)
            self.weight_hidden1_hidden2 = self.weight_hidden1_hidden2 + self.learnRate * self.delta_hidden2 * self.dsigmoid(sum_hidden2).dot(activate_hidden1)
            self.weight_hidden2_output = self.weight_hidden2_output + self.learnRate * self.delta_output[i] * self.dsigmoid(sum_output).dot(activate_hidden2)

    def predict(self, data, label):
        # 加权值
        self.sum_hidden1 = self.weight_input_hidden1.dot(data) + self.bias_input_hidden1
        # 激活值
        self.activate_hidden1 = self.sigmoid(self.sum_hidden1)

        self.sum_hidden2 = self.weight_hidden1_hidden2.dot(self.activate_hidden1) + self.bias_hidden1_hidden2
        self.activate_hidden2 = self.sigmoid(self.sum_hidden2)

        self.sum_output = self.weight_hidden2_output.dot(self.activate_hidden2) + self.bias_hidden2_output
        self.activate_output = self.sigmoid(self.sum_output)

        self.activate_output[self.activate_output>0.5] = 1
        self.activate_output[self.activate_output<=0.5] = 0

        accuray = np.sum(self.activate_output - label==0)/len(label)



        print('精度为:%f' %accuray)


if __name__ == '__main__':
    data = np.random.uniform(10, 120, 100000).reshape((2, 50000))

    label = np.random.randint(0, 2, data.shape[1])

    net = network(data[..., :25000], label[:25000:1], 0.1, 100)
    net.weight_matrix(2, 3, 2, 1)

    net.forward()

    net.backward()

    net.predict(data[..., 25000:], label[25000:])



