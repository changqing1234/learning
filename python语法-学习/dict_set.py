d  = {'Micheal':95, 'Bob':75, 'Tracy':85}
index =  d['Micheal']
print(index)

d['Adam'] = 67
print(d['Adam'])

d['Adam'] = 898
print(d['Adam'])





s  =  set([1,2,3, 56,4])
print(s)


s.add(78)
print(s)


s.remove(4)
print(s)



#求两个集合的交集
s1 = set([1, 2, 3])
s2 = set([2, 3, 4])
print(s1 & s2)


#求两个集合的并集
s1 = set([1, 2, 3])
s2 = set([2, 3, 4])
print(s1 | s2)
