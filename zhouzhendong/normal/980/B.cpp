#include <bits/stdc++.h>
using namespace std;
const int N=105;
int n,k;
char s[10][N];
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=4;i++)
		for (int j=1;j<=n;j++)
			s[i][j]='.';
	if (k==1)
		s[2][(n+1)/2]='#';
	else if (k==3)
		s[2][(n+1)/2-1]=s[2][(n+1)/2]=s[2][(n+1)/2+1]='#';
	else {
		for (int i=1;i<=(k+1)/2;i++)
			s[2][i+1]=s[3][i+1]='#';
		if (k%2==1)
			s[3][3]='.';
	}
	
	puts("YES");
	for (int i=1;i<=4;i++)
		puts(s[i]+1);
	return 0;
}