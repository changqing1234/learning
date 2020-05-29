# -*- coding: utf-8 -*-
"""
Created on Fri Jul 27 17:47:03 2018

@author: dj
"""
import numpy as np
import torch
from torchvision.datasets import mnist # 导入 pytorch 内置的 mnist 数据
from torch import nn#从torch模块中导出nn模块
from torch.autograd import Variable#导出Variable

#数据集处理函数
def data_tf(x):
    x = np.array(x, dtype='float32') / 255
    x = (x - 0.5) / 0.5 # 标准化，
    x = x.reshape((-1,)) # 拉平
    x = torch.from_numpy(x)
    return x

train_set = mnist.MNIST('./dataset/', train=True, transform=data_tf, download=True) # 重新载入数据集即数据集路径，申明定义的数据变换，即对数据的处理导入，download=True时没找到数据集将会对其进行下载
test_set = mnist.MNIST('./dataset/', train=False, transform=data_tf, download=True)#制作测试集
a, a_label = train_set[0]#读取测试集中第一个数据
print(a.shape)#数据的大小
print(a_label)#数据的标签

from torch.utils.data import DataLoader#导入DataLoader，在torch中需要dataloader进行迭代
train_data = DataLoader(train_set, batch_size=64, shuffle=True)#训练集，，shuffle为True时打乱数据，让数据更有选择随机性
test_data = DataLoader(test_set, batch_size=128, shuffle=False)#对测试集进行迭代器编号
a, a_label = next(iter(train_data))#一个迭代器中的内容
print(a.shape)# 打印出一个批次的数据大小
print(a_label.shape)

net = nn.Sequential(
    nn.Linear(784, 400),
    nn.ReLU(),
    nn.Linear(400, 200),
    nn.ReLU(),
    nn.Linear(200, 100),
    nn.ReLU(),
    nn.Linear(100, 10)
)
#net
# 定义 loss 函数
criterion = nn.CrossEntropyLoss()#交叉熵损失函数
optimizer = torch.optim.SGD(net.parameters(), 1e-1) # 使用随机梯度下降优化器，学习率 0.1

# 定义一些空列表来添加训练得到的一些值
losses = []
acces = []
eval_losses = []
eval_acces = []

for e in range(20):
    train_loss = 0
    train_acc = 0
    net.train()  # 网络开始训练
    for im, label in train_data:
        im = Variable(im)  # 首先将数据打包成Variable
        label = Variable(label)  # 得到标签
        # 前向传播
        out = net(im)
        loss = criterion(out, label)
        # 反向传播
        optimizer.zero_grad()
        loss.backward()
        optimizer.step()
        # 记录误差
        train_loss += loss.item()
        # 计算分类的准确率
        _, pred = out.max(1)  # 挑选出输出时值最大的位置
        num_correct = (pred == label).sum().item()  # 记录正确的个数
        acc = num_correct / im.shape[0]  # 计算精确率
        train_acc += acc

    losses.append(train_loss / len(train_data))
    acces.append(train_acc / len(train_data))

    eval_loss = 0
    eval_acc = 0
    net.eval()  # 将模型改为预测模式
    for im, label in test_data:
        im = Variable(im)
        label = Variable(label)
        out = net(im)
        loss = criterion(out, label)
        # 记录误差
        eval_loss += loss.item()
        # 记录准确率
        _, pred = out.max(1)
        num_correct = (pred == label).sum().item()
        acc = num_correct / im.shape[0]
        eval_acc += acc

    eval_losses.append(eval_loss / len(test_data))
    eval_acces.append(eval_acc / len(test_data))
    print('epoch: {}, Train Loss: {:.6f}, Train Acc: {:.6f}, Eval Loss: {:.6f}, Eval Acc: {:.6f}'
          .format(e, train_loss / len(train_data), train_acc / len(train_data),
                  eval_loss / len(test_data), eval_acc / len(test_data)))
import matplotlib.pyplot as plt
plt.title('train loss')
plt.plot(np.arange(len(losses)), losses)
plt.plot(np.arange(len(acces)), acces)
plt.title('train acc')
plt.plot(np.arange(len(eval_losses)), eval_losses)
plt.title('test loss')
plt.plot(np.arange(len(eval_acces)), eval_acces)
plt.title('test acc')
plt.show()

