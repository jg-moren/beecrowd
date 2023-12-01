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

int N, K;
vi fila(MAX,0);
vi dist(MAX,0);

void fun(){
    while(cin>>N>>K){
        for(int i=1;i<N;i++)cin>>fila[i];
        for(int i=1;i<N;i++)dist[i]=fila[i]-fila[i-1];
        sort(begin(dist),begin(dist)+N);
        int cont=0;
        for(int i=0;i<N-(K-1);i++)cont+=dist[i];
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