#import<bits/stdc++.h>
using namespace std;
int n,m,r,c,v,x;
string s[99];
main()
{
	for(cin>>n;cin>>n>>m>>r>>c;)
	{
		for(int i=1;i<=n;i++)
			cin>>s[i],s[i]=' '+s[i];
		v=x=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				if((i==r||j==c)&&s[i][j]=='B')
					v=1;
				x+=s[i][j]=='B';
			}
		if(!x)
			puts("-1");
		else if(s[r][c]=='B')
			puts("0");
		else if(v)
			puts("1");
		else
			puts("2");
	}
}