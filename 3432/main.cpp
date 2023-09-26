#include<bits/stdc++.h>
using namespace std;

int N;

void fun(){
    while(cin>>N){
        if(N!=1&&N!=0){cout<<"F"<<endl;return;}
    }
    cout<<"S"<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    fun();
    return 0;
}