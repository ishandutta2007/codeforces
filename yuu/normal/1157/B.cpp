#include <bits/stdc++.h>
using namespace std;
char f[256];
int n;
string s;
int main(){
    cin>>n>>s;
    for(int i='1'; i<='9'; i++) cin>>f[i];
    for(int i=0; i<s.size(); i++){
        if(f[s[i]]>s[i]){
            for(int j=i; j<s.size(); j++) if(f[s[j]]>=s[j]) s[j]=f[s[j]]; else break;
            break;
        }
    }
    cout<<s;
}