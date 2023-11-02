#include <bits/stdc++.h>
#define vi vector<int>
#define vii vector<vector<int>>
#define it vector<int>::iterator
#define s second
#define f first

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 2e2+10;

using namespace std;

int H,L;
int M[MAX][MAX];
bool vis[MAX][MAX];
int cam[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int maior=0,b;
int menor_a = INF;
set<int> adj;

int dfs(int i,int j,int v){
    vis[i][j] = 1;
    int cont=0;
    for(auto c:cam)
        if(
            !vis[i+c[0]][j+c[1]] && 
            (
                (M[i][j]==M[i+c[0]][j+c[1]])||
                (M[i][j]==0&&M[i+c[0]][j+c[1]]==v)||
                (M[i][j]==v&&M[i+c[0]][j+c[1]]==0)
            )&&
            i+c[0]<H && i+c[0]>=0 &&
            j+c[1]<L && j+c[1]>=0 
            ){
            cont += dfs(i+c[0],j+c[1],v);
            cont++;
    }
    return cont;
}


void fill_adj(int i,int j){
    vis[i][j] = 1;
    
    for(auto c:cam)
        if(
            i+c[0]<H && i+c[0]>=0 &&
            j+c[1]<L && j+c[1]>=0 &&
            !vis[i+c[0]][j+c[1]] && 
            M[i][j]==M[i+c[0]][j+c[1]]
            ){
            fill_adj(i+c[0],j+c[1]);
    }else if(
            i+c[0]<H && i+c[0]>=0 &&
            j+c[1]<L && j+c[1]>=0 &&
            M[i][j]!=M[i+c[0]][j+c[1]]
        ){
            adj.insert(M[i+c[0]][j+c[1]]);
        }
}


void fun(){
    cin>>H>>L; 
    for(int i=0;i<H;i++)for(int j=0;j<L;j++){cin>>b;M[i][j]=b;if(b>maior)maior=b;}
    adj.insert(0);
    memset(vis,0,sizeof vis);
    for(int i=0;i<H;i++)
            for(int j=0;j<L;j++)
                if(!vis[i][j] && M[i][j]==0)
                    fill_adj(i,j);
    //for(auto v:adj)printf("%d ",v);printf("\n");        
    for(auto v:adj){
        memset(vis,0,sizeof vis);
        for(int i=0;i<H;i++)
            for(int j=0;j<L;j++)
                if(!vis[i][j]){
                    //printf("%d ",dfs(i,j,v)+1);
                    int a = dfs(i,j,v)+1;
                    
                    if(a < menor_a)menor_a = a;
                }
    }
    //for(int i=0;i<H;i++){for(int j=0;j<L;j++)printf("%d ",M[i][j]);printf("\n");}printf("\n");
    cout<<menor_a<<endl;
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
