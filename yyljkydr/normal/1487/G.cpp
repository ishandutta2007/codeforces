#include<bits/stdc++.h>
using namespace std;

#define int long long

typedef long long ll;

const int N=401,P=998244353;

int n,c[26];

ll f[2][N][N][5][5],g[2][N][5][5],h[2][5][5];

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

struct T{
	int tot;
	int i,j;
	int s1,s2;
	T(int _t=0,int _i=0,int _j=0,int _s1=0,int _s2=0){tot=_t,i=_i,j=_j,s1=_s1,s2=_s2;}
};

vector<T>fe[5][5],fg[5][5],fh[5][5];

void inc(ll &a,ll b)
{
	a+=b;
	if(a>=P)
		a-=P;
}

signed main()
{
	scanf("%lld",&n);
	for(int i=0;i<26;i++)
		scanf("%lld",&c[i]);
	for(int i=0;i<=2;i++)
		for(int j=0;j<=(i==2?3:2);j++)
		{
			int cnt[4][4][2][2];
			memset(cnt,0,sizeof(cnt));
			for(int k=0;k<26;k++)
			{
				if(k==i)
					continue;
				int ni=j,nj=k;
				if(j!=0&&j!=1)
					ni=2;
				if(k!=0&&k!=1)
					nj=(j==k||j==0||j==1)?2:3;
				cnt[ni][nj][(nj==0)][(nj==1)]++;
			}
			for(int x=0;x<4;x++)
				for(int y=0;y<4;y++)
					for(int k=0;k<2;k++)
						for(int t=0;t<2;t++)
							if(cnt[x][y][k][t])
								fe[i][j].push_back(T(cnt[x][y][k][t],x,y,k,t));
		}
	for(int i=0;i<=1;i++)
		for(int j=0;j<=(i==1?2:1);j++)
		{
			int cnt[4][4][2];
			memset(cnt,0,sizeof(cnt));
			for(int k=0;k<26;k++)
			{
				if(k==i)
					continue;
				int ni=j,nj=k;
				if(j!=0)
					ni=1;
				if(k!=0)
					nj=j==k||j==0?1:2;
				cnt[ni][nj][nj==0]++;
			}
			for(int x=0;x<4;x++)
				for(int y=0;y<4;y++)
					for(int k=0;k<2;k++)
						if(cnt[x][y][k])
							fg[i][j].push_back(T(cnt[x][y][k],x,y,k));
		}
	for(int i=0;i<=0;i++)
		for(int j=0;j<=1;j++)
		{
			int cnt[4][4];
			memset(cnt,0,sizeof(cnt));
			for(int k=0;k<26;k++)
			{
				if(k==i)
					continue;
				int ni=j,nj=k;
				ni=0;
				nj=j==k?0:1;
				cnt[ni][nj]++;
			}
			for(int x=0;x<2;x++)
				for(int y=0;y<2;y++)
					if(cnt[x][y])
						fh[i][j].push_back(T(cnt[x][y],x,y));
		}
	for(int i=0;i<26;i++)		
		for(int j=0;j<26;j++)
		{
			int ni=(i==0||i==1)?i:2;
			int nj=(j==0||j==1)?j:(j==i||i==0||i==1?2:3);
			f[0][(i==0)+(j==0)][(i==1)+(j==1)][ni][nj]++;
		}
	int now=0,last=1;
	for(int i=3;i<=n;i++)
	{
		swap(now,last);
		memset(f[now],0,sizeof(f[now]));
		for(int c1=0;c1<=i-1;c1++)
			for(int c2=0;c2+c1<=i-1;c2++)
				for(int i=0;i<4;i++)
					for(int j=0;j<4;j++)
						if(f[last][c1][c2][i][j])
						{
							for(auto v:fe[i][j])
								inc(f[now][c1+v.s1][c2+v.s2][v.i][v.j],f[last][c1][c2][i][j]*v.tot%P);
						}
	}
	ll ans=0;
	for(int i=0;i<26;i++)
		for(int j=i+1;j<26;j++)
			for(int c1=c[i]+1;c1<=n;c1++)
				for(int c2=c[j]+1;c2<=n-c1;c2++)
					for(int x=0;x<4;x++)
						for(int y=0;y<4;y++)
							inc(ans,f[now][c1][c2][x][y]);
	for(int i=0;i<26;i++)
		for(int j=0;j<26;j++)
			{
				int ni=(i==0)?i:1;
				int nj=(j==0)?j:(j==i||i==0?1:2);
				g[0][(i==0)+(j==0)][ni][nj]++;
			}
	now=0,last=1;
	for(int i=3;i<=n;i++)
	{
		swap(now,last);
		memset(g[now],0,sizeof(g[now]));
		for(int c1=0;c1<=n;c1++)
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++)
					if(g[last][c1][i][j])
					{
						for(auto v:fg[i][j])
							inc(g[now][c1+v.s1][v.i][v.j],g[last][c1][i][j]*v.tot%P);
					}
	}
	for(int i=0;i<26;i++)
		for(int c1=c[i]+1;c1<=n;c1++)
			for(int x=0;x<3;x++)
				for(int y=0;y<3;y++)
					inc(ans,P-g[now][c1][x][y]);
	for(int i=0;i<26;i++)
		for(int j=0;j<26;j++)
		{
			int ni=0;
			int nj=(j==i)?0:1;
			h[0][ni][nj]++;
		}
	now=0,last=1;
	for(int i=3;i<=n;i++)
	{
		swap(now,last);
		memset(h[now],0,sizeof(h[now]));
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				if(h[last][i][j])
				{
					for(auto v:fh[i][j])
						inc(h[now][v.i][v.j],h[last][i][j]*v.tot%P);
				}
	}
	for(int x=0;x<2;x++)
		for(int y=0;y<2;y++)
			inc(ans,h[now][x][y]);
	printf("%lld\n",ans);
}