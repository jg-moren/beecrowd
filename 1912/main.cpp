#include <bits/stdc++.h>
#define MAX 1000005
#define ll long long int
#define iterator std::vector<ll>::iterator 
using namespace std;

ll N,A;
vector<ll> v(MAX);


ll possivel(ll chute){
    ll total = 0;
    for(int i=0;i<N;i++){
        int corte = v[i]-chute;
        if(corte>0)total+=corte;
        if(total>A)return total;
    }
    return total;

}

void fun(){
    while (cin >> N >> A && N!=0 && A!=0){
        A*=1e4;
        ll maior=0;
        ll total_soma=0;
        int b;
        for(int i=0;i<N;i++){
            cin>>b;
            v[i]=b*1e4;
            if(v[i]>maior)maior=v[i];
            total_soma += v[i];    
        }
        ll min=0,max=maior,m;
        if(total_soma<A)printf("-.-\n");
        else if(total_soma==A)printf(":D\n");
        else {
            while(min<max){
                    
                m = (min+max)/2;
                if(possivel(m)>A)min=m+1;
                else max = m;

            }
            if(possivel(min)+possivel(min-1)-A-A<0)min--;

            printf("%.4f\n",min/1e4);
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    fun();
    return 0;
}