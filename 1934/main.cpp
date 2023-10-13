#include<bits/stdc++.h>
#define MAX 105
#define LIM 2e9
#define ll long long
using namespace std;


int L,C;
int sumL[MAX];
int sumC[MAX];
string M[MAX][MAX];
map<string,int> solve;
string var;
int num_var=0;
int var_solve=0;



void fun(){
    cin >> L >> C;
    for(int i=0;i<L;i++){
        for(int j=0;j<C;j++){
            cin >> M[i][j];
            if(solve[M[i][j]]!=LIM){
                solve[M[i][j]]=LIM;
                num_var++;
            }
        }
        cin >> sumL[i];
    }
    for(int j=0;j<C;j++)cin >> sumC[j];
    
    while(num_var>var_solve){
        for(int i=0;i<L;i++){
            var="";
            bool match = 0;
            int solve_var=sumL[i];
            int cont_var=0;
            for(int j=0;j<C;j++){
                if(var == "" && solve[M[i][j]]==LIM){var=M[i][j];match=1;}
                if(M[i][j] == var)cont_var++;
                else if(solve[M[i][j]]==LIM)match=0;
                else solve_var-=solve[M[i][j]];
            }
            if(match){solve[var]=solve_var/cont_var;var_solve++;}
        }
        for(int j=0;j<C;j++){
            var="";
            bool match = 0;
            int solve_var=sumC[j];
            int cont_var=0;
            for(int i=0;i<L;i++){
                if(var == "" && solve[M[i][j]]==LIM){var=M[i][j];match=1;}
                if(M[i][j] == var)cont_var++;
                else if(solve[M[i][j]]==LIM)match=0;
                else solve_var-=solve[M[i][j]];
            }
            if(match){solve[var]=solve_var/cont_var;var_solve++;}
        }
    }

    //for(int i=0;i<L;i++){for(int j=0;j<C;j++)cout << M[i][j] << " ";cout<<endl;}
    

    for(auto a : solve)cout<<a.first<<" "<<a.second<<endl;
    
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