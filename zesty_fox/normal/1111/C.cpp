#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=100010;
const ll INF=0x3f3f3f3f3f3f3f3f;
int n,k,A,B;
ll ans;
struct SegmentTree{
    #define mid (((r-l)>>1)+l)
    int tot,lson[N<<5],rson[N<<5],cnt[N<<5],rt;
    ll val[N<<5];
    inline int newnode(){
        ++tot;lson[tot]=rson[tot]=0;
        return tot;
    }
    void pushup(int now,int l,int r){
        cnt[now]=cnt[lson[now]]+cnt[rson[now]];
        val[now]=INF;
        if(cnt[now]) val[now]=min(val[now],(ll)(r-l+1)*cnt[now]*B);
        else val[now]=min(val[now],(ll)A);
        val[now]=min(val[now],val[lson[now]]+val[rson[now]]);
    }
    void insert(int& now,int l,int r,int x){
        if(now==0) now=newnode();
        if(l==r){
            cnt[now]++;
            val[now]=B*cnt[now];
            return;
        }
        if(x<=mid) insert(lson[now],l,mid,x);
        else insert(rson[now],mid+1,r,x);
        pushup(now,l,r);
    }
}st;
int main(){
    scanf("%d%d%d%d",&n,&k,&A,&B);
    fill(st.val,st.val+(N<<5),A);
    for(int i=1;i<=k;i++){
        int x;scanf("%d",&x);
        st.insert(st.rt,1,(1<<n),x);
    }
    printf("%lld\n",st.val[1]);
    return 0;
}