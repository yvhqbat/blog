form urllib.request import urlopen

with urlopen('www.baidu.com') as response:
    for line in response:
        line=line.decode('utf-8')
        print(line)
