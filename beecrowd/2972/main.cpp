#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll N;
ll r=1;

void fun(){
    cin >> N;
    while(N){if((N)&1){r+=r<<1-1;}N=N>>1;}
    cout << r << endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    fun();
    return 0;
}