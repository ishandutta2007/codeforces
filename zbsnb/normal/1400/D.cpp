#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[3010];
int sum1[3010][3010];
int sum2[3010][3010];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=0;i<=n+1;i++){
            for(int j=0;j<=n+1;j++){
                sum1[i][j]=sum2[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum1[i][a[i]]++;
            sum2[i][a[i]]++;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                sum1[i][j]+=sum1[i-1][j];
            }
        }
        for(int i=n;i>=1;i--){
            for(int j=1;j<=n;j++){
                sum2[i][j]+=sum2[i+1][j];
            }
        }
        ll ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans+=sum1[i-1][a[j]]*sum2[j+1][a[i]];
            }
        }
        cout<<ans<<endl;
    }
}