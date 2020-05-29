
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
a = len('ABCDE')  #对于str类型，len函数是求str的字符数
print(a)


b = len('中文')
print(b)



c = len('ABCFD'.encode('ascii')) #对于bytes型，len函数是计算bytes类型的字节数
print(c)

d = len('中文吗'.encode('utf-8')) #将中文编码成utf-8，每个汉字通常占用3个自己
print(d)


