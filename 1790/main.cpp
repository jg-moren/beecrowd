#include<bits/stdc++.h>
#define MAX 500005
#define ll long long int
#define interator std::vector<int>::iterator 
using namespace std;

vector<vector<int>> g(MAX);
int vis[MAX];

void fun(){
    int C,P,X,Y;
    cin>>C>>P;
    while(P--){
        cin>>X>>Y;
        g[X].push_back(Y);
        g[Y].push_back(X);
        
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    fun();
    return 0;
}