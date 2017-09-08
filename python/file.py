# reading and writing files.

file = 'test.py'
f = open(file,'r')
data = f.read()
#f.close()
print(data)

data = f.read()
print(data)
f.close()

f = open(file,'r')
line = f.readline()
print(line)
f.close()

f = open(file,'r')
lines = f.readlines()
for line in lines:
    print(line)





