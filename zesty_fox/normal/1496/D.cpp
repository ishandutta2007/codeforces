#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <algorithm>
#include <vector>
#include <set>
#include <queue>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

#define rdi read<int>
#define rdl read<ll>
#define fi first
#define sec second
#define pb push_back
#define mp make_pair

const int N=100010;
int n,a[N];
int L1[N],R1[N],L2[N],R2[N],cnt1,cnt2;
int bl1[N],bl2[N],ans;
int main(){
    n=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi();
    a[0]=n+1;
    for(int i=1;i<=n;i++){
        if(a[i]<a[i-1]) L1[++cnt1]=i,R1[cnt1]=i;
        if(a[i]>a[i-1]) R1[cnt1]=i;
    }
    a[n+1]=n+1;
    for(int i=n;i>=1;i--){
        if(a[i]<a[i+1]) R2[++cnt2]=i,L2[cnt2]=i;
        if(a[i]>a[i+1]) L2[cnt2]=i;
    }
    a[0]=a[n+1]=0;
    reverse(L2+1,L2+cnt2+1);reverse(R2+1,R2+cnt2+1);
    for(int i=1;i<=cnt1;i++){
        for(int j=L1[i];j<=R1[i];j++) bl1[j]=i;
    }
    for(int i=1;i<=cnt2;i++){
        for(int j=L2[i];j<=R2[i];j++) bl2[j]=i;
    }
    vector<int> buf;buf.clear();
    int maxn=0;
    for(int i=1;i<=n;i++){
        int tmp=max(R2[bl2[i]]-i+1,i-L1[bl1[i]]+1);
        if(tmp>maxn){
            maxn=tmp;
            buf.clear();buf.pb(i);
        }
        else if(tmp==maxn){
            buf.pb(i);
        }
    }
    if(buf.size()>1){
        puts("0");
        return 0;
    }
    for(auto i:buf){
        if(L1[bl1[i]]==i||R2[bl2[i]]==i) continue;
        int tmp=L1[bl1[i]];
        if(!((i-tmp)&1)) tmp++;
        if(R2[bl2[i]]-i<i-tmp+1) continue;
        tmp=R2[bl2[i]];
        if(!((tmp-i)&1)) tmp--;
        if(i-L1[bl1[i]]<tmp-i+1) continue;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}