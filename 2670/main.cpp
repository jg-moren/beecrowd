#include <bits/stdc++.h>
using namespace std;

int v[3],s[3], r=1e9;

void fun(){
    for(int i=0;i<3;i++)cin>>v[i];
    s[0]=v[1]*2+v[2]*4;
    s[1]=v[0]*2+v[2]*2;
    s[2]=v[0]*4+v[1]*2;
    for(int i=0;i<3;i++)if(r>s[i])r=s[i];
    cout << r <<endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    fun();
    return 0;
}