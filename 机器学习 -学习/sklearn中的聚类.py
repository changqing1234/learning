import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import make_blobs
from sklearn.cluster import KMeans
from sklearn import metrics
'''
使用make_blobs生成n类数据，n_samples代表总共样本点，
n_features是每个样本的维度，centers表示类别数（可传入每一类的中心列表），
cluster_std表示每个类别的方差,shuffle表示是否将数据打散（打散后聚类的难度更高）
random_state表示随机化种子，不穿的话默认每次生成的效果都不一样
make_blobs返回两个值，第一个值是坐标点数组，第二个值是一个列表，标定每个坐标点属于哪个类
'''
X, y = make_blobs(n_samples=1000, n_features=2, centers=3, cluster_std=0.5, shuffle=True, random_state=10)
#random_state关系到聚类中心的选择，如果选择不当会导致聚类结果大失所望
km = KMeans(n_clusters=3,random_state = 0)
y_pre = km.fit_predict(X)
score=metrics.calinski_harabasz_score(X, y_pre)
print(score)
#统计分类正确与错误的点，并生成颜色列表（后面可视化要用到）
def judge(y,y_pre):
    blue=0
    red=0
    colorArr=[]
    for i in range(len(y)):
        if(y[i]==y_pre[i]):
            blue=blue+1
            colorArr.append('blue')
        else:
            red=red+1
            colorArr.append('red')
    print('分类正确：', blue, "分类错误：", red)
    return colorArr
colrArr=judge(y,y_pre)
#将得到的结果进行整理，方便绘图
def split(arr):
    x_axis=[]
    y_axis=[]
    for i in range(len(arr)):
        x_axis.append(arr[i][0])
        y_axis.append(arr[i][1])
    return x_axis,y_axis
fig=plt.figure()
(x_axis,y_axis)=split(X)
#聚类正确的点标蓝色，聚类错误的点标红色
plt.scatter(x_axis,y_axis,c=colrArr,s=10)
plt.show()

