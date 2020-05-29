print("包含中文的str")  #python3的编码都是Unicode编码,支持多语言
a = ord('A')    #ord(char a)函数返回字符的unicode编码数值
b = ord('中')
c = chr(66)         #chr函数将编码转换成字符
d = chr(25991)
print(a, b, c, d)



##使用的是全英文,转换时可以使用ascii
x = 'ABC'   #使用的是Unicode编码，占用两个字节
print(x)


y = x.encode('ascii')  #将ascii编码成bytes
print(y) 

print(y.decode('ascii'))  #将y进行解码



#h含有中文的,转化时可以使用utf-8编码成bytes，不能ascii编码成bytes
e = '中国'
print(e)

f =e.encode('utf-8')
print(f)


print(f.decode('utf-8')) #将f进行解码

