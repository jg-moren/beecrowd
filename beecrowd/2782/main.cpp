#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int>>
#define it vector<int>::iterator
#define s second
#define f first

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e6+10;

using namespace std;

int N;
int cont=1;
int v[MAX];
void fun(){
    cin>>N;
    cin>>v[0];
    for(int i=1;i<N;i++){
        cin>>v[i];
        if(i-2>=0)
            if(v[i]-v[i-1]!=v[i-1]-v[i-2])cont+=1;
    }
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