#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
char a[4][4];
int fl,s,x,y,p,q;
int c[4][2]={{0,1},{1,1},{1,0},{1,-1}};
int main(){
	for (int i=0;i<4;i++) scanf("%s",&a[i]);
	fl=0;
	for (int i=0;i<4;i++)
		for (int j=0;j<4;j++)
			for (int k=0;k<4;k++){
				s=0;
				x=i+c[k][0];
				y=j+c[k][1];
				p=x+c[k][0];
				q=y+c[k][1];
				if (p<0||q<0||p>3||q>3) continue;
				if (a[i][j]=='o'||a[x][y]=='o'||a[p][q]=='o') continue;
				if (a[i][j]=='x') s++;
				if (a[p][q]=='x') s++;
				if (a[x][y]=='x') s++;
				if (s==2) fl=1;
			}
	if (fl) printf("YES"); else printf("NO");
	return 0;
}