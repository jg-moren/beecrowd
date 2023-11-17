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

int N;
int v[MAX];
int t[3*MAX];

int esq(int i){return i*2;} 
int dir(int i){return i*2+1;}
int op(int a, int b){return a+b;}
//buildT(v,1,0,N-1);
void buildT(int *a, int v, int tl, int tr) {
	if (tl == tr)t[v] = a[tl];
	else {
    	int tm = (tl + tr) / 2;
    	buildT(a, esq(v), tl, tm);
    	buildT(a, dir(v), tm+1, tr);
    	t[v] = op(t[esq(v)] , t[dir(v)]);
	}
}
//searchT(1,1,N,1,n-1);
int searchT(int v, int tl, int tr, int l, int r) {
	if (l > r)return 0;//retornar um valor neutro na operacao
	if (l == tl && r == tr)return t[v];
	int tm = (tl + tr) / 2;
	return op(searchT(esq(v), tl, tm, l, min(r, tm)), searchT(dir(v), tm+1, tr, max(l, tm+1), r));
}
//updateT(1,1,N,n,0);
void updateT(int v, int tl, int tr, int pos, int new_val) {
	if (tl == tr) t[v] = new_val;
	else {
    	int tm = (tl + tr) / 2;
    	if (pos <= tm)updateT(esq(v), tl, tm, pos, new_val);
    	else updateT(dir(v), tm+1, tr, pos, new_val);
    	t[v] = op(t[esq(v)] , t[dir(v)]);
	}
}
//printT(1,1,N);
void printT(int v, int tl, int tr) {
	if (tl == tr){printf("%d ",t[v]);}
	else {
    	int tm = (tl + tr) / 2;
    	printT(esq(v), tl, tm);
    	printT(dir(v), tm+1, tr);

	}
}

int IP,M,PC,NA;

void fun(){
    while(cin>>IP>>M){
        memset(t,0,sizeof t);
        while (M--)
        {
            cin>>PC>>NA;
            int a = searchT(1, 1,MAX,max(1,PC-IP), min(MAX,PC+IP)); 
            if(a<=NA)updateT(1,1,MAX,PC,1);


        }
        cout<<t[1]<<endl; 
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

