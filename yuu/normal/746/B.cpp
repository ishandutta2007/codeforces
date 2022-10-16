#include <iostream>
#include <stdio.h>
using namespace std;
string s;
string res="";
string r1="";
string r2="";
int main(){
    int n;
//    freopen("B.INP", "r", stdin);
    cin>>n>>s;
    if(n==1){
        cout<<s;
        return 0;
    }
    else if(n%2){
        res=s[0];
        for(int i=1; i<n; i+=2)
            res=s[i]+res+s[i+1];
    }
    else{
        for(int i=0; i<n; i+=2)
            res=s[i]+res+s[i+1];
    }
    cout<<res;
}