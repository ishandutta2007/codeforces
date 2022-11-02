#include<bits/stdc++.h>
using namespace std;
const int N=404,M=404,C=30;
int n,m,q,s[M]={},type[M]={},ps[C][M]={};
char ch[N][M]={};
long long ans=0;
int main()
{	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;++i)
		scanf("\n%s",ch[i]+1);
	for(int i=1;i<=n;++i)
	{
		for(int k=1;k<=m;++k)
			s[k]=ch[i][k]=='a';
		for(int j=i+1;j<=n;++j)
		{
			for(int k=1;k<=m;++k)
				s[k]+=(ch[j][k]=='a');
			for(int k=1;k<=m;++k)
				type[k]=(ch[i][k]==ch[j][k] ? ch[i][k]-'a'+1 : 0);
			int t1[C]={},t2[C]={},ns=0;
			fill(t1,t1+C,1);
			for(int k=1;k<=m;ns+=s[k++])
			{
				int p=type[k];
				if(!p)
					continue;
				ps[p][++t2[p]]=ns;
				while(t1[p]<t2[p] && ps[p][t1[p]]<ns+s[k]-q)
					++t1[p];
				ans+=t2[p]-t1[p];
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}