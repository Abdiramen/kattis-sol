import sys

given = [int(s) for s in sys.stdin.read().split()]
r = given[0]
n = given[1]

if r == n:
    print("too late")
elif n == 0:
    print(r)
else:
    for i in range(1, r+1):
        if i not in given[2:]:
            print(i)
            break
