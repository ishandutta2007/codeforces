#include<bits/stdc++.h>
#define maxn 605
#define P 251
using namespace std;
typedef long long LL;

int n,m;
char mp[maxn][maxn];

int s[maxn][maxn];

LL F[maxn]={1};
LL H[maxn][maxn];

void init()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<maxn;++i)
		F[i]=F[i-1]*P;
	for (int i=1;i<=n;++i)
	{
		scanf("%s",mp[i]+1);
		for (int j=1;j<=m;++j)
			s[i][j]=s[i][j-1]^(1<<(mp[i][j]-'a')),
			H[i][j]=H[i][j-1]+F[mp[i][j]-'a'];
	}
}

bool check(int s)
{
	return !s||(s==(s&(-s)));
}


int N;
map<LL,int> S;

void clear()
{
	N=0;
	S.clear();
}

int newnode(LL x)
{
	if (!S[x])
		return S[x]=++N;
	return S[x];
}

LL ans=0;

int dp[maxn];
int str[maxn];

void calc()
{
	/*for (int i=0;i<=2*n+2;++i)
		cout<<str[i]<<" ";
	cout<<endl;*/
	
	int p=0,mx=0;
	for (int i=1;i<2*n+2;++i)
	{
		if (!~str[i])	continue;
		
		dp[i]=mx>i?min(dp[2*p-i],mx-i):1;
		while ((~str[i-dp[i]])&&(~str[i+dp[i]])&&str[i-dp[i]]==str[i+dp[i]])
			++dp[i];
		if (mx<i+dp[i])
			mx=i+dp[i],p=i;
		ans+=dp[i]/2;
	}
}

void solve()
{
	str[0]=-2,str[2*n+2]=-3;
	
	for (int l=1;l<=m;++l)
		for (int r=l;r<=m;++r)
		{
//			cout<<l<<" "<<r<<":";
			clear();
			
			for (int i=1;i<=n;++i)
			{
				if (!check(s[i][r]^s[i][l-1]))
					str[i<<1]=-1;
				else
					str[i<<1]=newnode(H[i][r]-H[i][l-1]);
			}
//			cout<<endl;
			
			calc();
		}
	printf("%lld\n",ans);
}

int main()
{
	init();
	solve();
	return 0;
}