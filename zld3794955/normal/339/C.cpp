#include<bits/stdc++.h>
using namespace std;
char ch[15]={};
const int M=1010;
int m,a[M]={},v[M][11][11]={};
void dfs(int t,int d,int l)
{
	if(t>m)
	{
		puts("YES");
		for(int i=1;i<=m;++i)
			cout<<a[i]<<' ';
		cout<<endl;
		exit(0);
	}
	if(v[t][d][l])
		return;
	v[t][d][l]=true;
	for(int i=d+1;i<=10;++i)
		if(ch[i]=='1' && i!=l)
		{
			a[t]=i;
			dfs(t+1,i-d,i);
		}
}
int main()
{
	cin>>(ch+1)>>m;
	dfs(1,0,0);
	puts("NO");
	return 0;
}