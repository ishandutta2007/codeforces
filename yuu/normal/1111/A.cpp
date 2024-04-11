#include <bits/stdc++.h>
using namespace std;
string s, t;
string v="aeiou";
int type[256];
int main(){
    cin>>s>>t;
    if(s.size()!=t.size()){
        puts("No");
        return 0;
    }
    for(char c: v) type[c]=1;
    for(int i=0; i<s.size(); i++){
        if(type[s[i]]!=type[t[i]]){
            puts("No");
            return 0;
        }
    }
    puts("Yes");
}