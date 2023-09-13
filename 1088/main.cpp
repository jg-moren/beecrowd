#include<bits/stdc++.h>
#define N 100005
using namespace std;


void fun(){
    int n,soma,i,b,aux;
    int v[N][2]={{0,0}};
    while(cin >> n && n){   
        for(i=1;i<=n;i++){
            cin >> b;
            v[i][0]=b;
            v[b][1]=i;           
        }      
        soma=0;   
        for(i=1;i<=n;i++){
            if(v[i][0]!=i){
                soma = (soma%2+((v[i][0]-i)*2-1)%2)%2;
                v[v[i][0]][1] = v[i][1];
                aux = v[i][0];
                v[i][0]=v[v[i][1]][0];
                v[v[i][1]][0] = aux;
            }
        };
        cout << ((soma%2)?"Marcelo":"Carlos")<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    fun();
    return 0;
}