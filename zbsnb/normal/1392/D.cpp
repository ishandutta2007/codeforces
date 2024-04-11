#include<bits/stdc++.h>
using namespace std;
#define ll long long
char s[200010];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;cin>>s+1;
        int ans=0;int b=0;int pre=1;int flg=0;
        for(int i=2;i<=n+1;i++){
            if(i==n+1){
                if(!flg){
                    if(n>=3)ans=(n+2)/3;
                    break;
                }
                if(s[1]==s[n]) ans+=(i-pre+b)/3;
                else ans+=(i-pre)/3+b/3;
                break;
            }
            if(s[i]!=s[i-1]){
                if(flg) ans+=(i-pre)/3;
                else flg=1,b=i-pre;
                pre=i;
            }
            // cout<<i<<" "<<ans<<endl;
        }
        cout<<ans<<endl;   
    }
}