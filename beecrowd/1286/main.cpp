#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int>>
#define it vector<int>::iterator
#define s second
#define f first

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e5+10;

using namespace std;

int N,P;

int v[50], p[50], M[50][100];

int knapsack(int c, int n){
   if(M[c][n] != -1)
       return M[c][n];
   if(c <= 0 || n <= 0)
       return 0;
   if(p[n-1] > c){
       M[c][n] = knapsack(c, n-1);
       return M[c][n];
   }
   M[c][n] = max(v[n-1] + knapsack(c - p[n-1], n-1),knapsack(c, n-1));
   return M[c][n];
}

void fun(){
    while(cin>>N && N!=0){
        memset(M,-1,sizeof M);
        cin>>P;
        for(int i=0;i<N;i++){cin>>v[i];cin>>p[i];};
        cout<<knapsack(P,N)<<" min."<<endl;
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