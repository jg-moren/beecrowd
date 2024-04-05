#include <bits/stdc++.h>
#define MAX 1000005
#define ll long long int
#define AM 3
using namespace std;


int N,M,a,b;
char c;
int v[MAX];
int *t[MAX*4];
int lazy[4*MAX];
int aux[AM]; 

int esq(int i){return i*2;}
int dir(int i){return i*2+1;}

int *new_vector(){
    int *r = (int*)malloc(sizeof(int)*AM);
    for(int i=0;i<AM;i++)r[i]=0;
    return r;
}

int *op(int *a, int *b){
    int *r = new_vector();
    for(int i=0;i<AM;i++){
        r[i]=a[i]+b[i];
    }
    return r;
}


void buildT(int v, int tl, int tr) {
    lazy[v]=0;
    free(t[v]);
    t[v]=new_vector();
    if (tl == tr){t[v][0] = 1;}
    else {
        int tm = (tl + tr) / 2;
        buildT(esq(v), tl, tm);
        buildT(dir(v), tm+1, tr);
        t[v] = op(t[esq(v)] , t[dir(v)]);

    }
}

void sum(int v,int value){
    for(int i=0;i<AM;i++)aux[i]=t[v][i];
    for(int i=0;i<AM;i++)t[v][(i+value)%AM]=aux[i];
}

void update_lazy(int v){
    if(t[esq(v)])sum(esq(v),lazy[v]);
    if(t[dir(v)])sum(dir(v),lazy[v]);
    lazy[esq(v)]+=lazy[v];
    lazy[dir(v)]+=lazy[v];
    lazy[v]=0;
}

int *searchT(int v, int tl, int tr, int l, int r) {
    update_lazy(v);
    if (l > r){return new_vector();};
    if (l == tl && r == tr)return t[v];
    int tm = (tl + tr) / 2;
    if(tm<l)return searchT(dir(v), tm+1, tr,l,r);
    if(r<=tm)return searchT(esq(v), tl, tm,l,r);
    return op(searchT(esq(v), tl, tm, l, tm), searchT(dir(v), tm+1, tr, tm+1, r));
}


void updateT(int v, int tl, int tr, int l, int r) {

    update_lazy(v);
    if (l > r)return;
    if (l == tl && r == tr){sum(v,1);lazy[v]=(lazy[v]+1)%3;}
    else {
        int tm = (tl + tr) / 2;
        updateT(esq(v), tl, tm, l, min(r, tm));
        updateT(dir(v), tm+1, tr, max(l, tm+1), r);
        free(t[v]);
        t[v]=op(t[esq(v)],t[dir(v)]);
    }
}


void printT(int v, int tl, int tr) {
    printf("%d(%d)(%d %d)[",v,lazy[v],tl+1,tr+1);
    for(int i=0;i<AM;i++)printf("%d ",t[v][i]);
    printf("]\n");
    if (tl == tr){return;}
    else {
        int tm = (tl + tr) / 2;
        printT(esq(v), tl, tm);
        printT(dir(v), tm+1, tr);

    }
}

void fun(){
    while(cin>>N && cin>>M){
        buildT(1,0,N-1);
        for(int i=0;i<M;i++){
            cin>>c>>a>>b;
            if(c=='M'){
                updateT(1,0,N-1,a-1,b-1);
            }else{
                int *r = searchT(1,0,N-1,a-1,b-1);
                for(int j=0;j<AM;j++){cout<<r[j];if(j!=AM-1)cout<<" ";}cout<<endl;
                //free(r);
            }
            //printT(1,0,N-1);
            //printf("--------------\n");
        }
        cout<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    fun();
    return 0;
}