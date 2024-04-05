#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define it vector<int>::iterator
#define s second
#define f first

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e5+10;

using namespace std;

//MAX
struct FenwickTree{
    vector<pii> bit;
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, {0,0});
    }

    pii getmax(int r) {
        pii ret = {0,0};
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret = max(ret, bit[r]);
        return ret;
    }

    void update(int idx, pii val) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] = max(bit[idx], val);
    }
};

FenwickTree cam = FenwickTree(1e9+10);
int N,b;
vvi v(MAX);
int f[MAX];
int vis[MAX];
int res[MAX];


void dfs(int i){
    vis[i]=1;

    pii m = cam.getmax(f[i]-1);

    res[i]=1;

    cam.update(f[i],{f[i],i});
    printf("i=%d m.f=%d m.s=%d f[i]=%d %d\n",i,m.f,m.s,f[i],res[i]); 
    
    for(auto c:v[i])if(!vis[c]){

        dfs(c);

    }

    cam.update(f[i],{0,0});
}

void fun(){
    cin>>N;
    memset(vis,0,sizeof vis);
    memset(res,0,sizeof res);
    for(int i=2;i<=N;i++){
        cin>>b;
        v[i].push_back(b);
        v[b].push_back(i);
    }
    for(int i=1;i<=N;i++)cin>>f[i];

    for(int i=1;i<=N;i++)cout<<res[i]<<" ";cout<<endl;
    dfs(1);

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