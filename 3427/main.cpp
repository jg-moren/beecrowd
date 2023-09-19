#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int N,X,Y,r;
float coo [2]={0,0};
//int dir[4][2] = {{1,-1},{1,1},{-1,1},{-1,-1}};

int bt(int x, int y,int cont){
    //printf("%d %d [%d]\n",x,y,N>>cont);
    if(x == X && y == Y){return cont;}
    if(!N>>cont)return 0;
    else{
        if(X<x)x = x-(N>>cont);
        else x = x+(N>>cont);
        if(Y<y)y = y-(N>>cont);
        else y = y+(N>>cont);
        return bt(x,y,cont+1);
    }
    return 0;
}

void fun(){
    cin >> N >> X >> Y;
    N = 1<<N;
    coo[0]=N>>1;
    coo[1]=N>>1;
    if(X>coo[0])X=coo[0]+coo[0]-X;
    if(X>coo[1])X=coo[1]+coo[1]-Y;
    r = bt(coo[0],coo[1],2);
    
    cout << r-2 << endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    fun();
    return 0;
}
