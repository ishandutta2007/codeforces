#include <cstdio>
int a[4][11];
char s[4];
int main()
{
	for(int i=1; i<=3; ++i) scanf("%s", s), ++a[s[1]=='m'?1:s[1]=='p'?2:3][s[0]-'0'];
	for(int i=1; i<=3; ++i) for(int j=1; j<=9; ++j)
	{
		if(a[i][j]==3) return puts("0"), 0;
	}
	for(int i=1; i<=3; ++i) for(int j=1; j<=7; ++j)
	{
		if((a[i][j]>0)+(a[i][j+1]>0)+(a[i][j+2]>0)>2) return puts("0"), 0;
	}
	for(int i=1; i<=3; ++i) for(int j=1; j<=9; ++j)
	{
		if(a[i][j]==2) return puts("1"), 0;
	}
	for(int i=1; i<=3; ++i) for(int j=1; j<=7; ++j)
	{
		if((a[i][j]>0)+(a[i][j+1]>0)+(a[i][j+2]>0)>1) return puts("1"), 0;
	}
	puts("2");
	return 0;
}