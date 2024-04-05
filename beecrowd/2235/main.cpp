#include <bits/stdc++.h>
using namespace std;

int v[9];

void fun(){
    for(int i=0;i<3;i++){cin>>v[i];}
    for(int i=0;i<3;i++){v[3+i]=v[i]+v[(i+1)%3];v[6+i]=abs(v[i]-v[(i+1)%3]);}
    for(int i=0;i<3;i++)for(int j=i+1;j<9;j++)if(v[i]==v[j]){cout<<"S"<<endl;return;}
    cout<<"N"<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    fun();
    return 0;
}