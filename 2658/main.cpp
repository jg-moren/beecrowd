#include <bits/stdc++.h>
#define MAX 1000005
#define ll long long int
#define MOD 9
using namespace std;


int N,Q,a,b;
int *t[MAX*4];
int lazy[4*MAX];
int aux[MOD]; 
int count_v[MOD];

int esq(int i){return i*2;}
int dir(int i){return i*2+1;}

int *new_vector(){
    int *r = (int*)malloc(sizeof(int)*MOD);
    for(int i=0;i<MOD;i++)r[i]=0;
    return r;
}

int maior(int *a){
    int m=0;
    for(int i=0;i<MOD;i++)if(a[i]>=a[m])m=i;
    return m;
}

int *op(int *a, int *b){
    int *r = new_vector();
    for(int i=0;i<MOD;i++){
        r[i]=a[i]+b[i];
    }
    return r;
}

void buildT(int v, int tl, int tr) {
    lazy[v]=0;
    t[v]=new_vector();
    if (tl == tr){t[v][1] = 1;}
    else {
        int tm = (tl + tr) / 2;
        buildT(esq(v), tl, tm);
        buildT(dir(v), tm+1, tr);
        t[v] = op(t[esq(v)] , t[dir(v)]);
    }
}

void sum(int v,int value){
    for(int i=0;i<MOD;i++)aux[i]=t[v][i];
    for(int i=0;i<MOD;i++)t[v][(i+value)%MOD]=aux[i];
}

void update_lazy(int v,bool final){
    if(lazy[v]==0)return;
    if(!final){
        lazy[esq(v)]=(lazy[esq(v)]+lazy[v])%MOD;
        lazy[dir(v)]=(lazy[dir(v)]+lazy[v])%MOD;
    }
    sum(v,lazy[v]);
    lazy[v]=0;
}

void printV(int v, int tl, int tr) {
    update_lazy(v,tl == tr);
    if (tl == tr){cout << maior(t[v])<<endl;}
    else {
        int tm = (tl + tr) / 2;
        printV(esq(v), tl, tm);
        printV(dir(v), tm+1, tr);
    }
}

void searchT(int v, int tl, int tr) {
    update_lazy(v, tl == tr);
    if (a <= tl && tr <= b) {
        if (tl == a) for (int i = 0; i < MOD; ++i) count_v[i] = t[v][i];
        else for (int i = 0; i < MOD; ++i) count_v[i] += t[v][i];
    } else {
        int mid = (tl + tr) >> 1;
        if (mid >= a) searchT(esq(v), tl, mid);
        if (mid+1 <= b) searchT(dir(v), mid+1, tr);
    }
}       

void updateT(int v, int tl, int tr,int val) {
    update_lazy(v, tl == tr);
    if (tr < a) return;
    if (tl > b) return;
    if (a <= tl && tr <= b) {
        lazy[v] = val;
        update_lazy(v, tl == tr);
    } else {
        int mid = (tl + tr) >> 1;
        updateT(esq(v), tl, mid,val);
        updateT(dir(v), mid+1, tr,val);
        //free(t[v]);
        //t[v]=op(t[esq(v)],t[dir(v)]);
        for(int i=0;i<MOD;i++)t[v][i]=t[esq(v)][i]+t[dir(v)][i];
    }
}

void fun(){
    cin >> N >> Q;
    buildT(1,0,N-1);
    for(int i=0;i<Q;i++){
        cin>>a>>b;
        searchT(1,0,N-1);
        int r = maior(count_v);
        updateT(1,0,N-1,r);
    }
    printV(1,0,N-1);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    fun();
    return 0;
}