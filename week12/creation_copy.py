from sys import stdout, stdin
import math, time


 
def nCrModpDP(n, r, p):
     
    C = [0] * (n + 1);
    C[0] = 1;
    for i in range(1, (n + 1)):        
        j = min(i, r);
        while(j > 0):
            C[j] = (C[j] + C[j - 1]) % p;
            j -= 1;
    return C[r];
 
def nCrModpLucas(n, r, p):
     
    if (r == 0):
        return 1;
         
    ni = int(n % p);
    ri = int(r % p);
         
    return (nCrModpLucas(int(n / p), int(r / p), p) *
        nCrModpDP(ni, ri, p)) % p;

t = int(stdin.readline())
for j in range(t):
    lower, upper, r = map(int, stdin.readline().split())

    if r == 2:
        print(1)
        continue

    n = upper-lower + 1
    p = r - 2

    start = time.process_time()

    print(nCrModpLucas(n+p-1,n-1,1000000007))
    print("%f" % ((time.process_time() - start)))
    