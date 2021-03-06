import numpy as np
import matplotlib.pyplot as plt

#原理地址 https://www.jianshu.com/p/d8a4d3b9ded0
"""
利用 Python 实现线性回归模型
"""

#定义线性回归类
class LinerRegressionModel(object):
    def __init__(self, data):
        self.data = data
        self.x = data[:, 0]
        self.y = data[:, 1]

    def log(self, a, b):
        print("计算出的线性回归函数为:\ny = {:.5f}x + {:.5f}".format(a, b))

    #将数据进行绘图
    def plt(self, a, b):
        plt.plot(self.x, self.y, 'o', label='data', markersize=10)
        plt.plot(self.x, a * self.x + b, 'r', label='line')
        plt.legend()
        plt.show()

    #最小二乘法训练模型
    def least_square_method(self):
        """
        最小二乘法的实现
        """
        def calc_ab(x, y):
            sum_x, sum_y, sum_xy, sum_xx = 0, 0, 0, 0
            n = len(x)
            for i in range(0, n):
                sum_x += x[i]
                sum_y += y[i]
                sum_xy += x[i] * y[i]
                sum_xx += x[i]**2
            a = (sum_xy - (1/n) * (sum_x * sum_y)) / (sum_xx - (1/n) * sum_x**2)
            b = sum_y/n - a * sum_x/n
            return a, b
        a, b = calc_ab(self.x, self.y)
        self.log(a, b)
        self.plt(a, b)


#用numpy库生成数据， 前一个是数据属性值，后一个是回归值（x, y）
data = np.array([[1, 2.5], [2, 3.3], [2.5, 3.8],[3, 4.5], [4, 5.7], [5, 6]])

#训练模型
model = LinerRegressionModel(data)
model.least_square_method()