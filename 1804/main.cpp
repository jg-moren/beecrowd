#include <bits/stdc++.h>
#define vi vector<int>
#define vii vector<vector<int>>
using namespace std;

const int MAX = 1e5+10;


int N,n;
char c;
int v[MAX];
int t[4*MAX];

int esq(int i){return i*2;}
int dir(int i){return i*2+1;}
int op(int a, int b){return a+b;}

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
    if (l > r)return 0;
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
void printT(int v, int tl, int tr) {

    if (tl == tr){printf("%d ",t[v]);}
    else {
        int tm = (tl + tr) / 2;
        printT(esq(v), tl, tm);
        printT(dir(v), tm+1, tr);

    }
}
void fun(){
    
    cin>>N;

    for(int i=0;i<N;i++)cin>>v[i];

    //for(int i=0;i<N;i++)cout<<v[i]<<" ";cout<<endl;

    buildT(v,1,0,N-1);
    //printT(1,1,N);printf("\n");

    //for(int i=1;i<20;i++)cout<<t[i]<<" ";cout<<endl;
    while(cin>>c && cin>>n){
        if(c=='a')
            updateT(1,1,N,n,0);
        else
            cout<<searchT(1,1,N,1,n-1)<<endl;
        //printT(1,1,N);printf("\n");
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