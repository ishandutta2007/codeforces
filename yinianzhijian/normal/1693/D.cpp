#include<bits/stdc++.h>
#define ll long long
#define LL __int128
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
const int xx=2e5+5;
int a[xx],n,sa[xx],sb[xx];
int mn[xx<<2],mx[xx<<2];
void build(int k,int l,int r)
{
	if(l==r)return mn[k]=mx[k]=a[l],void();
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	mn[k]=min(mn[k<<1],mn[k<<1|1]);
	mx[k]=max(mx[k<<1],mx[k<<1|1]);
}
int ask(int k,int l,int r,int x,int y,int op)
{
	if(x>y||x>n)return op==0?1e9:-1e9;
	if(x<=l&&r<=y)return op==0?mn[k]:mx[k];
	int mid=l+r>>1;
	if(y<=mid)return ask(k<<1,l,mid,x,y,op);
	if(mid<x)return ask(k<<1|1,mid+1,r,x,y,op);
	int A=ask(k<<1,l,mid,x,y,op),B=ask(k<<1|1,mid+1,r,x,y,op);
	return op==0?min(A,B):max(A,B);
}
//papb 
int tmid=1,ty=1,A=1e9,B=-1e9,ta,tb;
void midgo()
{
	while(tmid<=n)
	{
		if(B<=a[tmid]&&a[tmid]<=A)
		{
			if(tmid==n){tmid++;break;}
			if(a[tmid]<a[tmid+1])B=a[tmid];
			else A=a[tmid];
			tmid++; 
		}
		else break;
	}
}
void tygo()
{
	ty=max(ty,tmid),ta=min(A,ask(1,1,n,tmid,ty-1,0)),tb=max(B,ask(1,1,n,tmid,ty-1,1));
	while(ty<=n)
	{
		if(a[ty]>tb)tb=a[ty];
		else if(a[ty]<ta)ta=a[ty];
		else break;
		ty++;
	}
}
signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	//sa,sb 
	// 
	//
	build(1,1,n);
	midgo(),tygo();
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=ty-i;
		if(i==n)break;
		if(a[i]<a[i+1]&&B==a[i])B=-1e9;
		if(a[i]>a[i+1]&&A==a[i])A=1e9;
		midgo(),tygo();
	}
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}