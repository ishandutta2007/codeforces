#include <bits/stdc++.h>
using namespace std;
int k;
string a, b, c;
int main(){
    cin>>k>>a>>b;
    for(auto &x: a) x-='a';
    for(auto &x: b) x-='a';
    for(int i=0; i<k; i++) c.push_back(a[i]+b[i]);
    for(int i=k-1; i>0; i--) if(c[i]>=26){
    	c[i-1]++;
        c[i]-=26;
    }
    for(int i=0; i<k; i++){
        if((c[i]%2)&&(i<k)) c[i+1]+=26;
        c[i]/=2;
        c[i]+='a';
    }
    cout<<c;
}