#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int>>
#define it vector<int>::iterator
#define s second
#define f first

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e5+10;

using namespace std;

int K;
string S;

void ord(int n){
    vector<char> sub;
    for(int i=n;i<S.size();i+=K){sub.push_back(S[i]);}
    sort(sub.begin(),sub.end());
    for(int i=n;i<S.size();i+=K){S[i]=sub[i/K];}
}

void fun(){
    cin>>S;
    cin>>K;
    for(int i=0;i<K;i++)ord(i);
    cout<<S<<endl;
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