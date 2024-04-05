#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int>>
#define it vector<int>::iterator
#define s second
#define f first

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e5+10;

using namespace std;

char c;

int saque = 0;
bool terminou = 0;

int G[2] = {0,0};
int P[2] = {0,0};

void placar(){
    if(terminou)
       printf("%d%s - %d%s\n",G[0],((G[0]==2)?" (winner)":""),G[1],((G[1]==2)?" (winner)":""));
    else
       printf("%d (%d%s) - %d (%d%s)\n",G[0],P[0],((saque==0)?"*":""),G[1],P[1],((saque==1)?"*":""));

}

void fun(){
    while(cin>>c){
        switch (c)
        {
        case 'S':
            P[saque]+=1;
            break;
        case 'R':
            P[!saque]+=1;
            saque = saque?0:1;
            break;
        case 'Q':
            placar();
            break;
        default:
            break;
        }
        if((P[0]>=5&&P[0]-P[1]>=2)||P[0]==10){P[0]=0;P[1]=0;G[0]+=1;saque=0;}
        if((P[1]>=5&&P[1]-P[0]>=2)||P[1]==10){P[0]=0;P[1]=0;G[1]+=1;saque=1;}
        if(G[0]==2||G[1]==2)terminou=1;
    }
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