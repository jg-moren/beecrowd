#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int>>
#define it vector<int>::iterator
#define s second
#define f first

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 5e4+10;

using namespace std;

int N;
int a[MAX], pe[MAX], pd[MAX];
int maior = 0;

void fun(){
    cin>>N;
    for(int i=0;i<N;i++)cin>>a[i];
    memset(pe,0,sizeof pe);
    memset(pd,0,sizeof(int) * N);
    
    pe[0]=1;
    for(int i=1;i<N;i++)pe[i]=(pe[i-1]+1 <= a[i])?pe[i-1]+1:a[i];
    
    pe[N]=1;
    for(int i=N-1;i>=0;i--)pd[i]=(pd[i+1]+1 <= a[i])?pd[i+1]+1:a[i];

    for(int i=0;i<N;i++){
        int al = min(pe[i],pd[i]);
        if(al > maior)maior = al;
    }
    //for(int i=0;i<N;i++)printf("%d ",pe[i]);printf("\n");
    //for(int i=0;i<N;i++)printf("%d ",pd[i]);printf("\n");
    cout<<maior<<endl;
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