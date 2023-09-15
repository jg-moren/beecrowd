#include <bits/stdc++.h>
#define ll long long int
#define iterator std::vector<int>::iterator 
using namespace std;


ll N,B;
ll pos=1;
ll min_l;
ll max_l;
ll coo[2]={1,1};

int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

ll f(int x){return 1+(4*(x-1)*(N-1-(x-2)));}

ll lm(){return (N/2)+1;}

ll binary_search(ll ini, ll fim, ll x){
    ll min=ini,max=fim,m;
    while(min<max){
        m=(min+max)/2;
        if(f(m)<=x)min = m+1;
        else max = m ;
    }
    return min-1;
}

void fun(){
    int i;
    cin >> N >> B;
    if( (N%2) &&  B == N*N ){cout << lm() <<" "<< lm()<<endl;return;}
    min_l = N;

    ll l = binary_search(1,lm(),B);
    coo[0]=l;
    coo[1]=l;
    min_l -=(l-1)*2;
    pos = f(l);

    for(i=0;i<4;i++){
        if(pos+(min_l-1)>B)break;
        pos += min_l-1;
        coo[0]+=dir[i][0]*(min_l-1);
        coo[1]+=dir[i][1]*(min_l-1);
    }
    coo[0]+=dir[i][0]*(B-pos);
    coo[1]+=dir[i][1]*(B-pos);
    cout<< coo[1] << " " << coo[0] <<endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    fun();
    return 0;
}