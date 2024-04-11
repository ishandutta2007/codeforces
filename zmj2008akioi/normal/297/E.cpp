#include <cstdio>
#include <cstring>
#include <algorithm>
const int N=1e5,EXT=10;
int n,mx,ont,a[N+EXT],b[N+EXT],l[N+EXT],r[N+EXT],trr[2*N+EXT];
long long ans;
char cdc;
struct option{
	int x,y,id,tp;
	option(){};
	option(int x,int y,int id,int tp):x(x),y(y),id(id),tp(tp){};
}orr[2*N+EXT];
inline int lowbit(int x){return x&(-x);}
inline void swap(int &x,int &y){x^=y^=x^=y;}
void modify(int x,int d){while(x<=2*n)trr[x]+=d,x+=lowbit(x);}
int query(int x){int res=0;while(x)res+=trr[x],x-=lowbit(x);return res;}
inline bool cmp(option a,option b){return a.x<b.x||(a.x==b.x&&a.tp<b.tp);}
inline int read(){
	int res=0;
	for(;cdc<'0'||cdc>'9';cdc=getchar());
	for(;!(cdc<'0'||cdc>'9');cdc=getchar())res=(res<<1)+(res<<3)+(cdc^48);
	return res;
}
int main(){
	n=read(),mx=2*n+1;
	for(register int i=1;i<=n;++i){
		a[i]=read(),b[i]=read();
		if(a[i]>b[i])swap(a[i],b[i]);
	}
	ont=0,memset(trr,0,sizeof(trr));
	for(register int i=1;i<=n;++i){
		orr[++ont]=option(a[i],b[i],i,0);
		orr[++ont]=option(a[i]-1,a[i]-1,i,1);
	}
	std::sort(orr+1,orr+1+ont,cmp);
	for(register int i=1;i<=ont;++i){
		if(orr[i].tp==0)modify(orr[i].y,1);
		if(orr[i].tp==1)l[orr[i].id]+=query(orr[i].y);
	}
	ont=0,memset(trr,0,sizeof(trr));
	for(register int i=1;i<=n;++i){
		orr[++ont]=option(a[i],mx-b[i],i,0);
		orr[++ont]=option(a[i]-1,mx-b[i]-1,i,1);
	}
	std::sort(orr+1,orr+1+ont,cmp);
	for(register int i=1;i<=ont;++i){
		if(orr[i].tp==0)modify(orr[i].y,1);
		if(orr[i].tp==1)l[orr[i].id]+=query(orr[i].y);
	}
	ont=0,memset(trr,0,sizeof(trr));
	for(register int i=1;i<=n;++i){
		orr[++ont]=option(mx-a[i],mx-b[i],i,0);
		orr[++ont]=option(mx-b[i]-1,mx-b[i]-1,i,1);
	}
	std::sort(orr+1,orr+1+ont,cmp);
	for(register int i=1;i<=ont;++i){
		if(orr[i].tp==0)modify(orr[i].y,1);
		if(orr[i].tp==1)l[orr[i].id]+=query(orr[i].y);
	}
	ont=0,memset(trr,0,sizeof(trr));
	for(register int i=1;i<=n;++i){
		orr[++ont]=option(mx-a[i],b[i],i,0);
		orr[++ont]=option(mx-a[i]-1,b[i]-1,i,1);
	}
	std::sort(orr+1,orr+1+ont,cmp);
	for(register int i=1;i<=ont;++i){
		if(orr[i].tp==0)modify(orr[i].y,1);
		if(orr[i].tp==1)r[orr[i].id]+=query(orr[i].y);
	}
	for(register int i=1;i<=n;++i)ans+=(long long)(l[i]+r[i])*(n-1-l[i]-r[i]);
	ans/=2;
	for(register int i=1;i<=n;++i)ans+=(long long)l[i]*r[i];
	printf("%lld",(long long)n*(n-1)*(n-2)/6-ans);
	return 0;
}