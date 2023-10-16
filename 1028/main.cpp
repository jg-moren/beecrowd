#include<bits/stdc++.h>
using namespace std;

int N;
int a,b;

int mdc(int a,int b){
    if(a==0)return b;
    if(b==0)return a;
    return mdc(b,a%b);
}

void fun(){
    cin >> N;
    while(N--){
        cin>>a>>b;
        cout<<mdc(max(a,b),min(a,b))<<endl;
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