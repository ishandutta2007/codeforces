#include<iostream>
#include<algorithm>
#include<numeric>
#include<set>
using namespace std;
int a[300010];
int b[300010];
int e[300010];
int d[300010];
int dp[300010];
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=1;i<=n;i++)a[i]=b[i]=e[i]=d[i]=0;
        for(int i=1;i<=n;i++){
            int tmp;cin>>tmp;
            a[tmp]++;
            b[tmp]=b[tmp]==0?i:b[tmp];
            e[tmp]=i;
        }
        int ans=1;
        int p=0;
        for(int i=1;i<=n;i++){
            if(a[i])d[++p]=i;
        }
        dp[d[1]]=1;
        for(int i=2;i<=p;i++){
            if(e[d[i-1]]<b[d[i]])dp[d[i]]=dp[d[i-1]]+1;
            else dp[d[i]]=1;
            ans=max(ans,dp[d[i]]);
        }
        //cout<<p<<" "<<ans<<endl;
        cout<<p-ans<<endl;
    }
}