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

ll N,K,L;

ll pos=1;

ll org(int t, int p,int g){
    if(t==0)return 1;
    if(t-10>=0){return ((org(t-10,p,g) * g) + (org(t-5 ,p,g) * p));}
    if(t-5>=0) {return (org(t-5 ,p,g) * p);}
    return 1;
}

void fun(){
    while(cin>>N>>K>>L){

        printf("%lld\n",org(N,K,L));
    };
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