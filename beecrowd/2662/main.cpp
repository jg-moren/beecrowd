#include<bits/stdc++.h>
using namespace std;

int N,b;
int escala[12] = {1,0,1,0,1,1,0,1,0,1,0,1};
string nome_notas[12] = {"do","do#","re","re#","mi","fa","fa#","sol","sol#","la","la#","si"};
int notas[12]={0,0,0,0,0,0,0,0,0,0,0,0};
int nota;

void fun(){
    cin >> N;
    for(int i=0;i<N;i++){cin>>b;notas[(b-1)%12]+=1;}
    for(nota=0;nota<12;nota++){
        int escala_correta = true;
        for(int i=0;i<12;i++){
            if(!escala[i]&&notas[(nota+i)%12])escala_correta=false;
        }
        if(escala_correta){cout<<nome_notas[nota]<<endl;return;}
    }
    cout << "desafinado" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    fun();
    return 0;
}
