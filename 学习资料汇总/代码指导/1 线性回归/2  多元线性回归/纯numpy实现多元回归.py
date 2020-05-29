import numpy as np
import matplotlib.pyplot as plt
from sklearn import datasets

#原理地址 https://www.jianshu.com/p/d8a4d3b9ded0
"""
利用 Python 实现线性回归模型
"""
class LinerRegressionModel(object):
    def __init__(self, data):
        self.data = data

        #给数据集增加一列1数组
        b = np.ones((len(data.data), 1))
        self.x = np.hstack((data.data, b))
        self.y = data.target.reshape((len(data.target), 1))

    def least_square_method(self, predict_data, predict_label):
        """
        最小二乘法的实现
        """
        output1 = np.linalg.inv(np.dot(self.x.T, self.x))
        output2 = np.dot(output1, self.x.T)

        output = np.dot(output2, self.y)
        #output = np.squeeze(output)

        print(output.shape)
        print(predict_data.shape)
        output = np.dot(predict_data, output)

        print('预测误差矩阵为', output-predict_label)

data = datasets.load_boston()



model = LinerRegressionModel(data)

b = np.ones((len(data.data), 1))
predict_data = np.hstack((data.data, b))
model.least_square_method(predict_data[1:4,...], data.target[1:4,...])