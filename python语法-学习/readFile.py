file = open('my_file.txt', 'r')
content = file.readline()

print(content)
next = file.readline()
print(next)

file.close()
