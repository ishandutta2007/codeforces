#include<bits/stdc++.h>
#define maxn 400050
using namespace std;

int n,m,q;

int fa[maxn];

int find(int i)
{
	return fa[i]?fa[i]=find(fa[i]):i;
}

bool join(int i,int j)
{
	int fi=find(i),fj=find(j);
	if (fi==fj)	return 0;
	fa[fi]=fj;
	return 1;
}

int main()
{
//	freopen("c.in","r",stdin);
	scanf("%d%d%d",&n,&m,&q);
	int ans=n+m-1;
	while (q--)
	{
		int i,j;
		scanf("%d%d",&i,&j);
		j+=n;
		if (join(i,j))
			--ans;
	}
	cout<<ans<<endl;
	return 0;
}