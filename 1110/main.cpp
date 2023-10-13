#include<bits/stdc++.h>
using namespace std;


int c;

void fun(){

	while (cin>>c && c != 0)
	{

        vector<int> pilha;
		for (int i = 0; i < c; i++)pilha.insert(pilha.begin(),c - i);
		int tam = size(pilha);
		cout<<"Discarded cards: ";
		while (tam > 1)
		{
			cout << pilha[0];
			pilha.erase(pilha.begin());
			pilha.insert(pilha.end(),pilha[0]);
			pilha.erase(pilha.begin());
			tam = size(pilha);
			if (tam > 1)cout<<", ";
			
		}
		cout<<endl;
		cout<<"Remaining card: "<< pilha[0]<<endl;
	}
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    fun();
    return 0;
}
