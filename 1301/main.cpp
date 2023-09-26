#include <bits/stdc++.h>
#define MAX 1000005
#define ll long long int
using namespace std;

int N,K,a,b;
char c;
int v[MAX];
int n, t[4*MAX];

int esq(int i){return i*2;}
int dir(int i){return i*2+1;}
int op(int a, int b){return a*b;}

void buildT(int *a, int v, int tl, int tr) {
    if (tl == tr)t[v] = a[tl];
    else {
        int tm = (tl + tr) / 2;
        buildT(a, esq(v), tl, tm);
        buildT(a, dir(v), tm+1, tr);
        t[v] = op(t[esq(v)] , t[dir(v)]);
    }
}

int searchT(int v, int tl, int tr, int l, int r) {
    if (l > r)return 1;
    if (l == tl && r == tr)return t[v];
    int tm = (tl + tr) / 2;
    return op(searchT(esq(v), tl, tm, l, min(r, tm)), searchT(dir(v), tm+1, tr, max(l, tm+1), r));
}

void updateT(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) t[v] = new_val;
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)updateT(esq(v), tl, tm, pos, new_val);
        else updateT(dir(v), tm+1, tr, pos, new_val);
        t[v] = op(t[esq(v)] , t[dir(v)]);
    }
}

void fun(){
    while(cin>>N && cin>>K){
        for(int i=0;i<N;i++){
            cin>>b;
            if(b>0)b=1;
            if(b<0)b=-1;
            v[i]=b;
        };
        buildT(v,1,0,N-1);
        //print_st(0,N-1,1);
        for(int i=0;i<K;i++){
            cin>>c;cin>>a;cin>>b;
            if(c=='C'){
                if(b>0)b=1;
                if(b<0)b=-1;
                updateT(1,0,N-1,a-1,b);
            }else{
                int r = searchT(1,0,N-1,a-1,b-1);
                char resp;
                if(r>0)resp = '+';
                else if(r<0)resp = '-';
                else resp = '0';
                cout<<resp;
            }
            //print_st(0,N-1,1);
            //printf("\n\n");
        }
        //print_st(0,N-1,1);
        //printf("\n\n\n");
        cout<<endl;
    }

}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    fun();
    return 0;
}