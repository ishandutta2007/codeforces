#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
char gc(){
	char ch=getchar();
	while (ch!='x'&&ch!='.'&&ch!='o')
		ch=getchar();
	return ch;
}
char g[10][10];
int n,m;
int main(){
	for (int i=1;i<=9;i++)
		for (int j=1;j<=9;j++)
			g[i][j]=gc();
	scanf("%d%d",&n,&m);
	n=(n-1)%3,m=(m-1)%3;
	int cnt=0;
	for (int i=1;i<=3;i++)
		for (int j=1;j<=3;j++)
			if (g[i+n*3][j+m*3]=='.'){
				g[i+n*3][j+m*3]='!';
				cnt++;
			}
	if (cnt==0)
		for (int i=1;i<=9;i++)
			for (int j=1;j<=9;j++)
				if (g[i][j]=='.')
					g[i][j]='!';
	for (int i=1;i<=9;i++){
		for (int j=1;j<=9;j++){
			printf("%c",g[i][j]);
			if (j%3==0)
				putchar(' ');
		}
		puts("");
		if (i%3==0)
			puts("");
	}
	return 0;
}