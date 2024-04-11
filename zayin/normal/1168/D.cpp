#include<bits/stdc++.h>
#define maxc 27
#define maxn 150050
using namespace std;
typedef long long LL;

int n,m;

int up[maxn];
char s[10];

int fa[maxn];
int dep[maxn],D;
vector<int> G[maxn];

bool fake[maxn];
int sum[maxn],len[maxn];
int dp[maxn][maxc],cnt[maxn][maxc];

int chr(int i)	{
	return i=='?'?26:i-'a';
}

void init()	{
	scanf("%d%d",&n,&m);
	for (int i=2;i<=n;++i)	{
		scanf("%d%s",fa+i,s);
		up[i]=chr(*s);
		G[fa[i]].push_back(i);
		dep[i]=dep[fa[i]]+1;
	}
}


int tp[maxn];

bool judge()	{
	D=-1;
	for (int i=1;i<=n;++i)	{
		if (G[i].size())	continue;
		if (~D&&dep[i]!=D)	return 0;
		D=dep[i];
	}
	return 1;
} 

void modify(int i,int c,int d)	{
	if (c==26)	return ;
	cnt[i=tp[i]][c]+=d;
	for (i=tp[fa[i]];i;i=tp[fa[i]])	{
		assert(G[i].size()==2);
		int ls=G[i][0],rs=G[i][1];
		sum[i]-=dp[i][c];
		dp[i][c]=max(dp[ls][c]+cnt[ls][c],dp[rs][c]+cnt[rs][c]);
		sum[i]+=dp[i][c];
		fake[i]=fake[ls]|fake[rs]|(sum[i]>D-dep[i]);
	}
}

void solve()	{
	tp[1]=1;
	for (int i=2;i<=n;++i)	{
		if (G[fa[i]].size()==1)
			tp[i]=tp[fa[i]],++len[tp[i]],dep[tp[i]]=dep[i];
		else
			tp[i]=i;
//		cout<<i<<" "<<tp[i]<<endl;
	}
	for (int i=1;i<=n;++i)	G[i].clear();
	for (int i=2;i<=n;++i)	
		if (tp[i]==i)
			G[tp[fa[i]]].push_back(i);
	
	for (int i=2;i<=n;++i)	modify(i,up[i],1);
	
	while (m--)	{
//		cout<<"----------------"<<endl;
		
		int i;
		scanf("%d%s",&i,s);
		
		modify(i,up[i],-1);
		modify(i,up[i]=chr(*s),1);
		
		/*for (int i=1;i<=n;++i)
			if (i==tp[i])	{
				cout<<i<<"("<<sum[i]<<","<<dep[i]<<"):";
				for (int c=0;c<maxc;++c)
					cout<<dp[i][c]<<" ";
				cout<<endl;
			}*/
		
		if (fake[1])
			puts("Fou");
		else	{
			LL ans=0,s=D-sum[1];
			for (int c=0;c<26;++c)
				s-=cnt[1][c];
			for (int c=0;c<26;++c)
				ans+=(s+dp[1][c]+cnt[1][c])*(c+1);
			printf("Shi %lld\n",ans);
		}
	}
}

int main()	{
	init();
	if (!judge())
		while (m--)	puts("Fou");
	else
		solve();
	return 0;
}