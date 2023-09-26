#include<bits/stdc++.h>
#define MAX 1000100
using namespace std;

int N,C;
vector<string> palavras(MAX);
vector<int> cont(MAX);
vector<int> lex(MAX);


void fun(){
    cin >> N >> C;
    for(int i=0;i<N;i++){cin>>palavras[i];cont[i]=0;}
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int match = true;
            for(int c=0;c<C;c++){
                lex[i]+=palavras[i][c];
                if(
                    palavras[i][c]!='*' &&
                    palavras[j][c]!='*' &&
                    palavras[i][c]!=palavras[j][c])match=false;
            }
            if(match)cont[i]++;
        }
    }
    int maior=0;
    for(int i=0;i<N;i++){
        if(cont[i]>cont[maior]||cont[i]==cont[maior] && lex[i]<lex[maior])maior=i;
    }

    
    cout << palavras[maior] << " " << cont[maior] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    fun();
    return 0;
}
