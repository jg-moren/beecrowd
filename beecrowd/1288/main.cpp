#include <bits/stdc++.h>
using namespace std;

int V[55],P[55], M[105][55];

int C,N,K,R;

int knapsack(int c, int n){
    if(M[c][n] != -1)return M[c][n];

    if(c <= 0 || n <= 0)return 0;

    if(P[n-1] > c){M[c][n] = knapsack(c, n-1);return M[c][n];}

    M[c][n] = max(V[n-1] + knapsack(c - P[n-1], n-1),knapsack(c, n-1));
    return M[c][n];
}

void fun(){
    cin>>C;
    while(C--){
        cin>>N;

        memset(M,-1,sizeof M);
        for(int i=0;i<N;i++)cin>>V[i]>>P[i];
        cin>>K>>R;

        int solve = knapsack(K,N);
        cout<<((solve>=R)?"Missao completada com sucesso":"Falha na missao")<<endl;
    }
}

int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   clock_t begin = clock();
   fun();
   clock_t end = clock();
   double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
   //printf("time: %f\n",elapsed_secs);
   return 0;
}