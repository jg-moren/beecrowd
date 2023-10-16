#include<bits/stdc++.h>
#define MAX 1005
#define ll long long
using namespace std;


int b;
int N;
vector<int> v;
vector<int> est;

void fun(){
    while(cin >> N && N){
        while(cin>>b && b){
            int vagao = N;
            v.clear();
            est.clear();
            v.insert(v.begin(),b);
            for(int i=1;i<N;i++){cin>>b;v.insert(v.begin(),b);};

            while(true){
                if(est.size() && *est.begin()==vagao){
                    est.erase(est.begin());
                    vagao--;
                }else if(v.size() && *v.begin()==vagao){
                    v.erase(v.begin());
                    vagao--;
                }else{
                    if(v.size()){
                        est.insert(est.begin(),*v.begin());
                        v.erase(v.begin());
                    }else{
                        break;
                    }
                }
            }
            cout<<(vagao?"No":"Yes")<<endl;

        }
        cout<<endl;
    }
    
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