#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll result;
ll fat[25];

int a,b;


void fun(){
    
    fat[0]=1;
    for(int i=1;i<25;i++)fat[i]=fat[i-1]*i;

    while(cin>>a>>b){
        cout<<fat[a]+fat[b]<<endl;
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