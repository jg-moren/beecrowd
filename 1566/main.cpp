#include<bits/stdc++.h>
#define MAX 500005
#define ll long long int
#define iterator std::vector<int>::iterator 
using namespace std;

void fun(){

    int n,k,x,i;
    ll soma=0;
    vector<int> v(MAX);
    cin >> n >> k;
    v[0]=0;
    for(i=1;i<=n;i++){
        cin >> x;
        v[i] = v[i-1]+x;

    }
    for(i=0;i<=n;i++){
        x = v[i]-k;
        if(x>=0){
            iterator low = lower_bound(v.begin(),v.begin()+i,x);
            if(x == *low){
                iterator up  = upper_bound(v.begin(),v.begin()+i,x);
                soma+=up-low;
            }
        }
    }
    cout << soma <<endl;

}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    fun();
    return 0;
}
