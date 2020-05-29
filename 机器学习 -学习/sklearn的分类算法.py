import numpy as np
from sklearn.linear_model import LogisticRegression, SGDClassifier
from sklearn.model_selection import train_test_split, cross_val_score
from sklearn.preprocessing import StandardScaler, MinMaxScaler
from sklearn import datasets
from sklearn.metrics import accuracy_score
from sklearn.svm import SVC
from sklearn.neighbors import KNeighborsClassifier
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import RandomForestClassifier
from sklearn.naive_bayes import GaussianNB
import tensorflow as tf
from tensorflow.examples.tutorials.mnist import input_data


#加载mnist手写体数据集
MNIST_data =r'C:\Users\changqing\Desktop\数据集\MNIST_data'
mnist = input_data.read_data_sets(MNIST_data,one_hot=True)

#将十位的标签表示成一位的数字
x_train = mnist.train.images
y_train = 1 + np.where(mnist.train.labels==1)[1]

x_test = mnist.test.images
y_test = 1 + np.where(mnist.test.labels==1)[1]


# #加载鸢尾花数据集
# load_data = datasets.load_iris()
# data_x = load_data.data
# data_y = load_data.target

# #加载手写体数据集
# load_data = datasets.load_digits()
# data_x = load_data.data
# data_y = load_data.target
#
# #拆分数据集
# x_train, x_test, y_train, y_test = train_test_split(data_x, data_y, test_size=0.3, random_state=1)

# #数据标准化效果好
# scaler = StandardScaler()
# x_train = scaler.fit_transform(x_train)
# x_test = scaler.transform(x_test)

#数据归一化
scaler = MinMaxScaler()
x_train = scaler.fit_transform(x_train)
x_test = scaler.transform(x_test)

# #逻辑回归
# model = LogisticRegression(random_state=0)
# model.fit(x_train, y_train)
# predicted = model.predict(x_test)
# print('逻辑回归的精度：', accuracy_score(y_test, predicted))

#随机梯度下降逻辑回归
model = SGDClassifier(random_state=0)
model.fit(x_train, y_train)
predicted = model.predict(x_test)
print('SGD的逻辑回归的精度:', accuracy_score(y_test, predicted))

# #支持向量机分类svc
# model = SVC(kernel='linear', random_state=0)
# model.fit(x_train, y_train)
# predicted = model.predict(x_test)
# print('支持向量机svc分类的精度:', accuracy_score(y_test, predicted))

# #交叉验证
# score = cross_val_score(model, data_x, data_y, cv = 3)

#knn分类
model = KNeighborsClassifier(n_neighbors=10)
model.fit(x_train, y_train)
predicted = model.predict(x_test)
print('knn的精度：', accuracy_score(y_test, predicted))

#决策树分类
model = DecisionTreeClassifier(random_state=0)
model.fit(x_train, y_train)
predicted = model.predict(x_test)
print('决策树的精度：', accuracy_score(y_test, predicted))

#随机深林分类
model = RandomForestClassifier(random_state=0)
model.fit(x_train, y_train)
predicted = model.predict(x_test)
print('随机深林的精度：', accuracy_score(y_test, predicted))

#基于高斯分布的朴素贝叶斯分类
model = GaussianNB()
model.fit(x_train, y_train)
predicted = model.predict(x_test)
print('基于高斯分布的朴素贝叶斯的精度：', accuracy_score(y_test, predicted))







