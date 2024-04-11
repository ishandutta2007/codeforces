#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstring>
using namespace std;
#define ll long long
#define int long long

int a[200010];
int l[200010],r[200010];
signed main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int ans=0,cnt=0;;
    for(int i=1;i<=n+1;i++){
        if(i!=n+1&&(i==1||a[i]>a[i-1]))cnt++;
        else ans=max(ans,cnt),cnt=1;
    }
    for(int i=1;i<=n;i++){
        if(i!=1&&a[i]>a[i-1])l[i]=l[i-1]+1;
        else l[i]=1;
    }
    for(int i=n;i>=1;i--){
        if(i!=n&&a[i]<a[i+1])r[i]=r[i+1]+1;
        else r[i]=1;
    }
    for(int i=1;i<=n;i++){
        // cout<<i<<" "<<l[i-1]<<" "<<r[i+1]<<endl;
        if(i==1||i==n||a[i-1]<a[i+1])ans=max(ans,l[i-1]+r[i+1]);
    }
    cout<<ans<<endl;
}