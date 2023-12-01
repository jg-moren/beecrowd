#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int>>
#define it vector<int>::iterator
#define s second
#define f first

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e6+10;

using namespace std;

int N,K;
int b;
int F[MAX];

int tam(int num){
    int cont=0;
    while (num)
    {
        cont += num%10;
        num/=10;
    }
    return cont;
}

void fun(){
    memset(F,0,sizeof F);
    cin>>N>>K;
    for(int i=0;i<N;i++){cin>>b;F[b]+=1;}
    for(int i=MAX-1;i>=0;i--){
        if(F[i]){
            K-=F[i];
            if(K<=0){cout<<tam(i)<<endl;return;}
            F[max(i-tam(i),0)]+=F[i];
        }
    }
    cout<<0<<endl;
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