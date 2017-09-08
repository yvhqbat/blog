def scope_test():
    def do_local():
        spam="local spam"
    def do_nonlocal():
        nonlocal spam
        spam="nonlocal spam"
    def do_global():
        global spam
        spam="global spam"
    spam="test spam"
    print(spam)
    do_local()
    print(spam)
    do_nonlocal()
    print(spam)
    do_global()
    print(spam)

scope_test()
print(spam)

