#include <bits/stdc++.h>
#define MAX 1005
#define iterator std::vector<int>::iterator 
using namespace std;

int result=0;
char c;

void fun(){
    while(cin>>c)result=(result+(c-'0'))%3;
    cout << result << endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    fun();
    return 0;
}