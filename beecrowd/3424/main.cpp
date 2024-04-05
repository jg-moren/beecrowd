#include<bits/stdc++.h>
#define MAX 100005
using namespace std;

int N;
char c[MAX];
int cont;
int rep=0;

void fun(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>c[i];
        if(c[i]=='a')rep++;
        else{
            if(rep != 1)cont+=rep;
            rep=0;
        }
    }
    if(rep != 1)cont+=rep;
    cout<<cont<<endl;

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