#include<bits/stdc++.h>
using namespace std;

int N;
char c[14]={0,4,4,4,4,4,4,4,4,4,4,4,4,4};
int somaM=0;
int somaJ=0;
int b;

int val(int x){return (x<10)?x:10;}

void fun(){
    cin>>N;

    cin>>b;
    somaJ+=val(b);
    c[b]-=1;
    cin>>b;
    somaJ+=val(b);
    c[b]-=1;

    cin>>b;
    somaM+=val(b);
    c[b]-=1;

    cin>>b;
    somaM+=val(b);
    c[b]-=1;


    for(int i=0;i<N;i++){
        cin>>b; 
        somaM+=val(b);
        somaJ+=val(b);
        c[b]-=1;
    }

    int result = -1;
    if(somaJ>somaM){
        for(int i=1;i<=13;i++){
            if(c[i] && somaJ+val(i)>23 && somaM+val(i)<=23){result=i;break;}
        }
    }else{
        for(int i=1;i<=13;i++){
            if(c[i] && somaM+val(i)==23){result=i;break;}
        }
    }
    cout<<result<<endl;    
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