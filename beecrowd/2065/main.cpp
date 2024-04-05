#include<bits/stdc++.h>
#define MAX 10005
#define ll long long
using namespace std;

int N,M;
int v[MAX];
int c;
int t[MAX];

void fun(){
    cin >> N >> M;
    for(int i=0;i<N;i++)cin>>v[i];
    for(int i=0;i<N;i++)t[i]=0;


    for(int i=0;i<M;i++){
        cin>>c;
        int menor=0;
        for(int j=1;j<N;j++)if(t[menor]>t[j])menor=j;
        t[menor]+=v[menor]*c;
    }

    int maior=0;
    for(int i=1;i<N;i++)if(t[maior]<t[i])maior=i;
    cout<<t[maior]<<endl;

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