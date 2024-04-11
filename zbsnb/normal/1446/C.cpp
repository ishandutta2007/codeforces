#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000010];
int dfs(int l,int r,int k){
    if(l==r) return 1;
    int pos=l-1;
    for(int i=l;i<=r;i++){
        if(((a[i]>>k)&1)==0) pos=i;
        else break;
    }
    if(pos==l-1||pos==r) return dfs(l,r,k-1);
    int ans1=dfs(l,pos,k-1);
    int ans2=dfs(pos+1,r,k-1);
    return max(ans1+1,ans2+1);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    cout<<n-dfs(1,n,31)<<endl;
}