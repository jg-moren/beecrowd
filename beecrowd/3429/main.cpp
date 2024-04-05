#include<bits/stdc++.h>
#define P 'z'+1
using namespace std;

int N,C;
map<string,int>p;
string s;

void fun(){
    cin >> N >> C;
    while(N--){
        cin >> s;
        int a;
        for(int i=0;i<C;i++)if(s[i]=='*')a=i;
        for(int c='a';c<='z';c++){s[a]=c;p[s]+=1;}
    }
    string rs;
    int rr;
    for(auto e : p){
        if(rs==""){rs = e.first;rr=e.second;}
        if(e.second > rr){rs = e.first;rr=e.second;}
    }
    cout << rs << " " << rr << endl;

}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    fun();
    return 0;
}