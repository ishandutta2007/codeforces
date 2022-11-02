#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int f[4][2]={{1,1},{1,-1},{-1,1},{-1,-1}};
const int p=1e9+7;
int ksm(int x,int y)
{
	int r=1;
	while (y)
	{
		if (y&1) r=(ll)r*x%p;
		x=(ll)x*x%p;
		y>>=1;
	}
	return r;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while (T--)
	{
		int n,m,x,y,xx,yy,i,j,k,d=0,r=0,q,ans=0,now=1;
		cin>>n>>m>>x>>y>>xx>>yy>>q;q=(ll)q*ksm(100,p-2)%p;
		int dis[n+1][m+1][4];
		memset(dis,0,sizeof dis);
		while (1)
		{
			if (x+f[d][0]<1||x+f[d][0]>n) d^=2;
			if (y+f[d][1]<1||y+f[d][1]>m) d^=1;
			if (dis[x][y][d]) break;
			dis[x][y][d]=++r;
			//cout<<x<<' '<<y<<' '<<d<<' '<<dis[x][y][d]<<endl;
			x+=f[d][0];y+=f[d][1];
		}
		/*for (k=0;k<=3;k++)
		{
			cout<<d[k][0]
			for (i=1;i<=n;i++) for (j=1;j<=m;j++) cout<<dis[i][j][k]<<" \n"[j==m];
		}*/
		vector<int> a;
		for (i=1;i<=n;i++) for (j=1;j<=m;j++) for (k=0;k<=3;k++) if (dis[i][j][k]&&(i==xx||j==yy)) a.push_back(dis[i][j][k]-1);
		assert(a.size());
		sort(all(a));a.resize(unique(all(a))-a.begin());
		for (i=0;i<a.size();i++) ans=(ans+(ll)a[i]*now%p*q)%p,now=(ll)now*(p+1-q)%p;
		ans=(ans+(ll)r*now)%p;
		ans=(ll)ans*ksm((p+1-now)%p,p-2)%p;
		cout<<ans<<'\n';
		cout.flush();
	}
}