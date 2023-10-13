#include<bits/stdc++.h>
#define MAX 100005
#define ll long long
using namespace std;

int N,K,L;
vector<int[2]> C(MAX);
ll comb=0;
set<pair<int,int>> combK;
set<pair<int,int>> combL;
ll sumComb=0;
ll maior = 0;

void insert(int i){
    if(combL.size()<L){
        combL.insert({C[i][1],i});
        sumComb += C[i][1];
        return;
    }else{
        if(C[i][1]>combL.begin()->first){
            sumComb+=C[i][1]-combL.begin()->first;
                
            combK.insert(*combL.begin());
            combL.erase(*combL.begin());
            combL.insert({C[i][1],i});
        }else{
            combK.insert({C[i][1],i});
        }
    }
}

void erase(int i){
    if(combL.erase({C[i][1],i})){
        sumComb+=combK.rbegin()->first-C[i][1];
        combL.insert(*combK.rbegin());
        combK.erase(*combK.rbegin());
    }else{
        combK.erase({C[i][1],i});
    }
}


void fun(){
    cin>>N;
    for(int i=0;i<N;i++)cin>>C[i][0];
    for(int i=0;i<N;i++)cin>>C[i][1];
    cin >> K >> L;

    for (int i=0; i<K;i++){comb+=C[i][0];insert(i);}
    maior = sumComb+comb;
    for (int i=0; i<K;i++){
        comb-=C[K-i-1][0];
        erase(K-i-1);
        comb+=C[N-i-1][0];
        insert(N-i-1);
        


        if(sumComb+comb > maior)maior=sumComb+comb;
    }
    cout<<maior<<endl;
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