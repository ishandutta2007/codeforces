#include<bits/stdc++.h>
using namespace std;
string s;
int n,a,b,ans;//abans
int main(){
    cin>>n>>s;
    for(int i=0;s[i];i++){
        if(s[i]=='(')
            a++;
        else
            b++;
        if(b>a&&s[i]==')')//+1
            ans++;
    }
    if(a!=b){//
        cout<<-1;
        return 0;
    }
    cout<<ans*2;
    return 0;
}