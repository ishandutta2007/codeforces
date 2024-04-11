#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
#define double long double
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
#define mp make_pair
typedef pair<double,double> pdd;
 
const int N=100010;
int n,q;
double p[N];
 
struct SegmentTree{
#define lson (now<<1)
#define rson (now<<1|1)
#define mid ((l+r)>>1)
    double mul[N<<2],sum[N<<2];
    void pushup(int now){
        mul[now]=mul[lson]*mul[rson];
        sum[now]=sum[lson]+mul[lson]*sum[rson];
    }
    void build(int now,int l,int r){
        if(l==r){
            mul[now]=sum[now]=(1-p[l])/p[l];
            return;
        }
        build(lson,l,mid);build(rson,mid+1,r);
        pushup(now);
    }
    void modify(int now,int l,int r,int x,double val){
        if(l==x&&r==x){
            mul[now]=sum[now]=(1-val)/val;
            return;
        }
        if(x<=mid) modify(lson,l,mid,x,val);
        if(x>mid) modify(rson,mid+1,r,x,val);
        pushup(now);
    }
    pdd query(int now,int l,int r,int x,int y){
        if(x<=l&&r<=y) return mp(mul[now],sum[now]);
        bool flg1=(x<=mid),flg2=(y>mid);
        pdd tmp1,tmp2;
        if(flg1&&flg2){
            tmp1=query(lson,l,mid,x,y),tmp2=query(rson,mid+1,r,x,y);
            return mp(tmp1.first*tmp2.first,tmp1.second+tmp1.first*tmp2.second);
        }
        else if(flg1) return tmp1=query(lson,l,mid,x,y);
        else return tmp2=query(rson,mid+1,r,x,y);
    }
}s;
 
int main(){
    n=rdi(),q=rdi();
    for(int i=1;i<=n;i++){
        int a=rdi(),b=rdi();
        p[i]=1.0*a/b;
    }
    s.build(1,1,n);
    while(q--){
        int typ=rdi(),x=rdi(),y=rdi();
        if(typ==1){
            int z=rdi();
            s.modify(1,1,n,x,1.0*y/z);
        }
        else{
            printf("%.5Lf\n",1.0/(s.query(1,1,n,x,y).second+1));
        }
    }
    return 0;
}
// 123332111123123123