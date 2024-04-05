#include <bits/stdc++.h>
#define vc vector<char>
#define it vector<char>::iterator
#define s second
#define f first

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e5+10;

using namespace std;

string line;
vc text;
int i;

void fun(){
    while(cin>>line){
        i = 0;
        for(char c:line){
            if(c == '[')i=text.size();
            else if(c == ']')i=0;
            else text.insert(text.begin()+i,c);
        }
        for(int j=text.size()-1;j>=0;j--)cout<<text[j];cout<<endl;
        text.clear();
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