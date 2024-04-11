#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=1e5+5,B=300,mod=998244353;
int n,k,a[maxn];
void add(int &x,int y){x=x+y>=mod?x+y-mod:x+y;}
struct blo
{
	int n,tag,mi,mx;
	vector<int>val,cnt,pre;
	void build(int _n){n=_n;val.resize(n);cnt.resize(n);pre.resize(1);}
	void rebuild()
	{
		mi=1e9,mx=0;
		for(int &i:cnt)mi=min(mi,i),mx=max(mx,i);
		pre.clear();pre.resize(mx-mi+1);
		for(int i=0;i<n;i++)::add(pre[cnt[i]-mi],val[i]);
		for(int i=1;i<=mx-mi;i++)::add(pre[i],pre[i-1]);
	}
	void add(int x){tag+=x;}
	void add(int l,int r,int x)
	{
		r=min(r,n-1);
		for(int i=l;i<=r;i++)cnt[i]+=x;
		for(int &i:cnt)i+=tag;
		tag=0;rebuild();
	}
	void chval(int p,int x)
	{
		val[p]=x;
		for(int i=cnt[p]-mi;i<=mx-mi;i++)::add(pre[i],x);
	}
	int query()
	{
		if(pre.empty())return 0;
		if(k<mi+tag)return 0;
		return pre[min((int)pre.size()-1,k-mi-tag)];
	}
}bl[maxn/B+1];
void add(int l,int r,int x)
{
	if(l/B==r/B)bl[l/B].add(l-(l/B)*B,r-(l/B)*B,x);
	else
	{
		int lid=l/B,rid=r/B;
		bl[lid].add(l-lid*B,B,x);
		bl[rid].add(0,r-rid*B,x);
		for(int i=lid+1;i<rid;i++)bl[i].add(x);
	}
}
void chval(int p,int x){bl[p/B].chval(p-(p/B)*B,x);}
int query()
{
	int ret=0;
	for(int i=0;i*B<n;i++)(ret+=bl[i].query())%=mod;
	return ret;
}
int pos[maxn],pre[maxn];
int main()
{
	n=read();k=read();generate_n(a,n,read);
	for(int i=0;i*B<n;i++)bl[i].build(min(B*(i+1),n)-B*i);
	memset(pos,-1,sizeof pos);
	for(int i=0;i<n;i++){pre[i]=pos[a[i]];pos[a[i]]=i;}
	chval(0,1);
	for(int i=0;i<n;i++)
	{
		add(pre[i]+1,i,1);
		if(pre[i]!=-1)add(pre[pre[i]]+1,pre[i],-1);
		int tmp=query();
		if(i+1==n)printf("%d\n",tmp);
		else chval(i+1,tmp);	
	}
	return 0;
}