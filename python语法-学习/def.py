append_text = '\n this is appended file.'
print(append_text)
myfile = open('my_file.txt', 'a')
myfile.write(append_text)
myfile.close()
