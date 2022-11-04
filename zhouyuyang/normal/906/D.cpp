#include<bits/stdc++.h>
const int N=100005;
const int M=20000005;
const int inf=N-4;
const int lim=20000000;
typedef long long ll;
using namespace std;
int n,m,x,cnt;
ll c[N],a[N];
int las[N];
map<int,int> phi; 
inline int read(){
    int f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}
inline int fpow(int x,ll p,int yql){
    int ans=1;
    for(;p;p>>=1,x=1LL*x*x%yql)if(p&1)ans=1LL*ans*x%yql;
    return ans;
}
inline int calcphi(int x){
	if (phi.find(x)!=phi.end())
		return phi[x];
     int ans=x,tmp=x;
     for (int i=2;i*i<=x;i++)
     	if (x%i==0){
     		ans-=ans/i;
     		for (;x%i==0;x/=i);
     	}
    if (x!=1)
    	ans-=ans/x;
    return phi[tmp]=ans;
}
ll sumv[N<<2],addv[N<<2],fone[N<<2];
#define lson (o<<1)
#define rson (o<<1|1)
inline void pushup(int o){
    sumv[o]=sumv[lson]+sumv[rson];
    fone[o]=min(fone[lson],fone[rson]);
}
inline void build(int o,int l,int r){
    fone[o]=inf;
    if(l==r){sumv[o]=a[l];if(a[l]==1)fone[o]=l;return;}
    int mid=(l+r)>>1;
    build(lson,l,mid);build(rson,mid+1,r);
    pushup(o);
}
inline ll querysum(int o,int l,int r,int q){
    if(l==r)return sumv[o];
    int mid=(l+r)>>1;
    if(q<=mid)return querysum(lson,l,mid,q);
    else return querysum(rson,mid+1,r,q);
}
inline ll query(int q){
    if(las[q]==m)return a[q];
    las[q]=m;
    return a[q]=querysum(1,1,n,q);
}
inline ll calc(int l,int r,int yql){
    if(query(l)%yql==0)return 0;
    int phiyql=calcphi(yql);
    if(yql==1)return 1;
    if(l==r)return query(l)%yql+(query(l)>=yql)*yql;
    int f=min(r,l+5);
    for(int i=l+1;i<=f;i++)if(query(i)==1){f=i;break;}
    ll last=query(f),q=0;
    for(int i=f-1;i>=l+1;i--){
        q=last,last=1;
        while(q--){
            last*=query(i);
            if(last>=phiyql)return fpow(query(l)%yql,calc(l+1,r,phiyql)+phiyql,yql);
        }
    }
    return fpow(query(l)%yql,last,yql);
}
int main(){
    memset(las,-1,sizeof(las));
    n=read();
	int yql=read();
    for(int i=1;i<=n;i++)a[i]=read();
    build(1,1,n);
    m=read();
    while(m--){
        int l=read(),r=read();
        printf("%I64d\n",(calc(l,r,yql))%yql);
    }
}