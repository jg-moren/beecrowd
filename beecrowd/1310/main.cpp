#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int>>
#define it vector<int>::iterator
#define s second
#define f first

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e2+10;

using namespace std;

int N,C,b;

int v[MAX];
int nmax;

void fun(){
    while(cin>>N>>C){
        v[0]=0;
        for(int i=1;i<=N;i++){cin>>b;v[i]=v[i-1]+b-C;}

        nmax=0;
        for(int i=0;i<=N;i++)for(int j=i;j<=N;j++)if(v[j]-v[i]>nmax)nmax=v[j]-v[i];
        cout<<nmax<<endl;

        //for(int i=0;i<=N;i++)cout<<v[i]<<" ";cout<<endl;        
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