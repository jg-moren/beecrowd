N = int(input())
def c (x):
    return len(x)
    
for _ in range(N):
    palavras = input().split(" ")
    palavras.sort(key=c,reverse=True)
    print(" ".join(palavras))