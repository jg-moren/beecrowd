#include<bits/stdc++.h>
#define ll long long int
#define MAX 100010
using namespace std;

int N,Q,a,b;
int teclas[MAX];
int press[MAX];
int v[MAX][2];
int sum=0;

void fun(){
    cin >> N >> Q;
    for(int i=0;i<N;i++)teclas[i]=1;
    for(int i=0;i<N;i++)press[i]=0;
    
    

    for(int i=0;i<Q;i++)cin >> v[i][0] >> v[i][1];

    sum=2;
    press[v[0][0]]+=1;
    press[v[0][1]+1]-=1;
    
    for(int i=1;i<Q;i++){
        if(v[i][1]>v[i-1][0]||v[i-1][1]>v[i][0]){

            sum =1;
            press[v[i][0]]+=sum;
            press[v[i][1]+1]-=sum;
        }else{

            sum =1;
            press[v[i][0]]+=sum;
            press[v[i][1]+1]-=sum;
        }
        for(int i=0;i<N;i++)printf("%d ",press[i]);printf("\n");

    };

    sum=0;
    for(int i=0;i<N;i++){
        sum+=press[i];
        teclas[i]+=sum;
    }    

    for(int i=0;i<N;i++)printf("%d ",press[i]);printf("\n");
    

    for(int i=0;i<N;i++)cout << teclas[i] << " ";cout<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    fun();
    return 0;
}
