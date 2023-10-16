T = int(input())
for _ in range(T):
    dest = 0
    B = []
    N = int(input())
    for _ in range(N):
        X,Y = [int(x) for x in input().split(" ")]
        B.append([X/Y,X,Y])
    K = int(input())
    R = int(input())
    def s(e):
        return [e[0],-e[1]]
    
    B.sort(key=s,reverse=True)
    for a in B:print(a)
    for x in B: 
        if(K-x[2]>=0):
            dest += x[1]
            K -= x[2]
    print( "Missao completada com sucesso" if (dest>=R) else "Falha na missao")