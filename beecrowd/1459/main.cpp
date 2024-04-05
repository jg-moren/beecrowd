#include <bits/stdc++.h>
#define vi2 vector<vector<int>>
#define s second
#define f first

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e6+10;

using namespace std;

int N;
vi2 v(MAX,vector<int>(2,0));
int a,b;
int cont;

void fun(){

    while(cin>>N){      
        for(int i=0;i<N;i++)cin>>v[i][0]>>v[i][1];
        sort(v.begin(),v.begin()+N);

        cont=1;
        int fim = v[0][1];
        for(int i=1;i<N;i++){
            if(v[i][0]<=fim){
                if(v[i][1]<fim)fim=v[i][1];
            }else{
                fim = v[i][1];
                cont++;
            }
        }
        //for(int i=0;i<N;i++)printf("(%d %d)\n",v[i][0],v[i][1]);

        
        cout<<cont<<endl;
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