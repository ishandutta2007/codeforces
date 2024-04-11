#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
using namespace std;
#define ll long long
#define int long long

int a[200010];
int pre[200010];
int find(int x){return pre[x]==x?x:pre[x]=find(pre[x]);}
int m,n,k,t;

struct nod{
    int l,r,k;
    bool operator<(const nod x){
        return k>x.k;
    }
}e[200010];
int solve(int x){
    for(int i=1;i<=n+1;i++)pre[i]=i;
    for(int i=1;i<=k;i++){
        // for(int i=1;i<=n;i++)cout<<find(i)<<" ";cout<<endl;
        if(e[i].k<=x)break;
        int now=find(e[i].l);
        while(now<=e[i].r){
            int tmp=find(now+1);
            // cout<<now<<" "<<tmp<<endl;
            pre[now]=tmp;
            now=tmp;
        }
    }
    int ret=0;
    for(int i=1;i<=n;i++)ret+=find(i)!=i;
    return 2*ret+n+1;
}
signed main(){
    cin>>m>>n>>k>>t;
    for(int i=1;i<=m;i++)cin>>a[i];

    for(int i=1;i<=k;i++)cin>>e[i].l>>e[i].r>>e[i].k;
    sort(e+1,e+k+1);

    int l=1,r=2e5;
    int ans=0;
    while(l<=r){
        // cout<<l<<" "<<r<<" "<<solve(m)<<endl;
        int m=l+r>>1;
        if(solve(m)<=t){
            ans=m;
            r=m-1;
        }
        else l=m+1;
    }

    // cout<<ans<<endl;

    int ans1=0;
    for(int i=1;i<=m;i++){
        ans1+=a[i]>=ans;
    }
    cout<<ans1<<endl;

}