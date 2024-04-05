#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;
const int MAX = 1e6+10;

vi ind;
int ind_size=0;
string s;
int N;


bool eh_divisivel(){
    int resto = 0;
    for(char c : s){
        resto = (resto*10 + (c-'0'))%N;
    }
    return (resto == 0);
}

void updateS(int i){
    if(i<0)return;
    if(s[ind[i]]=='9'){s[ind[i]]=(ind[i])?'0':'1';updateS(i-1);}
    else s[ind[i]]+=1;
}

void fun(){
    cin>>s>>N;
    for(int i=0;i<s.size();i++){
        if(s[i]=='?'){ind.push_back(i);ind_size+=1;s[i]=(i==0)?'1':'0';}
    }
    int i;
    for(i=0;i<MAX;i++){
        if(!eh_divisivel())updateS(ind.size()-1);
        else break;
    }
    cout<<i<<endl;
    cout<<s<<endl;
    cout<<(eh_divisivel()?s:"*")<<endl;
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