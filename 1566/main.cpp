#include <bits/stdc++.h>
#define MAX 3000010
#define ll long long int
using namespace std;

int NC,N;
vector<int> v(MAX,0);

void fun(){
    cin >> NC;
    while(NC){

        cin >> N;

        for(int i=0;i<N;i++)cin>>v[i];

        sort(v.begin(),v.begin()+N);

        for(int i=0;i<N;i++){cout<<v[i];if(i!=N-1)cout<<" ";}cout<<endl;

        NC--;
    }
}



int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    fun();
    return 0;
}