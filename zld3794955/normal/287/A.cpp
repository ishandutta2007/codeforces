#include<bits/stdc++.h>
using namespace std;
char ch[10][10]={};
int main()
{
	cin>>(ch[1]+1)>>(ch[2]+1)>>(ch[3]+1)>>(ch[4]+1);
	for(int i=1;i<=3;++i)
		for(int j=1;j<=3;++j)
			if((ch[i][j]=='.')+(ch[i+1][j]=='.')+(ch[i][j+1]=='.')+(ch[i+1][j+1]=='.')!=2)
			{
				puts("YES");
				return 0;
			}
	puts("NO");
}