#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define it vector<int>::iterator
#define s second
#define f first

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e5+10;

using namespace std;

int v[MAX];
pair<int,int> t[3*MAX];


int esq(int i){return i*2;}
int dir(int i){return i*2+1;}
pii op(pii a,pii b){return make_pair(max(a.f , b.f),min(a.s , b.s));}

//buildT(v,1,0,N-1);
void buildT(int i, int tl, int tr) {
	if (tl == tr)t[i] = make_pair(v[tl],v[tl]);
	else {
    	int tm = (tl + tr) / 2;
    	buildT(esq(i), tl, tm);
    	buildT(dir(i), tm+1, tr);
    	t[i] = op(t[esq(i)] , t[dir(i)]);
	}
}

//searchT(1,1,N,1,n-1);
pair<int,int> searchT(int i, int tl, int tr, int l, int r) {
	if (l > r)return make_pair(0,INF);//retornar um valor neutro na operacao
	if (l == tl && r == tr)return t[i];
	int tm = (tl + tr) / 2;
	return op(searchT(esq(i), tl, tm, l, min(r, tm)), searchT(dir(i), tm+1, tr, max(l, tm+1), r));
}


//updateT(1,1,N,n,0);
void updateT(int i, int tl, int tr, int pos, int new_val) {
	if (tl == tr) t[i] = make_pair(new_val,new_val);
	else {
    	int tm = (tl + tr) / 2;
    	if (pos <= tm)updateT(esq(i), tl, tm, pos, new_val);
    	else updateT(dir(i), tm+1, tr, pos, new_val);
    	t[i] = op(t[esq(i)] , t[dir(i)]);
	}
}

int N,Q;
int a,b,c;

void fun(){
   	while(scanf("%d",&N)==1){
		for(int i=0;i<N;i++)scanf("%d",&v[i]);
		buildT(1,0,N-1);
		scanf("%d",&Q);
		while(Q--){
			scanf("%d %d %d",&a,&b,&c);
			if(a==1){
				updateT(1,1,N,b,c);
			}else{
				pii val = searchT(1,1,N,b,c);
				printf("%d\n",val.f-val.s);
			}

		}
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