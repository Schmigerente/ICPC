from sys import stdout, stdin

fac = [1]
for j in range(1, 1001):
    fac.append(fac[-1] * j)

t = int(stdin.readline())
for j in range(t):
    n = int(stdin.readline())
    print(fac[n])