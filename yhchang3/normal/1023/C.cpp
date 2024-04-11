#include<bits/stdc++.h>

using namespace std;
int ans[200020];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    for(int a=0,b=0;b<k/2;a++){
        if(s[a]=='('){
            ans[a]++;
            b++;
        }
    }
    for(int a=n-1,b=0;b<k/2;a--){
        if(s[a]==')'){
            ans[a]++;
            b++;
        }
    }
    for(int i=0;i<n;i++)
        if(ans[i])  cout<<s[i];
    cout<<endl;
}