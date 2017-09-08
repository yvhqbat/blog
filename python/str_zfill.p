for x in range(1,10):
    print(str(x).zfill(5),' ',str(x*x).zfill(5),' ',str(x*x*x).zfill(5))

print('{0} and {1}'.format('dog','cat'))
print('{1} and {0}'.format('dog','cat'))

print('the story of {0}, {1}, and {other}'.format('bill','manfred',other='georg'))

contents = 'eels'
print('my hovercraft is full of {}'.format(contents))

key_value = {'liudong':25, 'caipei':26}
print(key_value['liudong'])
for name, age in key_value.items():
    print('{0:10} ==> {1:10d}'.format(name,age))

