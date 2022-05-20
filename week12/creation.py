from sys import stdout, stdin
import math, time

m = 1000000007
factorial = [0] * 200000

def inverse(n):
    return pow(n, m-2, m)

def binomial(n, k):
    return factorial[n] * inverse(factorial[k] * factorial[n - k] % m) % m;

factorial[0] = 1
for i in range(1, 200000):
    factorial[i] = factorial[i - 1] * i % m

t = int(stdin.readline())
for j in range(t):
    lower, upper, r = map(int, stdin.readline().split())
    if r == 2:
        print(1)
        continue
    n = upper-lower + 1
    p = r - 2
    print(binomial(n+p-1,n-1))
    