#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3f
ll a[200010],ans;
int getm(int l,int r,int k){
    int m=l-1;
    while(m<r&&(a[m+1]&k)==0) m++;
    return m;
}
ll find(int l1,int r1,int l2,int r2,int k){
    // cout<<"find:"<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<" "<<k<<endl;
    ll ret=inf;
    if(r1<=l1||r2<=l2||k==0){
        for(int i=l1;i<=r1;i++)
            for(int j=l2;j<=r2;j++)
                ret=min(ret,a[i]^a[j]);
        // cout<<ret<<endl;
        return ret;
    }
    int m1=getm(l1,r1,k), m2=getm(l2,r2,k);
    // cout<<m1<<" "<<m2<<"m"<<endl<<endl;
    if(m1==l1-1&&m2==r2||m1==r1&&m2==l2-1)
        return k|find(l1,r1,l2,r2,k>>1);
    return min(find(l1,m1,l2,m2,k>>1),find(m1+1,r1,m2+1,r2,k>>1));
}
void dfs(int l,int r,int k){
    if(r<l||k==0) return;
    int m=getm(l,r,k);
    ll f=find(l,m,m+1,r,k>>1);
    if(f!=inf)ans+=f;
    // cout<<"now:"<<l<<" "<<m<<" "<<r<<" "<<k<<" "<<f<<endl;
    dfs(l,m,k>>1);dfs(m+1,r,k>>1);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    dfs(1,n,1<<30);
    cout<<ans<<endl;
}