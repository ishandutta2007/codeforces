#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    string s,t;
    cin>>n>>m;
    cin>>s;
    cin>>t;
    int sw=0;
    for(int i=0;i<n;i++)
        if(s[i]=='*')   sw=1;
    if(sw){
        if(n>m+1){
            cout<<"NO"<<endl;
            return 0;
        }
        for(int i=0;s[i]!='*';i++){
            if(s[i]!=t[i]){
                cout<<"NO"<<endl;
                return 0;
            }
        }
        for(int i=n-1;s[i]!='*';i--){
            if(s[i]!=t[i+m-n]){
                cout<<"NO"<<endl;
                return 0;
            }
        }
        cout<<"YES"<<endl;
    }
    else{
        if(s==t)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}