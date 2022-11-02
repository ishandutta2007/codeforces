#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n,a[N]={},tot=0;
bool v[N]={};
void dfs(int s)
{
	v[s]=true;
	if(!v[s*2%n])
		dfs(s*2%n);
	if(!v[s*2%n+1])
		dfs(s*2%n+1);
	a[++tot]=s;
}
int main()
{
	cin>>n;
	if(n%2)
		puts("-1");
	else
	{
		dfs(0);
		for(int i=tot;i>=0;--i)
			printf("%d%c",a[i]," \n"[i==0]);
	}
	return 0;
}