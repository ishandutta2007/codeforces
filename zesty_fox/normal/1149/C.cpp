#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=200010;

struct SGT{
#define lson (now<<1)
#define rson (now<<1|1)
#define mid ((l+r)>>1)
    struct Node{
        int sum;
        int mxpre,mnsuf;
        int lrval,lval,rval,val;
        friend Node operator + (const Node &a,const Node &b){
            return (Node){
            a.sum+b.sum,\
            max(a.mxpre,a.sum+b.mxpre),\
            min(b.mnsuf,a.mnsuf+b.sum),\
            max(a.lrval+b.sum,b.lrval-a.sum),\
            max({a.lval,a.lrval+b.mxpre,b.lval-a.sum}),\
            max({b.rval,b.lrval-a.mnsuf,a.rval+b.sum}),\
            max({a.val,b.val,a.rval+b.mxpre,b.lval-a.mnsuf})};
        }
    }t[N*4];
    Node e(int val) const{return (Node){val,max(val,0),min(val,0),1,1,1,1};}
    void init(int now,int l,int r,char *s){
        if(l==r){
            t[now]=e(s[l]=='('?1:-1);
            return;
        }
        init(lson,l,mid,s);init(rson,mid+1,r,s);
        t[now]=t[lson]+t[rson];
    }
    void modify(int now,int l,int r,int x,char ch){
        if(l==r){
            t[now]=e(ch=='('?1:-1);
            return;
        }
        x<=mid?modify(lson,l,mid,x,ch):modify(rson,mid+1,r,x,ch);
        t[now]=t[lson]+t[rson];
    }
    int query() {return t[1].val;}
#undef lson
#undef rson
#undef mid
}t;

int n,m,len;
char s[N];

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),m=rdi(),len=2*(n-1);scanf("%s",s+1);
    t.init(1,1,len,s);cout<<t.query()<<'\n';
    while(m--){
        int x=rdi(),y=rdi();swap(s[x],s[y]);
        t.modify(1,1,len,x,s[x]),t.modify(1,1,len,y,s[y]);
        cout<<t.query()<<'\n';
    }
    return 0;
}