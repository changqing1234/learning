import numpy as np
import math
import copy


class codedML:
    def __init__(self):
        pass

    # 四舍五入
    def round(self, x):
        for i in range(x.shape[0]):
            for j in range(x.shape[1]):
                a = math.floor(x[i, j])
                if x[i, j] - a < 0.5:
                    x[i, j] = a
                else:
                    x[i, j] = a + 1
        return x

    # 以固定概率取得数据，期望值为X
    def proMap(self, x):
        np.random.seed(0)
        for i in range(x.shape[0]):
            for j in range(x.shape[1]):
                p1 = [1 - (x[i, j] - math.floor(x[i, j])), x[i, j] - math.floor(x[i, j])]
                x[i, j] = np.random.choice([math.floor(x[i, j]), math.floor(x[i, j]) + 1], 1,  p=p1)
        return x

    #利用随机量化数据来进行r次生成权值矩阵
    def generateW(self, w, r):
        W = []
        for i in range(r):
            wt = self.proMap(w)
            W.append(wt.tolist()[0])

        return np.array(W).reshape(len(w[0]), r)

        # 将数据转为正整数
    def map(self, p, X):
        for i in range(X.shape[0]):
            for j in range(X.shape[1]):
                if X[i][j]<0:
                    X[i,j] =  p+X[i, j]
        return X


    def partition(self, X):
        pass

w = 0.1*np.random.randint(20, 120, 6).reshape(1, 6)
c = codedML()

p = 15485863
W = c.generateW(w, 10)
print(c.map(p, W))
