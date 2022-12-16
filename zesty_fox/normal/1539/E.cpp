#include <bits/stdc++.h>
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
#define rdll read<ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=100010;
int n,m;
struct Segment{
    int l,r;
    Segment operator & (const Segment &rhs){
        return {max(l,rhs.l),min(r,rhs.r)};
    }
    bool in(int x) {return l<=x&&x<=r;}
};
struct Operation{int k;Segment x,y;}op[N];

int lg2[N];
void init_lg(){
    for(int i=2;i<=n;i++) lg2[i]=lg2[i>>1]+1;
}

struct ST{
    Segment a[N][20];
    void init(Segment *in){
        for(int i=1;i<=n;i++) a[i][0]=in[i];
        for(int j=1;j<=lg2[n];j++){
            for(int i=1;i<=n-(1<<j)+1;i++){
                a[i][j]=a[i][j-1]&a[i+(1<<(j-1))][j-1];
            }
        }
    }
    Segment query(int l,int r){
        int k=lg2[r-l+1];
        return a[l][k]&a[r-(1<<k)+1][k];
    }
}st[2];

struct Partial_Sum{
    int sum[N];
    void init(int *in){partial_sum(in+1,in+n+1,sum+1);}
    int query(int l,int r){return sum[r]-sum[l-1];}
}ps[2];


int pos[N][2],f[N][2],pre[N][2],res[N];
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    n=rdi(),m=rdi();init_lg();
    for(int i=1;i<=n;i++) 
        op[i].k=rdi(),op[i].x.l=rdi(),op[i].x.r=rdi(),op[i].y.l=rdi(),op[i].y.r=rdi();
    
    {
        Segment a[N],b[N];
        for(int i=1;i<=n;i++) a[i]=op[i].x,b[i]=op[i].y;
        st[0].init(a),st[1].init(b);
    }
    {
        int a[N],b[N];
        for(int i=1;i<=n;i++) a[i]=op[i].x.in(op[i].k),b[i]=op[i].y.in(op[i].k);
        ps[0].init(a),ps[1].init(b);
    }
    
    for(int i=1;i<=n;i++){
        for(int j=0;j<2;j++){
            int l=i-1,r=n;
            while(l<r){
                int mid=(l+r+1)>>1;
                if(!st[j^1].query(i,mid).in(op[i-1].k)||ps[j].query(i,mid)<mid-i+1) r=mid-1;
                else l=mid;
            }
            pos[i][j]=l;
        }
    }

    pii s[2]={mp(pos[1][0],1),mp(pos[1][1],1)};
    for(int i=1;i<=n;i++){
        for(int j=0;j<2;j++){
            if(s[j].fi<i) continue;
            int pr=s[j].se;
            pre[i][j]=pr,f[i][j]=1;
        }
        for(int j=0;j<2;j++){
            if(f[i][j]) s[j^1]=max(s[j^1],mp(pos[i+1][j^1],i+1));
        }
    }
    if(!f[n][0]&&!f[n][1]) puts("No");
    else{
        puts("Yes");
        int now=n,val=f[n][0]?0:1;
        while(now){
            int pr=pre[now][val];
            for(int i=pr;i<=now;i++) res[i]=val;
            now=pr-1,val^=1;
        }
        for(int i=1;i<=n;i++) putchar(res[i]+'0'),putchar(' ');
        putchar('\n');
    }
    return 0;
}