#include <bits/stdc++.h>
#define MAX 1000005
#define ll long long int
using namespace std;

string notas;
int soma;
int correta;

map<char,int> n;

void fun(){
    n['W']=64;
    n['H']=32;
    n['Q']=16;
    n['E']=8;
    n['S']=4;
    n['T']=2;
    n['X']=1;
    
    while(cin>>notas && notas!="*"){
        soma=0;
        correta=0;
        for(int i=0;i<notas.size();i++){
            if(notas[i]=='/'){
                if(soma==64)correta++;
                soma=0;
            }else{
                soma+=n[notas[i]];
            }
        }
        cout<<correta<<endl;

    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    fun();
    return 0;
}