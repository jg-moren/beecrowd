#include <bits/stdc++.h>
#define MAX 100005
#define iterator std::vector<int>::iterator 
using namespace std;

int N,K;
vector<int> v(MAX);

void fun(){
    int i;
    cin >> N;
    for(i=0;i<N;i++)cin>>v[i];
    cin>>K;
    iterator b;
    for(i=0;i<N;i++){
        b = lower_bound(v.begin()+i,v.begin()+N,K-v[i]);
        if(*b==K-v[i])break;
    }
    cout << v[i] << " " << *b << endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    fun();
    return 0;
}