#include<stdio.h>
int a[26],n,cnt=0;char c;
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		while((c=getchar())<'a');a[c-'a']++;
		while(getchar()>='a');
	}
	for(int i=0;i<=25;i++)if(a[i]>=3)cnt+=((a[i]>>1)*(a[i]-2>>1)>>1)+((a[i]+1>>1)*(a[i]-1>>1)>>1);
	printf("%d",cnt);
}