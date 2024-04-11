#include<bits/stdc++.h>
using namespace std;

const int N=5e3+7;

int T,n,f[N][N],a[N];

vector<int>v[2];

int main()
{
	scanf("%d",&n);
	v[0].push_back(0),v[1].push_back(0);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),v[a[i]].push_back(i);
	if(!v[1].size())
	{
		puts("0");
		return 0;
	}
	memset(f,0x3f,sizeof(f));
	for(int j=0;j<v[0].size();j++)
		f[0][j]=0;
	for(int i=1;i<v[1].size();i++)
		for(int j=i;j<v[0].size();j++)
		{
			f[i][j]=min(f[i][j-1],f[i-1][j-1]+abs(v[1][i]-v[0][j]));
		}
	printf("%d\n",f[v[1].size()-1][v[0].size()-1]);
}