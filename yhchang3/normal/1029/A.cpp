#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k,pos;
    cin>>n>>k;
    string s,t,ans;
    cin>>t;
    for(int i=1;i<=n;i++){
        string tmp;
        tmp=t.substr(0,i)+t;
        if(tmp.substr(0,n)==t){
            pos=i;
            break;
        }
    }
    for(int i=1;i<k;i++){
        ans+=t.substr(0,pos);
    }
    ans+=t;
    cout<<ans<<endl;
}