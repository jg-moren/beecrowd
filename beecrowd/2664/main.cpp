#include<bits/stdc++.h>
#define ll long long int
#define MAX 100010
#define MOD 1000000007
using namespace std;

int T,M,N;
int r = 0;
int v[55][MAX];

void fun(){
    cin >> T >> M >> N;
    
    for(int j=0;j<T;j++)for(int i=M-1;i<=N+1;i++)v[j][i]=0;
    for(int i=M;i<=N;i++)v[0][i]=1;
    for(int j=1;j<T;j++)for(int i=M;i<=N;i++)v[j][i]=(v[j-1][i-1]+v[j-1][i+1])%MOD;
//    for(int j=0;j<T;j++){for(int i=M-1;i<=N+1;i++){printf("%d ",v[j][i]);}printf("\n");}
    for(int i=M;i<=N;i++)r=(r+v[T-1][i])%MOD;
    cout << r << endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    fun();
    return 0;
}