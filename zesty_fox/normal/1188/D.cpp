// LUOGU_RID: 96470492
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

template<typename T>
void ckmin(T &a,T b) {if(a>b) a=b;}

const int N=1e5+10,L=63;

int n;
i64 a[N];

int id[N],f[2][N];

int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
    n=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi64();
    
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) a[i]=a[n]-a[i];
    iota(id+1,id+n+1,1);

    memset(f,0x3f,sizeof(f));
    f[1][0]=0;

    for(int b=0,nw=0;b<L;b++,nw^=1){
        memset(f[nw],0x3f,sizeof(f[nw]));

        int cnt[3]={0};
        for(int i=1;i<=n;i++) cnt[a[i]>>b&1]++;
        for(int i=0;;i++){
            int v=f[nw^1][i];
            ckmin(f[nw][cnt[2]],v+cnt[1]);
            ckmin(f[nw][cnt[1]+cnt[2]],v+cnt[0]+cnt[2]);

            if(i==n) break;
            int bit=a[id[i+1]]>>b&1;
            cnt[bit]--,cnt[bit+1]++;
        }

        stable_partition(id+1,id+n+1,[&](int x){return a[x]>>b&1;});
    }

    int ans=INT_MAX;
    for(int i=0;i<=n;i++)
        ans=min(ans,f[(L-1)&1][i]+i);
    cout<<ans<<endl;
    return 0;
}