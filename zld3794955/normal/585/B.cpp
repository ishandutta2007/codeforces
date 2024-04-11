#include<bits/stdc++.h>
using namespace std;
const int N=110;
int main()
{	
	int T,n,k;
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		char ch[5][N]={};
		bool b[5][N]={};
		cin>>(ch[1]+1)>>(ch[2]+1)>>(ch[3]+1);
		for(int j=1;j<=3;++j)
			ch[j][n+1]=ch[j][n+2]=ch[j][n+3]='.';
		for(int j=1;j<=3;++j)
			if(ch[j][1]=='s')
				ch[j][1]='.',b[j][1]=true;
		
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=3;++j)
			{
				if(!b[j][i] || ch[j][i]!='.')
					continue;
				if(ch[j][i+1]=='.' && ch[j][i+2]=='.' && ch[j][i+3]=='.')
					b[j][i+3]=true;
				if(ch[j][i+1]=='.' && ch[j-1][i+1]=='.' && ch[j-1][i+2]=='.' && ch[j-1][i+3]=='.')
					b[j-1][i+3]=true;
				if(ch[j][i+1]=='.' && ch[j+1][i+1]=='.' && ch[j+1][i+2]=='.' && ch[j+1][i+3]=='.')
					b[j+1][i+3]=true;
			}
		}
		bool flag=false;
		for(int i=n+1;i<=n+3;++i)
			for(int j=1;j<=3;++j)
				flag|=b[j][i];
		puts(flag ? "YES" : "NO");
	}
	return 0;
}