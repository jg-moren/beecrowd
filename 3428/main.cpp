#include<bits/stdc++.h>
#define MAX 1000100
using namespace std;

int N,cont=0;
vector<vector<int>> v(MAX,{0,0,1});
int s[MAX];

int binary_search(int x,int i){
    int min=0,max=N,m;
    while(min<max){
        m = (min+max)/2;
        if(v[m][0]>x)max = m-1;
        if(v[m][0]<x)min = m+1;
        if(v[m][0]==x && v[m][1]>i && v[m][2])max = m;

        if(v[m][0]==x && v[m][1]>i && !v[m][2])min = m+1;
        if(v[m][0]==x && v[m][1]<=i)min = m+1;
    }
    if(v[min][0]==x && v[min][1]>i && v[min][2]){
        v[min][2] = 0;
        return min;
    }
    else return -1;
}

void fun(){
    cin >> N;
    for(int i=0;i<N;i++){cin>>s[i];v[i][0]=s[i];v[i][1]=i;}
    sort(v.begin(),v.begin()+N);

//    for(int i=0;i<N;i++){printf("%d[%d] ",s[i],binary_search(s[i]-1,i));}printf("\n");
//    for(int i=0;i<N;i++){printf("%d ",v[i][0]);}printf("\n");
//    for(int i=0;i<N;i++){printf("%d ",v[i][1]);}printf("\n");
//    for(int i=0;i<N;i++){printf("%d ",v[i][2]);}printf("\n");

    for(int i=0;i<N;i++){if(binary_search(s[i]-1,i)==-1)cont++;}
    
//    printf("\n%d\n",cont);
//    if(cont == 20)for(int i=1;i<=N;i++){printf("%d ",s[i]);}
    cout << cont << endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    fun();
    return 0;
}
