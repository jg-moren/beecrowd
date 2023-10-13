#include <bits/stdc++.h>
#define MAX 1000005
#define ll long long int
#define iterator std::vector<ll>::iterator 
using namespace std;

int N,C,P;
int lucro=0;
int sum;
int maior;
int v[MAX];

void fun(){
    cin >> N >> C;
    for(int i=0;i<N;i++)cin>>v[i];
    for(int i=0;i<N-1;i++)v[i]=v[i+1]-v[i];
    //for(int i=0;i<N-1;i++)printf("%d ",v[i]);printf("\n");    
    //for(int i=1;i<N-1;i++)v[i]=v[i]+v[i-1];
    sum =-C;
    maior=0;
    for(int i=0;i<N-1;i++){
        
        if(sum+v[i]<=maior-C){lucro+=maior;sum=-C;maior=0;}
        else sum+=v[i];
        if(sum > maior)maior = sum;
        
    //    printf("%d ",maior);
    };
    lucro+=maior;
    //printf("\n");
    //for(int i=0;i<N-1;i++)printf("%d ",v[i]);printf("\n");    
    cout<<lucro<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    fun();
    return 0;
}