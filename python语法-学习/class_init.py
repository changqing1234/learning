class Calculator:
    name='good calculator'
    price=18
    def __init__(self,name,price): #后面三个属性设置默认值,查看运行
        self.name=name
        self.price=price

    def add(self, x, y):
        print(x+y)

cal = Calculator('test', 20)
cal.add(45, 67)
print(cal.name)
