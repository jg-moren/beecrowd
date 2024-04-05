#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int>>
#define it vector<int>::iterator
#define s second
#define f first

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e1+10;

using namespace std;

int N;
int D,L,R,C;
int v[MAX][MAX];

bool verifica(int i,int j){
    if(i<1||10<i||j<1||10<j||v[i][j])return 0;
    v[i][j] =1;
    return 1;
}

void fun(){
    cin>>N;
    memset(v,0,sizeof v);
    bool s = true;
    while (N--){
        cin>>D>>L>>R>>C;
        for(int i=0;i<L;i++){
            if(D)s&=verifica(R+i,C);
            else s&=verifica(R,C+i);
        }
    }
    //for(int i=0;i<10;i++){for(int j=0;j<10;j++)printf("%d",v[i+1][j+1]);printf("\n");}
    
    cout<<(s?"Y":"N")<<endl;
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