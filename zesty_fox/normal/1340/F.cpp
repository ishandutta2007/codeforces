#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef unsigned long long u64;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=1e5+10,B=100019;
u64 pw[N];
int n,k,a[N];

void init(int n){
    pw[0]=1;
    for(int i=1;i<=n;i++) pw[i]=pw[i-1]*B;
}

struct SGT{
#define lson (now<<1)
#define rson (now<<1|1)
#define mid ((l+r)>>1)
    struct Node{
        u64 ha_p,ha_s;
        int len_p,len_s;
        bool fail;
    }t[N*4];
    u64 find_l(int now,int l,int r,int len){
        if(l==r) return len?t[now].ha_p:0;
        if(t[lson].len_p>=len) return find_l(lson,l,mid,len);
        else{
            int len1=len-t[lson].len_p;
            return t[lson].ha_p*pw[len1]+(find_l(rson,mid+1,r,t[lson].len_s+len1)+t[lson].ha_s*pw[len1]);
        }
    }
    u64 find_r(int now,int l,int r,int len){
        if(l==r) return len?t[now].ha_s:0;
        if(t[rson].len_s>=len) return find_r(rson,mid+1,r,len);
        else{
            int len1=len-t[rson].len_s;
            return t[rson].ha_s*pw[len1]+(find_r(lson,l,mid,t[rson].len_p+len1)+t[rson].ha_p*pw[len1]);
        }
    }
    // merge [l,m] and [m+1,r].
    Node merge(int nw1,int nw2,int l,int m,int r,const Node &a,const Node &b){
        Node ret;ret.fail=a.fail|b.fail;
        if(ret.fail) return ret;
        if(a.len_s<=b.len_p){
            u64 tmp=find_l(nw2,m+1,r,a.len_s);
            if(a.ha_s+tmp==0){
                ret.len_p=a.len_p+b.len_p-a.len_s;
                ret.ha_p=a.ha_p*pw[ret.len_p-a.len_p]+b.ha_p-tmp*pw[b.len_p-a.len_s];
                ret.len_s=b.len_s;
                ret.ha_s=b.ha_s;
            }
            else ret.fail=true;
        }
        else{
            u64 tmp=find_r(nw1,l,m,b.len_p);
            if(b.ha_p+tmp==0){
                ret.len_s=b.len_s+a.len_s-b.len_p;
                ret.ha_s=b.ha_s*pw[ret.len_s-b.len_s]+a.ha_s-tmp*pw[a.len_s-b.len_p];
                ret.len_p=a.len_p;
                ret.ha_p=a.ha_p;
            }
            else ret.fail=true;
        }
        return ret;
    }
    void pushup(int now,int l,int r){
        t[now]=merge(lson,rson,l,mid,r,t[lson],t[rson]);
    }
    void build(int now,int l,int r,int *a){
        if(l==r){
            if(a[l]>0) t[now]={0,(u64)a[l],0,1,0};
            else t[now]={(u64)a[l],0,1,0,0};
            return;
        }
        build(lson,l,mid,a),build(rson,mid+1,r,a);
        pushup(now,l,r);
    }
    void modify(int now,int l,int r,int x,int val){
        if(l==r){
            if(val>0) t[now]={0,(u64)val,0,1,0};
            else t[now]={(u64)val,0,1,0,0};
            return;
        }
        x<=mid?modify(lson,l,mid,x,val):modify(rson,mid+1,r,x,val);
        pushup(now,l,r);
    }
    bool query(int now,int l,int r,int x,int y){
        if(x<=l&&r<=y){
            if(t[now].fail) return false;
            static struct{int now,l,r,used,rest;u64 ha;}st[N];
            static int tp;
            if(x==l) tp=0;
            u64 ha=0;int used=0,rest=t[now].len_p;
            while(tp&&rest){
                int len=min(st[tp].rest,rest);
                u64 ha1=find_r(st[tp].now,st[tp].l,st[tp].r,st[tp].used+len)-st[tp].ha*pw[len];
                u64 ha2=find_l(now,l,r,used+len)-ha*pw[len];
                if(ha1+ha2) break;
                rest-=len,st[tp].rest-=len,used+=len,st[tp].used+=len;
                if(!st[tp].rest) --tp;
                else st[tp].ha=ha1+st[tp].ha*pw[len];
                if(!rest) break;
                else ha=ha2+ha*pw[len];
            }
            if(rest) return false;
            if(t[now].len_s) st[++tp]={now,l,r,0,t[now].len_s,0};
            if(y==r) return tp==0;
            return true;
        }
        if(y<=mid) return query(lson,l,mid,x,y);
        if(x>mid) return query(rson,mid+1,r,x,y);
        return query(lson,l,mid,x,y)&&query(rson,mid+1,r,x,y);
    }
}t;

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),k=rdi();init(n);
    for(int i=1;i<=n;i++) a[i]=rdi();
    t.build(1,1,n,a);
    int q=rdi();
    while(q--){
        int op=rdi();
        if(op==1){
            int x=rdi(),typ=rdi();
            a[x]=typ,t.modify(1,1,n,x,typ);
        }
        else{
            int l=rdi(),r=rdi();
            puts(t.query(1,1,n,l,r)?"Yes":"No");
        }
    }
    return 0;
}