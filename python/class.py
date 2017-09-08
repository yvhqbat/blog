class MyClass:
    """a simple example class"""
    i=12345

    def f(self):
        return "hello word"

    # 构造函数
    #def __init__(self):
    #    self.data=[]

    def __init__(self, m, n):
        self.m=m
        self.n=n


x = MyClass(4,7)
print(x.i)
print(x.f())
print(MyClass.__doc__)

y=MyClass(3,5)
print(y.m,y.n)

class Dog:
    kind='tidy'  # class variable shared by all instances
    def __init__(self, name):
        self.name=name  # instance variable unique to each instance
        self.tricks=[]
    def add_trick(self, trick):
        self.tricks.append(trick)

d=Dog('fibbi')
e=Dog('bobbi')
f=Dog('cc')
print(d.kind, d.name)
print(e.kind, e.name)
d.kind='new'  # failed
print(f.kind, f.name)
d.add_trick('roll over')
e.add_trick('play dead')
print(d.tricks)
print(e.tricks)

