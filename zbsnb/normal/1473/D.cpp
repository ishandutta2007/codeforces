#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int a[maxn];
int pre[maxn],pre_max[maxn],pre_min[maxn];
int suf[maxn],suf_max[maxn],suf_min[maxn];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n,q;cin>>n>>q;
        for(int i=1;i<=n;i++){
            char tmp;cin>>tmp;
            if(tmp=='+') a[i]=1;
            else a[i]=-1;
        }
        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1]+a[i];
            pre_max[i]=max(pre_max[i-1],pre[i]);
            pre_min[i]=min(pre_min[i-1],pre[i]);
        }
        suf[n+1]=suf_max[n+1]=suf_min[n+1]=0;
        for(int i=n;i>=1;i--){
            suf[i]=suf[i+1]+a[i];
            suf_max[i]=max(suf_max[i+1],suf[i]);
            suf_min[i]=min(suf_min[i+1],suf[i]);
        }
        while(q--){
            int l,r;cin>>l>>r;
            int minn=min(pre_min[l-1],pre[l-1]+suf[r+1]-suf_max[r+1]);
            int maxn=max(pre_max[l-1],pre[l-1]+suf[r+1]-suf_min[r+1]);
            cout<<maxn-minn+1<<endl;
        }
    }
}