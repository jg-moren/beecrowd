#include<bits/stdc++.h>
using namespace std;

int EV1,EV2,D;
float AT;



void fun(){
    while(cin>>EV1>>EV2>>AT>>D && EV1){
        double p1 = AT/6;
        double p2 = (6-AT)/6;
        double qnt1 = EV1/D+(EV1%D!=0);
        double qnt2 = EV2/D+(EV2%D!=0);


        double p;
        if(p1!=p2)p = (1-pow(p2/p1,qnt1))/(1-pow(p2/p1,qnt1+qnt2));
        else p = (qnt1/(qnt1+qnt2));
        printf("%.1f\n",p*100);


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