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

int g[MAX];
bool vis[MAX];
vi cam;

int N,K,b;

int dfs(int i){
    if(vis[i])return 0;
    vis[i]=true;
    if(i==1)return 1;
    return dfs(g[i])+1;
}

void fun(){
    memset(vis,false,sizeof vis);
    cin>>N>>K;
    for(int i=2;i<=N;i++)cin>>g[i];
    for(int i=N;i>1;i--)cam.push_back(dfs(i));
    sort(cam.begin(),cam.end());

    int sum=0;
    for(int i=N-2;i>N-K-2;i--)sum+=cam[i];
    cout<<sum<<endl;
}

//nao resolvido
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    clock_t begin = clock();
    fun();
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    //printf("time: %f\n",elapsed_secs);
    return 0;
}