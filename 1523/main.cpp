#include <bits/stdc++.h>
#define MAX 1000005
using namespace std;

int N,K,a,b;
vector<vector<int>> v(MAX,{0,0});
vector<int> est;


void fun(){
    while(cin >> N >> K && N != 0 && K != 0){
        bool possivel = true;
        est.clear();
        for(int i=0;i<N;i++)cin >> v[i][0] >> v[i][1];
        //sort(v.begin(),v.begin()+N);
        //for(int i=0;i<N;i++)printf("[%d %d]\n",v[i][0],v[i][1]);
        est.insert(est.begin(),v[0][1]);
        for(int i=1;i<N;i++){
            //printf("-%d ",*est.end());
            while(est.size() && est[0]<=v[i][0])est.erase(est.begin());
            est.insert(est.begin(),v[i][1]);
            if(est.size()>K){possivel = false;break;}
            for(int i=1;i<est.size();i++)if(est[i-1]>est[i]){possivel = false;break;}

            //for(int i=0;i<est.size();i++)printf("%d ",est[i]);printf("\n");
        }

        cout << ((possivel)?"Sim":"Nao") << endl;

        //printf("\n\n");
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    fun();
    return 0;
}