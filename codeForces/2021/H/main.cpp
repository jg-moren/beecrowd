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


int L[MAX];
int N,K;
int a,b;
void fun(){
    cin>>N>>K;
    for(int i=0;i<N;i++){
        cin>>a>>b;
        L[i]+=b;
        L[a-1]-=b;
    }

    for(int i=0;i<N;i++)if(L[i]){cout<<"N"<<endl;return;}
    cout<<"Y"<<endl;return;
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