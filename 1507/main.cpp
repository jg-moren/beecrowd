#include <bits/stdc++.h>
#define ll long long int
#define iterator std::vector<int>::iterator 
#define MAX 100005
#define L 'z'+1
using namespace std;


int N,Q;

int v[L][MAX];
int tam[L];

string s;
string subs;

int binary_search(int x,int c){
    int min=0,max=tam[c],m;
    //if(x==0&&tam[c]>0)return v[c][0]; 
    while(min<max){
        m=(min+max)/2;
        if(v[c][m]<=x)min=m+1;
        else max=m;
    }
    if(v[c][min]>x)return v[c][min];
    else return -1;
    
}

void fun(){
    cin >> N;
    while(N){
        for(int i=0;i<L;i++)tam[i]=0;
        cin >> s;
        for(int i=0;i<s.size();i++){v[s[i]][tam[s[i]]]=i;tam[s[i]]++;}
/*
        for(int i=0;i<L;i++){
            printf("%c[%d] ",i,tam[i]);
            for(int j=0;j<tam[i];j++){
                printf("%d ",v[i][j]);
            }
            printf("\n");
        }
*/

        cin >> Q;
        for(int i=0;i<Q;i++){
            cin>>subs;
            bool e_sub = true;
            int ic=-1;
            for(int j=0;j<subs.size();j++){
                ic = binary_search(ic,subs[j]);
                //printf("%c[%d] ",s[ic],ic);
                if(ic==-1){e_sub=false;break;}
            }
            printf((e_sub)?"Yes\n":"No\n");

        }


        N--;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    fun();
    return 0;
}