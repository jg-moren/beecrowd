#include<bits/stdc++.h>
#define N 100005
using namespace std;

string expr;
int cont;

void fun(){

    while(cin>>expr){
        cont=0;
        for(int i=0;i<expr.size();i++){
            if(expr[i]=='(')cont+=1;
            if(expr[i]==')')cont-=1;
            if(cont<0)break;
        }
        cout<<((!cont)?"correct":"incorrect")<<endl;
    }    
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    fun();
    return 0;
}