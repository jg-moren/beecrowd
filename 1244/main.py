N = int(input())
def c (x):
    return len(x)
    
for _ in range(N):
    palavras = input().split(" ")
    palavras.sort(key=c,reverse=True)
    for palavra in palavras:
        print(palavra,end="")
        if(palavra!=palavras[-1]):print(end=" ")
    print()