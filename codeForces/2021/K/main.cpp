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


int T,D,M;
int y=0;
int ini=0;
bool res=0;
void fun(){
    cin>>T>>D>>M;
    while(M--){
        cin>>y;
        if(y-ini>=T)res=1;
        ini=y;
    }
    if(D-ini>=T)res=1;
    
    cout<<(res?'Y':'N')<<endl;
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