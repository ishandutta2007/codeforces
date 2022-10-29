#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[200][200];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%s",s[i]+1);
	int lx=0,ly=0,rx=0,ry=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(s[i][j]=='B'){
				if(!lx)lx=i;
				rx=i;
				if(!ly)ly=j;
				ry=j;
			}
	printf("%d %d",(lx+rx)/2,(ly+ry)/2);
}