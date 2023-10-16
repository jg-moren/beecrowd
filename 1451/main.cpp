#include<bits/stdc++.h>
using namespace std;

int ini = 0;
string c;
vector<char> t;

void fun(){
    while(cin >> c){
        t.clear();
        for(char l:c){
            if(l=='[')ini++;
            else if(l==']')ini--;
            else if(ini)cout<<l;
            else t.push_back(l);
        }
        for(char l:t)cout<<l;

        cout<<endl;   
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