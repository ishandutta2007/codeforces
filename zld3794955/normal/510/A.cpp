#include<bits/stdc++.h>
using namespace std;
const int N=55,M=55;
char ch[N][M]={};
int n,m;
int main()
{	
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		if(i%2)
			for(int j=1;j<=m;++j)
				ch[i][j]='#';
		else
			if(i%4)
				for(int j=1;j<=m;++j)
					ch[i][j]=j==m ? '#' : '.';
			else
				for(int j=1;j<=m;++j)
					ch[i][j]=j==1 ? '#' : '.';
	}
	for(int i=1;i<=n;++i)
		puts(ch[i]+1);
	return 0;
}