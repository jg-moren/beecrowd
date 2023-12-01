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

int D,C,R;
int b;
vi c;
vi r;
int cont=0;

void fun(){
    cin>>D>>C>>R;
    while(C--){cin>>b;c.push_back(b);}
    while(R--){cin>>b;r.push_back(b);}

    while(true){
        if(c.size() && c[0]<=D){
            D-=c[0];
            c.erase(c.begin());
            cont++;
        }else{
            if(r.size()){
                D+=r[0];
                r.erase(r.begin());
                cont++;
            }
            else break;
        }
    }
    cout<<cont<<endl;
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