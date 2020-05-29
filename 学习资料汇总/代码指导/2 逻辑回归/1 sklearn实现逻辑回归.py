from __future__ import print_function
import numpy as np
from sklearn.linear_model import LogisticRegression
from sklearn import datasets
from sklearn.model_selection import train_test_split

iris = datasets.load_iris()

x_train, x_test, y_train, y_test = train_test_split(iris.data, iris.target, test_size=0.2)
# X = np.array([-2, -1, 0, 1, 2, 1]).reshape(-1, 1)
# y = np.array([0, 0, 1, 1, 1, 0])
lr = LogisticRegression()
lr.fit(x_train, y_train)
score = lr.score(x_test, y_test)
print('模型精度: ', score)