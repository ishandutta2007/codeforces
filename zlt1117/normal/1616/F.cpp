//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define gc getchar()
#define mk make_pair
#define iter set<int>::iterator
//#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
using namespace std;
char _buf[100000],*_p1=_buf,*_p2=_buf;
inline int gi()
{
	int x=0,f=1;
	char ch=gc;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=gc;
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=gc;
	}
	return (f==1)?x:-x;
}
const int maxn=5005,maxm=5005;
int a[maxm][maxm];
int n,m,cnt,tot,M;
int sum[maxm];
int id[maxn],u[maxn],v[maxn],w[maxn],bel[maxn],ans[maxn];
inline void guess(int n,int m)
{
	int p=1;
	FOR(i,1,n)
	{
//		printf("%d\n",i);
//		FOR(j,1,m)
//		{
//			FOR(k,1,n)printf("%d ",(int)a[j][k]);
//			printf("%d ",sum[j]);
//			puts("");
//		}
		if(p==m+1)
		{
			FOR(j,1,n)ans[j]=3;p=m;
			for(int j=p;j>=1;--j)
			{
				ans[bel[j]]=sum[j];
				for(int k=j-1;k>=1;--k)
				{
					sum[k]=(sum[k]+9-sum[j]*a[k][bel[j]])%3;
				}
			}
			FOR(j,1,M)
			{
				if(ans[id[j]]==0)ans[id[j]]=3;
				if(!id[j])printf("%d ",w[j]);
				else printf("%d ",ans[id[j]]);
			}
			puts("");
			return ;
		}
		int now=p;
		FOR(j,p,m)if(a[j][i]!=0){now=j;break;}
		if(now!=p)swap(a[p],a[now]),swap(sum[p],sum[now]);
		if(a[p][i]==0)continue;
		if(a[p][i]==2){FOR(j,i,n)a[p][j]=2*a[p][j]%3;sum[p]=2*sum[p]%3;}
		FOR(j,p+1,m)
		{
			if(a[j][i])
			{
				int v=a[j][i];
				FOR(k,i,n)a[j][k]-=v*a[p][k],a[j][k]=(a[j][k]+9)%3;
				sum[j]=(sum[j]+9-v*sum[p])%3;
			}
		}
//		printf("%d\n",i);
//		FOR(j,1,m)
//		{
//			FOR(k,1,n)printf("%d ",(int)a[j][k]);
//			printf("%d ",sum[j]);
//			puts("");
//		}
		bel[p]=i;p++;
	}
	FOR(j,p,m)
	{
		if(sum[j]!=0)return puts("-1"),void();
	}
	FOR(j,1,n)ans[j]=3;
	for(int j=p-1;j>=1;--j)
	{
		ans[bel[j]]=sum[j];
		for(int k=j-1;k>=1;--k)
		{
			sum[k]=(sum[k]+9-a[k][bel[j]]*sum[j])%3;
		}
	}
	FOR(j,1,M)
	{
		if(ans[id[j]]==0)ans[id[j]]=3;
		if(!id[j])printf("%d ",w[j]);
		else printf("%d ",ans[id[j]]);
	}
	puts("");
}
int cid[maxn][maxn];
inline void init()
{
	memset(bel,0,sizeof(bel));
	FOR(i,1,tot)memset(a[i],0,sizeof(a[i]));
	n=m=tot=M=cnt=0;
	memset(sum,0,sizeof(sum));
	memset(ans,0,sizeof(ans));
	memset(id,0,sizeof(id));
	memset(cid,0,sizeof(cid));
}
inline void input()
{
	n=gi(),m=gi();M=m;
	FOR(i,1,m)
	{
		u[i]=gi(),v[i]=gi(),w[i]=gi();
		if(u[i]>v[i])swap(u[i],v[i]);
		cid[u[i]][v[i]]=i;
		cid[v[i]][u[i]]=i;
		if(w[i]==-1)id[i]=++tot;
	}
}
inline void solve()
{
	FOR(i,1,m)FOR(j,i+1,m)
	{
		int k=0;
		if(u[i]==u[j])k=cid[v[i]][v[j]];
		if(u[i]==v[j])k=cid[v[i]][u[j]];
		if(v[i]==u[j])k=cid[u[i]][v[j]];
		if(v[i]==v[j])k=cid[u[i]][u[j]];
		if(k<j)continue;
		vector<int>vec={u[i],v[i],u[j],v[j],u[k],v[k]};
		sort(vec.begin(),vec.end());vec.resize(unique(vec.begin(),vec.end())-vec.begin());
		if(sz(vec)==3)
		{
			++cnt;
			if(w[i]==-1)a[cnt][id[i]]=1;
			else sum[cnt]=(sum[cnt]+3-w[i])%3;
			if(w[j]==-1)a[cnt][id[j]]=1;
			else sum[cnt]=(sum[cnt]+3-w[j])%3;
			if(w[k]==-1)a[cnt][id[k]]=1;
			else sum[cnt]=(sum[cnt]+3-w[k])%3;
		}
	}
	guess(tot,cnt);
}
int main()
{
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	int T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}