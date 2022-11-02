#include<bits/stdc++.h>
#define maxn 1050
using namespace std;

int n,m;
int a[maxn][maxn];

int s[maxn][maxn],l[maxn][maxn];

int main()	{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			scanf("%d",a[i]+j);
	for (int i=1;i<=n;++i)	{
		vector<int> A;
		for (int j=1;j<=m;++j)
			A.push_back(a[i][j]);
		sort(A.begin(),A.end());
		A.resize(unique(A.begin(),A.end())-A.begin());
		for (int j=1;j<=m;++j)	{
			int t=lower_bound(A.begin(),A.end(),a[i][j])-A.begin();
			s[i][j]=max(s[i][j],t);
			l[i][j]=max(l[i][j],(int)A.size()-1-t);
		}
	}
	for (int j=1;j<=m;++j)	{
		vector<int> A;
		for (int i=1;i<=n;++i)
			A.push_back(a[i][j]);
		sort(A.begin(),A.end());
		A.resize(unique(A.begin(),A.end())-A.begin());
		for (int i=1;i<=n;++i)	{
			int t=lower_bound(A.begin(),A.end(),a[i][j])-A.begin();
			s[i][j]=max(s[i][j],t);
			l[i][j]=max(l[i][j],(int)A.size()-1-t);
		}
	}
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			printf("%d%c",l[i][j]+s[i][j]+1," \n"[j==m]); 
	return 0;
}