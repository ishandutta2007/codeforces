#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
	int l,id;
	node(int nl=0,int nid=0){l=nl;id=nid;}
};
int n,q,cnt=0,ctp[200005],ans[4][200005],seq[3][200005],seq2[4][200005],d[2][200005],x[2][200005],a[200005];
int sp[2][200005],v,u,jc[2];
int st[200005],tp=0;
map<int,int>mp;
map<int,int>::iterator it;
set<int>stp;
set<int>::iterator it2;
vector<node>qu[200005];
vector<int>sv[200005],tk2[200005],tk[200005];
int mx(int x,int y)
{
	if(a[x]>a[y])return x;
	return y;
}
int mi(int x,int y)
{
	if(a[x]<a[y])return x;
	return y;
}
void svp2(int u,int v)
{
	seq2[0][u]=u;seq2[3][u]=v;
	seq2[1][u]=mx(d[1][u],d[0][v]);
	seq2[2][u]=mi(x[1][u],x[0][v]);
	if(seq2[1][u]>seq2[2][u])swap(seq2[1][u],seq2[2][u]);
	tk2[v].push_back(u);
}
void opt(int u,int v,int r)
{
	seq[0][u]=u;seq[1][u]=v;seq[2][u]=r;
	tk[r].push_back(u);
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),mp[a[i]]=0;
	for(it=mp.begin();it!=mp.end();it++)
	{
		cnt++;
		it->second=cnt;
	}
	for(int i=1;i<=n;i++)a[i]=mp[a[i]];
	tp=0;
	for(int i=1;i<=n;i++)
	{
		while(tp&&a[st[tp]]>=a[i])tp--;
		x[0][i]=st[tp];
		st[++tp]=i;
	}
	tp=0;
	for(int i=1;i<=n;i++)
	{
		while(tp&&a[st[tp]]<=a[i])tp--;
		d[0][i]=st[tp];
		st[++tp]=i;
	}
	tp=0;
	st[0]=n+1;
	for(int i=n;i;i--)
	{
		while(tp&&a[st[tp]]>=a[i])tp--;
		x[1][i]=st[tp];
		st[++tp]=i;
	}
	tp=0;
	st[0]=n+1;
	for(int i=n;i;i--)
	{
		while(tp&&a[st[tp]]<=a[i])tp--;
		d[1][i]=st[tp];
		st[++tp]=i;
	}
	for(int i=1;i<=n;i++)
	{
		sp[0][i]=min(d[0][i],x[0][i]);
		sp[1][i]=max(d[1][i],x[1][i]);
		sv[sp[0][i]].push_back(i);
	}
	for(int i=n;i>0;i--)
	{
		for(int j=0;j<sv[i].size();j++)
		{
			v=sv[i][j];
			stp.insert(v);
		}
		it2=stp.lower_bound(sp[1][i]);
		if(it2!=stp.end())svp2(i,*it2);
	}
	for(int i=n;i>0;i--)
	{
		u=x[0][d[0][i]];
		v=d[0][x[0][i]];
		if(max(u,v)<1)continue;
		if(u>v)opt(u,d[0][i],i);
		else opt(v,x[0][i],i);
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&u,&v);
		qu[v].push_back(node(u,i));
	}
	jc[0]=jc[1]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<tk[i].size();j++)jc[0]=max(jc[0],tk[i][j]);
		for(int j=0;j<tk2[i].size();j++)jc[1]=max(jc[1],tk2[i][j]);
		for(int j=0;j<qu[i].size();j++)
		{
			u=qu[i][j].l;v=qu[i][j].id;
			if(jc[1]>=u)
			{
				ctp[v]=4;
				for(int k=0;k<4;k++)ans[k][v]=seq2[k][jc[1]];
			}
			else 
			{
				if(jc[0]>=u)
				{
					ctp[v]=3;
					for(int k=0;k<3;k++)ans[k][v]=seq[k][jc[0]];
				}
				else ctp[v]=0,ans[0][v]=0;
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		printf("%d\n",ctp[i]);
		if(ctp[i]>0)
		{
			for(int j=0;j<ctp[i]-1;j++)printf("%d ",ans[j][i]);
			printf("%d\n",ans[ctp[i]-1][i]);	
		}
	}
	return 0;
	
}