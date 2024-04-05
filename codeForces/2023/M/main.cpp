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

int N,K;
// peso das arestas
int w[MAX][MAX];

// distância entre qualquer par de vértices
int d[MAX][MAX];
set<int> rem;

void floyd_warshall()
{

    // inicialmente, a distância de u->v será o peso da sua aresta (se existir)
	// caso não exista, então seu valor será infinito (um valor bem grande) ou 0 se u = v.
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			d[i][j] = (w[i][j])?w[i][j]:INF;
        
	for (int k = 0; k < N; k++) // vértice intermediário
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++){
                if(d[i][j]==d[i][k] + d[j][k]&&i>j)rem.insert(i*1000+j);//cont++;//printf("%d %d[%d = %d]\n",i,j,d[i][j],k);
				d[i][j] = min(d[i][j], d[i][k] + d[j][k]); // recursão principal
    }
}

void fun(){
    cin>>N;
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)cin>>w[i][j];
    floyd_warshall();
    
    for (int i = 0; i < N; i++)
		for (int j = i+1; j < N; j++)
			if(d[i][j]<w[i][j]){cout<<-1<<endl;return;}

    cout<<rem.size()<<endl;
    // for(int i=0;i<N;i++){for(int j=0;j<N;j++)cout<<w[i][j]<<" ";cout<<endl;}
    // cout<<endl;
    // for(int i=0;i<N;i++){for(int j=0;j<N;j++)cout<<d[i][j]<<" ";cout<<endl;}
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