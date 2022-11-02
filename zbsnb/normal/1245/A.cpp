#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
using namespace std;
#define ll long long

int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
    int t;cin>>t;
    while(t--){
        int a,b;cin>>a>>b;
        cout<<(gcd(a,b)==1?"Finite":"Infinite")<<endl;
    }
}