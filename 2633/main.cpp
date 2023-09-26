#include<bits/stdc++.h>
#define MAX 100
using namespace std;

int N,b;
vector<vector<int>> v(MAX,{0,0});
vector<string> s(MAX);
void fun(){
    while(cin >> N){
        for(int i=0;i<N;i++){cin>>s[i];cin >> b;v[i][0]=b;v[i][1]=i;}
        sort(v.begin(),v.begin()+N);
        for(int i=0;i<N;i++){cout<<s[v[i][1]];if(i!=N-1)cout<<" ";}cout<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    fun();
    return 0;
}
