#include<cstdio>
#include<cstring>
#include<algorithm> 
#define x(i) p[i].first
#define y(i) p[i].second
#define mkp(i,j) make_pair(i,j)
#define maxn 2050
#define modu 998244353
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int n,m;

int mp[maxn][maxn];

pii p[maxn*maxn];

LL ans[maxn][maxn];

bool cmp(pii i,pii j)
{
	return mp[i.first][i.second]<mp[j.first][j.second];
}

LL sq(LL x)
{
	return x*x;
}

LL inv(LL a)
{
	LL ans=1;
	for (int k=modu-2;k;k>>=1)
	{
		if (k&1)
			ans=(ans*a)%modu;
		a=(a*a)%modu;
	}
	return ans;
}

int main()
{
//	freopen("c.in","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
		{
			scanf("%d",&mp[i][j]);
			p[(i-1)*m+j]=mkp(i,j);
		}
	sort(p+1,p+n*m+1,cmp); 
	
	/*for (int i=1;i<=n*m;++i)
		printf("%d ",mp[x(i)][y(i)]);
	putchar('\n');*/
	
//	printf("%lld\n",inv(3)*3%modu);
	LL sx=0,sy=0,sa=0;
	for (int k=1,j=1;k<=n*m;k=j)
	{
//		putchar('\n');
		while (j<=n*m&&mp[x(j)][y(j)]==mp[x(k)][y(k)])	++j;
		if (k==1)
			for (int i=k;i<j;++i)
				ans[x(i)][y(i)]=0;
		else
		{ 
			for (int i=k;i<j;++i)
//				printf("%lld %lld %lld %lld\n",sa,2*sx*x(i),2*sy*y(i),sq(x(i))+sq(y(i))),
//				ans[x(i)][y(i)]=(sa-2*sx*x(i)-2*sy*y(i)+(k-1)*(sq(x(i))+sq(y(i))))*inv(k-1),
				ans[x(i)][y(i)]=(((sa-2*sx*x(i)-2*sy*y(i))%modu*inv(k-1))%modu+sq(x(i))+sq(y(i))+modu)%modu;
//				printf("%d %d %lld\n",x(i),y(i),ans[x(i)][y(i)]); 
		}
		for (int i=k;i<j;++i)
			sx+=x(i),sy+=y(i),sa+=ans[x(i)][y(i)]+sq(x(i))+sq(y(i));
		sx%=modu,sy%=modu,sa%=modu;
		
//		printf("%d %d %lld %lld %lld\n",k,j,sx,sy,sa); 
	}
	
	scanf("%d%d",&n,&m);
	printf("%I64d\n",ans[n][m]); 
	return 0;
}