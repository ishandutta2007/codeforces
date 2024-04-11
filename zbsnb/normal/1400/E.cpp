#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[5010];
int dfs(int l,int r,int h){
    if(l>r)return 0;
    int minn=2e9,pos;
    for(int i=l;i<=r;i++){
        if(a[i]<minn)minn=a[i],pos=i;
    }
    return min(r-l+1,dfs(l,pos-1,minn)+dfs(pos+1,r,minn)+minn-h);
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cout<<dfs(1,n,0)<<endl;
}