// LUOGU_RID: 90884243
#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using u64=unsigned long long;
using db=double;
using pii=pair<int,int>;
using vi=vector<int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch-'0'),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back

mt19937_64 rng(random_device {}());

const int N=2e5+10;

int n,m,cov[N];
u64 sum[N];
unordered_map<u64,i64> pos,cnt;
i64 ans;

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),m=rdi();
    for(int i=1;i<=n;i++){
        int l=rdi(),r=rdi();
        u64 v=rng();
        sum[l+1]^=v,sum[r+1]^=v;
        cov[l]++,cov[r+1]--;
    }
    for(int i=1;i<=m;i++) sum[i]^=sum[i-1];
    for(int i=1;i<=m;i++){
        sum[i]^=sum[i-1];
        cnt[sum[i]]++,pos[sum[i]]+=i-1;
        ans+=(i64)cnt[sum[i]]*i-pos[sum[i]];
    }

    for(int i=1;i<=m;i++) cov[i]+=cov[i-1];
    for(int i=1,j;i<=m;i++){
        if(!cov[i]){
            j=i;
            while(j<=m&&!cov[j]) ++j;
            for(int len=1;len<=j-i;len++)
                ans-=(i64)(j-i-len+1)*len;
            i=j-1;
        }
    }
    cout<<ans<<'\n';
    return 0;
}