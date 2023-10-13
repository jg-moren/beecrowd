#include <bits/stdc++.h>
using namespace std;
#define FAT 11

int N;
int soma=0;
int fat[FAT];

void fun(){
    fat[0]=1;
    for(int i=1;i<FAT;i++)fat[i]=fat[i-1]*i;
    cin >> N;
    for(int i=FAT-1;i>=0;i--){soma+=N/fat[i];N%=fat[i];}
    cout << soma << endl;
    
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    fun();
    return 0;
}