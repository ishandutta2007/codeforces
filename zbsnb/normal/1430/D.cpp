#include<bits/stdc++.h>
using namespace std;
#define ll long long
char s[1000010];
int a[1000010];
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;cin>>(s+1);
        int cnt=1,m=0;
        for(int i=2;i<=n+1;i++){
            if(i==n+1||s[i]!=s[i-1]){
                a[++m]=cnt;
                cnt=1;
            }
            else cnt++;
        }
        int ans=0;int pos=0;
        for(int i=1;i<=m;i++){
            if(a[i]==1){
                pos=max(pos,i+1);
                while(pos<=m&&a[pos]==1) pos++;
                if(pos==m+1){
                    ans+=(m-i+1+1)/2;
                    break;
                }
                else a[pos]--;
            }
            ans++;
        }
        cout<<ans<<endl;
    }
}