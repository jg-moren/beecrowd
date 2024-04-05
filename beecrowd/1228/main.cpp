#include <bits/stdc++.h>
#define ll long long int
#define MAX 24
#define iterator std::vector<int>::iterator 
using namespace std;

int N;
int v[MAX][2];
int b,r;

int bubble_sort(){
    int cont=0;
    bool solve = false;
    while(!solve){
        solve = true;
        for(int i=1;i<N;i++)
            if(v[i-1][1]>v[i][1]){
                cont++;
                solve = false;
                for(int j=0;j<2;j++){
                    int aux;
                    aux = v[i-1][j];
                    v[i-1][j] = v[i][j];
                    v[i][j] = aux;
            }
        }
    }
    return cont;
}

void fun(){
    while(cin >> N){
        for(int i=0;i<N;i++){cin>>b;v[b-1][0]=i+1;}
        for(int i=0;i<N;i++){cin>>b;v[v[b-1][0]-1][1]=i+1;}
        cout<<bubble_sort()<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    fun();
    return 0;
}