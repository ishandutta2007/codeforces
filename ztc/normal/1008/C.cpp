#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int a[100002],n,cnt=0,i,j=1;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(i=1;;i++)
	{
		do{j++;}while(j<=n&&a[j]<=a[i]);
		if(a[j]>a[i])cnt++;
		if(j>=n)
		{
			printf("%d",cnt);
			return 0;
		}
	}
}