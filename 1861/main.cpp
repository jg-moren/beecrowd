#include<bits/stdc++.h>
using namespace std;

map<string,int[2]> murders;
string assa;
string mort;

void fun(){

    while(cin>>assa && cin >> mort){
        murders[assa][0]+=1;
        murders[mort][1]=1;
    }
    cout<<"HALL OF MURDERERS"<<endl;
    for(auto a : murders){
        if(!a.second[1])cout<<a.first<<" "<<a.second[0]<<endl;
    }

}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    fun();
    return 0;
}