#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=100010,BIT=1050010;
int n,m,k,sum[N],L[N],R[N],belong[N],tot;
ll res[N],cnt[BIT];
struct Question{int l,r,id;}q[N];

inline bool cmp(Question a,Question b){
    return belong[a.l]==belong[b.l]?a.r<b.r:belong[a.l]<belong[b.l];
}

inline void build(){
    tot=(int)(sqrt(n));
    for(int i=1;i<=tot;i++) L[i]=R[i-1]+1,R[i]=L[i]+tot-1;
    R[tot]=n;
    for(int i=1;i<=n;i++){
        for(int j=L[i];j<=R[i];j++) belong[j]=i;
    }
    belong[0]=1;
}

inline void MoDui(){
    int l=0,r=-1;ll ans=0;
    for(int i=1;i<=m;i++){
        while(r>q[i].r){
            cnt[sum[r]]--;
            ans-=cnt[sum[r]^k];
            r--;
        }
        while(r<q[i].r){
            ++r;
            ans+=cnt[sum[r]^k];
            cnt[sum[r]]++;
        }
        while(l>q[i].l){
            --l;
            ans+=cnt[sum[l]^k];
            cnt[sum[l]]++;
        }
        while(l<q[i].l){
            cnt[sum[l]]--;
            ans-=cnt[sum[l]^k];
            l++;
        }
        res[q[i].id]=ans;
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    build();
    for(int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        sum[i]=(sum[i-1]^x);
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d",&q[i].l,&q[i].r),q[i].id=i;
        q[i].l--;
    }
    sort(q+1,q+m+1,cmp);
    MoDui();
    for(int i=1;i<=m;i++) printf("%lld\n",res[i]);
    return 0;
}