#include <bits/stdc++.h>
using namespace std;

string s;
char vogal[55];
int t=0;

void fun(){
    cin>>s;
    for(int i=0;i<s.size();i++)
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
            vogal[t]=s[i];
            t++;
        }
    bool f = true;
    for(int i=0;i<t/2;i++)if(vogal[i]!=vogal[t-i-1])f=false;
    cout << ((f)?"S":"N") << endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    fun();
    return 0;
}