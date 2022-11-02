#include<bits/stdc++.h>
using namespace std;
#define ll long long
// #define int long long
char s[200010];
char ans[200010];
char ans2[200010];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        cin>>s;int n=strlen(s);
        int x;cin>>x;
        for(int i=0;i<n;i++){
            ans[i]='1';
        }
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                if(i>=x)ans[i-x]='0';
                if(i<n-x)ans[i+x]='0';
            }
        }
        for(int i=0;i<n;i++){
            ans2[i]='0';
        }
        for(int i=0;i<n;i++){
            if(i>=x&&ans[i-x]=='1')ans2[i]='1';
            if(i<n-x&&ans[i+x]=='1')ans2[i]='1';
        }

        ans[n]=ans2[n]=0;
        int flg=0;
        for(int i=0;i<n;i++)if(ans2[i]!=s[i])flg=1;
        // cout<<ans<<endl;
        // cout<<ans2<<endl;
        if(flg)cout<<-1<<endl;
        else{
            cout<<ans<<endl;
        }
    }
}