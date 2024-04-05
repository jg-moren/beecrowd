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

int N,b;
ll m[MAX][2];
void fun(){
    memset(m,0,sizeof m);
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>b;
        if(b==1){
            m[i][1]=m[i-1][0];
            m[i][0]=m[i-1][1];
        }else{
            m[i][0]=m[i-1][0];
            m[i][1]=m[i-1][1];
        }
        m[i][b]+=1;
    }
    ll cont=0;
    for(int i=1;i<=N;i++)cont+=m[i][1];
    cout<<cont<<endl;
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