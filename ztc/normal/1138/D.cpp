#include<stdio.h>
int a[2],f[500002],r,n1,n2,i,j;
bool k[500002];
main()
{
	while((r=getchar())>='0')a[r-'0']++,n1++;
	if(r!='\n')while((r=getchar())!='\n');
	while((r=getchar())>='0')k[++n2]=r-'0';
	for(i=2;i<=n2;i++)
	{
		f[i]=f[i-1];
		while(f[i]&&k[f[i]+1]!=k[i])f[i]=f[f[i]];
		f[i]+=(k[f[i]+1]==k[i]);
	}r=0;
	for(i=2;i<=n2;i++)
	{
		while(r&&k[i]!=k[r+1])r=f[r];
		if(k[i]==k[r+1])r++;
	}r=n2-r;
	for(i=1;i<=n1;i++)
	{
		if(++j>r)j-=r;
		if(a[k[j]])printf("%d",k[j]),a[k[j]]--;
		else printf("%d",k[j]^1),a[k[j]^1]--;
	}
}