#include<bits/stdc++.h>
//#include<cstring>
//#include<iostream>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
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
void wts(int x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(c,0);
}
const int xx=3e5+5;
int a[xx];
ll sum[xx][2];//01 
int stk[xx][2],top[2];
int to[xx][2];
struct node{int l,r;}e[xx*85];
map<int,int>sm;
int cst;
void clear(){memset(e,0,sizeof(e[0])*(cst+1));cst=0;}
struct seg
{
	int root[xx];
}t[2];
void insert(int &k,ll l,ll r,ll x)
{
	cst++;
//	if(cst%1000==0)cerr<<cst<<"\n";
	if(l==r)sm[cst]=sm[k];
	e[cst]=e[k],k=cst;
	
	if(l==r)return sm[k]++,void();
	ll mid=l+r>>1;
	if(x<=mid)insert(e[k].l,l,mid,x);
	else insert(e[k].r,mid+1,r,x);
}
int ask(int a,int b,ll l,ll r,ll x)
{
	if(l==r)return sm[b]-sm[a];
	ll mid=l+r>>1;
	if(x<=mid)return ask(e[a].l,e[b].l,l,mid,x);
	return ask(e[a].r,e[b].r,mid+1,r,x);
}
signed main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
//	cout<<sizeof(e)/1024/1024<<"\n";
	int T=read();
	while(T--)
	{
//		if(T%100==0)cerr<<T<<"\n";
		sm.clear();
		int n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		ll mn=1e18,mx=-1e18;
		for(int i=1;i<=n;i++)
		{
			sum[i][0]=sum[i-1][0]+((i&1)?-1:1)*a[i];
			sum[i][1]=sum[i-1][1]+((i&1)?1:-1)*a[i];
			mn=min(mn,sum[i][0]);
			mn=min(mn,sum[i][1]);
			mx=max(mx,sum[i][0]);
			mx=max(mx,sum[i][1]);
		}
		sum[n+1][0]=-1e18;
		sum[n+1][1]=-1e18;
		top[0]=top[1]=0;
		stk[++top[0]][0]=n+1;
		stk[++top[1]][1]=n+1;
			//0/1< 
		for(int i=n;i>=0;i--)
		{
			if(i&1)
			{
				while(sum[i][1]<=sum[stk[top[1]][1]][1])top[1]--;
			}
			else while(sum[i][0]<=sum[stk[top[0]][0]][0])top[0]--;
			to[i][0]=n+1;
			int l=1,r=top[0];
			while(l<=r)
			{
				int mid=l+r>>1;
				if(sum[i][0]>sum[stk[mid][0]][0])to[i][0]=min(to[i][0],stk[mid][0]),l=mid+1;
				else r=mid-1;
			}
			to[i][1]=n+1;
			l=1,r=top[1];
			while(l<=r)
			{
				int mid=l+r>>1;
				if(sum[i][1]>sum[stk[mid][1]][1])to[i][1]=min(to[i][1],stk[mid][1]),l=mid+1;
				else r=mid-1;
			}
//			cout<<to[2][0]<<" "<<to[2][1]<<"\n";
//			to[i][0]=stk[top[0]][0];
//			to[i][1]=stk[top[1]][1];
			if(i&1)stk[++top[1]][1]=i;// 
			else stk[++top[0]][0]=i;
		}
		clear();
		for(int i=1;i<=n;i++)
		{
			t[0].root[i]=t[0].root[i-1];
			t[1].root[i]=t[1].root[i-1];
			if(i&1)
				insert(t[1].root[i],mn,mx,sum[i][1]);// 
			else insert(t[0].root[i],mn,mx,sum[i][0]);
//			if(i%100==0)cout<<i<<"\n";
		}
		ll ans=0;
		for(int i=n-1;i>=0;i--)
		{
//			cout<<to[i][0]<<" "<<to[i][1]<<"\n";
			//l-1 
			int r=min(to[i][0]-1,to[i][1]-1);
			ans+=ask(t[1].root[i],t[1].root[r],mn,mx,sum[i][1]);
			ans+=ask(t[0].root[i],t[0].root[r],mn,mx,sum[i][0]);
//			cout<<i<<" "<<r<<" "<<ans<<"\n";
		}
		cout<<ans<<"\n";
	}
	pc('1',1);
	return 0;
}