#include <iostream>
#include <stdio.h>
using namespace std;
long long n, k, a, b;
int main(){
//    freopen("D.INP", "r", stdin);
    cin>>n>>k>>a>>b;
    if((k*(a+1)<b)||(k*(b+1)<a)){
        cout<<"NO";
        return 0;
    }
    else{
        string res="";
        if(a==b){
            for(long long i=1; i<=a; i++)
                cout<<"GB";
            return 0;
        }
        if(a>b){
            long long x=a/(b+1);//Tm
            long long temp=x*(b+1);//S cn d li nu nhuw
            long long y=a-temp;
            for(long long i=1; i<=y; i++){
                for(long long j=1; j<=x; j++) cout<<"G";//In ra y lan x+1 g cho du
                cout<<"GB";
            }
            for(long long i=y+1; i<=b; i++){
                for(long long j=1; j<=x; j++) cout<<"G";
                    cout<<"B";
            }
            for(long long i=1; i<=x; i++)
                cout<<"G";
        }
        else{
            swap(a, b);
            long long x=a/(b+1);//Tm
            long long temp=x*(b+1);//S cn d li nu nhuw
            long long y=a-temp;
            for(long long i=1; i<=y; i++){
                for(long long j=1; j<=x; j++) cout<<"B";//In ra y lan x+1 g cho du
                cout<<"BG";
            }
            for(long long i=y+1; i<=b; i++){
                for(long long j=1; j<=x; j++) cout<<"B";
                    cout<<"G";
            }
            for(long long i=1; i<=x; i++)
                cout<<"B";
        }
    }
}