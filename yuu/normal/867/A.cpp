#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
    cin>>s>>s;
    char old=s[0];
    int cnt=0;
    for(char c: s){
       if(c!=old){
           old=c;
           if(c=='S') cnt--;
           else cnt++;
       } 
    }
    if(cnt>0) cout<<"YES\n";
    else cout<<"NO\n";
}