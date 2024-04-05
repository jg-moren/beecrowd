#include<bits/stdc++.h>
#define MAX 100005
#define ll long long int
#define interator std::vector<int>::iterator 
using namespace std;

int n,c,t,p;
int v[MAX];

int possivel(ll chute){
    ll total=0;
    int cont_c = 1;
    ll t_chute = chute*t;
    for(int i=0;i<n;i++){
        if(v[i]>t_chute)return 0;
        if(total+v[i]>t_chute){cont_c++;total=v[i];}
        else {total+=v[i];}
        if(cont_c > c)return 0;
    }
    return 1;
}

void fun(){
    cin >> n >> c >> t;
    ll min=0,max=0,m;

    for(int i=0;i<n;i++){cin >> p;v[i]=p;max+=p;};
    while(min<max){

        m = (min+max)/2;
        if(!possivel(m))min=m+1;
        else max = m;

    }
    
    cout << min << endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    fun();
    return 0;
}