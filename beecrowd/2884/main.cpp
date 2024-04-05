#include <bits/stdc++.h>
#define vi vector<int>
#define vii vector<vector<int>>
#define it vector<int>::iterator
#define s second
#define f first

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e3+10;

using namespace std;

int N,M,a,b;
bool lamps[MAX];
bool ini[MAX];
vii inter(MAX);


bool compare(bool *a,bool *b){
    for(int i=0;i<M;i++)if(a[i]!=b[i])return 0;
    return 1;
}

bool is_false(bool *a){
    for(int i=0;i<N;i++)if(a[i])return 0;
    return 1;
}

void fun(){
    memset(lamps,0,sizeof lamps);
    memset(ini,0,sizeof ini);
    cin>>N>>M;
    cin>>a;while(a--){cin>>b;lamps[b-1]=1;ini[b-1]=1;}
    for(int i=0;i<N;i++){cin>>a;while(a--){cin>>b;inter[i].push_back(b-1);}}

    int cont=0;
    int i = 0;
    do{
        for(int j=0;j<inter[i].size();j++)lamps[inter[i][j]]=lamps[inter[i][j]]?false:true;
        i = (i+1)%N;
        cont++;
    }while(!(i==0 && compare(lamps,ini)) && !is_false(lamps));
    

    if(is_false(lamps))
        cout<<cont<<endl;
    else
        cout<<"-1"<<endl;

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