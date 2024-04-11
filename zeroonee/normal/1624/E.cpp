#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
struct Q
{
	int l,r,id;
	Q(){}
	Q(int a,int b,int c):l(a),r(b),id(c){}
};
Q a[2][1000],ans[1003];
char s[1005];
int f[1003],pre[1003];
vector<Q> r;
void dfs(int n)
{
	if (!n) return;
	dfs(pre[n]);
	r.push_back(ans[n]);
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j;
		for (i=0;i<2;i++) for (j=0;j<1000;j++) a[i][j].id=0;
		cin>>m>>n;
		for (i=1;i<=m;i++)
		{
			cin>>s;
			for (j=0;j<n;j++) s[j]-='0';
			for (j=1;j<n;j++) a[0][s[j-1]*10+s[j]]=Q(j-1,j,i);
			for (j=2;j<n;j++) a[1][(s[j-2]*10+s[j-1])*10+s[j]]=Q(j-2,j,i);
		}
		string S;
		cin>>S;
		for (i=1;i<=n;i++) s[i]=S[i-1]-'0';
		memset(f,0,(n+1)*sizeof f[0]);
		f[0]=1;f[0]=1;
		for (i=2;i<=n;i++)
		{
			int x=(s[i-2]*10+s[i-1])*10+s[i];
			int y=s[i-1]*10+s[i];
			if (i>=3&&f[i-3]&&a[1][x].id) f[i]=1,pre[i]=i-3,ans[i]=a[1][x];
			else if (f[i-2]&&a[0][y].id) f[i]=1,pre[i]=i-2,ans[i]=a[0][y];
		}
		if (!f[n]) {cout<<"-1\n";continue;}
		r.clear();dfs(n);
		cout<<r.size()<<'\n';
		for (auto [a,b,c]:r) cout<<a+1<<' '<<b+1<<' '<<c<<'\n';
	//	cout.flush();
	}
}