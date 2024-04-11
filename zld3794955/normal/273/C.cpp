#include<bits/stdc++.h>
using namespace std;
const int N=300030;
int n,m,c[N]={},e[N][4]={};
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,a,b;i<=m;++i)
	{
		scanf("%d%d",&a,&b);
		e[a][++*e[a]]=b,e[b][++*e[b]]=a;
	}
	queue<int> q;
	for(int i=1;i<=n;++i)
		q.push(i);
	while(!q.empty())
	{
		int s=q.front(),t=0;
		q.pop();
		for(int i=1;i<=*e[s];++i)
			t+=c[s]==c[e[s][i]];
		if(t>=2)
		{
			c[s]=!c[s];
			for(int i=1;i<=*e[s];++i)
				q.push(e[s][i]);
		}
	}
	for(int i=1;i<=n;++i)
		putchar(c[i]+'0');
	putchar('\n');
	return 0;
}