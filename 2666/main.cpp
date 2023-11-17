#include <bits/stdc++.h>
#define vi vector<int>
#define vvd vector<vector<pair<int,int>>>
#define it vector<int>::iterator
#define s second
#define f first

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e4+10;

using namespace std;

int N,C;
vvd g(MAX);
int P[MAX];
int a,b,c;
bool vis[MAX];

int caminho = 0;

void dfs(int v,int peso){
   vis[v]=true;
   for(auto c:g[v])if(!vis[c.f]){
      printf("%d ",c.f);
      if(peso!=0)caminho+=c.s; 
      dfs(c.f,peso+P[v]);
      caminho+=c.s;
   }

   vis[v]=false;
}

void fun(){
   cin>>N>>C;
   for(int i=1;i<=N;i++)cin>>P[i];
   for(int i=0;i<N-1;i++){
      cin>>a>>b>>c;
      g[a].push_back({b,c});
      g[b].push_back({a,c});
   };
   dfs(1,P[1]);printf("\n");
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