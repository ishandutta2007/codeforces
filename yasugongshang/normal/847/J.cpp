#include<cstdio>
#include<cctype>
#include<cstring>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=10005,M=41005;
const int oo=1e9+7;
int a[N],b[N],nedge,son[N],n,m,gap[N],d[N],que[N],l,r;
struct edge{
	int nextt,ed,di;
}e[M];
inline int	read()// 
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(int a){
	write(a); puts("");
}
inline void aedge(int a,int b,int c){//cout<<a<<" "<<b<<" "<<c<<endl;
	e[++nedge].nextt=son[a];
	son[a]=nedge;
	e[nedge].ed=b;
	e[nedge].di=c;
}
inline void ycl(int s,int t) {
    memset(gap,0,sizeof gap),memset(d,0,sizeof d),++gap[d[t]=1];
    que[l=r=1]=t;
    while(l<=r){
        int k=que[l++];
        for (int i=son[k];i;i=e[i].nextt)if(!d[e[i].ed])++gap[d[e[i].ed]=d[k]+1],que[++r]=e[i].ed;
    }
}
inline int aug(int x,int s,int t,int mmin) {
    if(x==t)return mmin;
    int flow=0; 
    for(int i=son[x];i;i=e[i].nextt)if(d[x]==d[e[i].ed]+1){
        int tmp=aug(e[i].ed,s,t,min(mmin,e[i].di));
        flow+=tmp;mmin-=tmp;e[i].di-=tmp;e[((i-1)^1)+1].di+=tmp;
        if(!mmin)return flow;
    }
    if(!(--gap[d[x]]))d[s]=n+1; ++gap[++d[x]];
    return flow;
}
inline int maxflow(int s,int t) {
    ycl(s,t); int ans=aug(s,s,t,oo);
    while(d[s]<=n)ans+=aug(s,s,t,oo);
    return ans;
}
inline int check(int x){
	int s=n+m+1,t=n+m+2,zs=n; 
	for(int i=1;i<=t;i++)son[i]=0; nedge=0;
	for(int i=1;i<=m;i++){aedge(i,a[i]+m,1); aedge(a[i]+m,i,0); aedge(i,b[i]+m,1); aedge(b[i]+m,i,0);}
	for(int i=1;i<=m;i++){aedge(s,i,1); aedge(i,s,0); }
	for(int i=1;i<=n;i++){aedge(i+m,t,x); aedge(t,i+m,0);} n=t;int ttt=maxflow(s,t); n=zs;
	return ttt==m;
}
int main(){
    n=read(); m=read(); nedge=0; 
    for(int i=1;i<=m;i++){
    	cin>>a[i]>>b[i];
	}
	int l=0,r=5005;
	while(l<r){//cout<<l<<" "<<r<<endl;
		int mid=l+r>>1;
		if(check(mid))r=mid; else l=mid+1;
	}
	check(l); writeln(l);
	for(int i=1;i<=4*m;i+=4){
		if(e[i].di)swap(a[i/4+1],b[i/4+1]);
		write(a[i/4+1]); putchar(' '); writeln(b[i/4+1]);
	}
}