#include<bits/stdc++.h>
using namespace std;
int r,c,i,j;
int main(){
	scanf("%d%d",&r,&c);
	if(r==1 && c==1){puts("0");return 0;}
	if(r==1){for(i=1;i<=c;++i)printf("%d ",i+1);return 0;}
	if(c==1){for(i=1;i<=r;++i)printf("%d\n",i+1);return 0;}
	for(i=1;i<=r;++i)for(j=1;j<=c;++j)printf("%d%c",i*(r+j),j==c?'\n':' ');
	return 0;
}