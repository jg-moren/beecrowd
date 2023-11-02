#include <bits/stdc++.h>
#define vi vector<int>
#define vii vector<vector<int>>
using namespace std;

const int MAXV = 1e5+10;
const int MAXM = 1e3+10;


bool M[MAXV];

int b;
int v,m;


void fun(){
    cin>>v>>m;
    memset(M,false,sizeof(M));
    M[0]=true;
    for(int i=0;i<m;i++){
        cin>>b;
        for(int j=MAXV-b;j>=0;j--)
            if(M[j])M[j+b]=true;
        //for(int j=0;j<MAXV;j++)cout<<M[j];cout<<endl;

    }
    cout<<((M[v])?"S":"N")<<endl;
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