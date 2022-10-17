#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n,m;
const int xx=1e5+5;
struct node
{
	int sum,l,r;
}e[xx*20];
int root[xx];
int cst;
void insert(int &k,int l,int r,int x)
{
	if(!k)k=++cst;
	int mid=l+r>>1;
	e[k].sum++;
	if(l==r)return;
	if(x<=mid)insert(e[k].l,l,mid,x);
	else insert(e[k].r,mid+1,r,x);
}
int ask(int k,int l,int r,int x)//n+1 
{
	if(x==n+1)return x;
	if(!e[k].sum)return r+1;
//	cout<<l<<" "<<r<<" "<<" "<<e[k].sum<<" "<<k<<" "<<e[k].l<<" "<<e[k].r<<"sss \n";
	if(l==r)return l;
	int mid=l+r>>1;
	if(x>mid)return ask(e[k].r,mid+1,r,x);
	int a=ask(e[k].l,l,mid,x);
	if(a==mid+1)return ask(e[k].r,mid+1,r,x);
	return a;
}
int r[xx];
int minn[xx][20];
vector<int>v[xx];
int ask(int l,int r)
{
	int k=log2(r-l+1);
	return min(minn[l][k],minn[r-(1<<k)+1][k]);
}
int to[xx][20];
signed main(){
//	freopen("a.in","r",stdin);
//	freopen("b.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		int a=read();
		for(int j=2;j*j<=a;j++)
		{
			if(a%j!=0)continue;
			v[i].push_back(j);
			insert(root[j],1,n,i);
//			cout<<j<<" "<<a<<"ss\n";
			while(a%j==0)a/=j;
		}
		if(a!=1)v[i].push_back(a),insert(root[a],1,n,i);
//		puts("");
	}
	memset(minn,0x3f,sizeof(minn));
//		cout<<ask(root[7],1,n,5)<<"\n";
//		return 0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<v[i].size();j++)minn[i][0]=min(minn[i][0],ask(root[v[i][j]],1,n,i+1));
//		puts("");
	}
	for(int j=1;j<=19;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(i+(1<<j-1)<=n)minn[i][j]=min(minn[i][j-1],minn[i+(1<<j-1)][j-1]);
			else minn[i][j]=minn[i][j-1];
		}
	}
	for(int i=1;i<=n;i++)
	{
		int size=1;
		int now=i;
		if(now!=n)
		while(size!=0)
		{
			if(ask(i,min(now+size,n))>min(now+size,n))
			{
				now=now+size,size*=2;
				if(now>=n)
				{
					now=n;break;
				}
			}
			else size/=2;
		}
		to[i][0]=now+1;
//		cout<<i<<" "<<now<<"sss \n";
	}
	to[n+1][0]=n+1;
	for(int j=1;j<=19;j++)
	{
		for(int i=1;i<=n+1;i++)
		{
			to[i][j]=to[to[i][j-1]][j-1];
//			cout<<i<<" "<<j<<" "<<to[i][j]<<"\n";
		}
	}
	
//	return 0;
//	for(int i=1;i<=n;i++)cout<<i<<" "<<minn[i][0]<<"\n";
	for(int i=1;i<=m;i++)
	{
		int l,r;
		l=read();
		r=read();
		int tot=0;
		for(int i=18;i>=0;i--)
		{
			if(to[l][i]<=r)
			{
				l=to[l][i];
				tot+=(1<<i);
			}
		}
		tot++;
		cout<<tot<<"\n";
	}
	return 0;
}