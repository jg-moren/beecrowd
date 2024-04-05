#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int>>
#define it vector<int>::iterator
#define s second
#define f first

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 45;

using namespace std;

int L,C,N;

char M[MAX][MAX];
string s;


bool horizontal(string p, int l, int c){
    map<char,int> m;
    for(int i=0;i<p.length();i++)m[p[i]]++;
    for(int t=0;t<s.size();t++){
        if(l+t>=L)break;
        if(m[M[l+t][c]])m[M[l+t][c]]-=1;
    }
    for(auto i:m)if(i.s!=0)return false;
    return true;
}

bool vertical(string p, int l, int c){

    map<char,int> m;
    for(int i=0;i<p.length();i++)m[p[i]]++;
    for(int t=0;t<s.size();t++){
        if(c+t>=C)break;
        if(m[M[l][c+t]])m[M[l][c+t]]-=1;
    }
    for(auto i:m)if(i.s!=0)return false;
    return true;
}
bool diagonal(string p, int l, int c){
    map<char,int> m;
    for(int i=0;i<p.length();i++)m[p[i]]++;   
    for(int t=0;t<s.size();t++){
        if(l+t>=L||c+t>=C)break;
        if(m[M[l+t][c+t]])m[M[l+t][c+t]]-=1;
    }
    for(auto i:m)if(i.s!=0)return false;
    return true;
}
void fun(){
    cin >> L >> C;
    for(int i=0;i<L;i++)for(int j=0;j<C;j++)cin>>M[i][j];
    cin>>N;
    while(N--){
        cin>>s;
        cout<<s<<endl;
        for(int l=0;l<L;l++)
        for(int c=0;c<C;c++){
            horizontal(s,l,c);
            vertical(s,l,c);
            diagonal(s,l,c);
        }

           
    }

    for(int i=0;i<L;i++){for(int j=0;j<C;j++)cout<<M[i][j]<<" ";cout<<endl;}
        


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