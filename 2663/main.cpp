#include <bits/stdc++.h>
#define MAX 1005
#define iterator std::vector<int>::iterator 
using namespace std;

int N,K;
vector<int> v(MAX);

void fun(){
    cin >> N;
    cin >> K;
    for(int i=0;i<N;i++)cin>>v[i];
    sort(v.begin(),v.begin()+N);
    iterator b = lower_bound(v.begin(),v.begin()+N,v[N-K]);
    cout << ( N - int(b - v.begin())) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    fun();
    return 0;
}