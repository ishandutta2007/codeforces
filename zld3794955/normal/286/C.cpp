#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int n,m,p[N]={},s[N]={},top=0;
bool r[N]={};
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&p[i]);
	scanf("%d",&m);
	for(int i=1,x;i<=m;++i)
	{
		scanf("%d",&x);
		r[x]=true;
	}
	for(int i=n;i>=1;--i)
	{
		s[++top]=i;
		if(top>=2 && p[s[top]]==p[s[top-1]] && !r[s[top]])
		{
			r[s[top-1]]=true;
			top-=2;
		}
	}
	if(top)
		puts("NO");
	else
	{
		puts("YES");
		for(int i=1;i<=n;++i)
			printf("%d%c",r[i] ? -p[i] : p[i]," \n"[i==n]);
	}
	return 0;
}