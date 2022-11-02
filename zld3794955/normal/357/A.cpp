#include<iostream>
#include<cstdio>
using namespace std;
int c[101]={},x,y,m,s=0,sum=0;
int main()
{	
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{	
		scanf("%d",&c[i]);
		sum+=c[i];
	}
	scanf("%d%d",&x,&y);
	int i;
	bool b=false;
	for(int i=1;i<=m;++i)
	{	
		s+=c[i];
		if(s>=x && s<=y && sum-s>=x && sum-s<=y)
		{	
			printf("%d\n",i+1);
			b=true;
			break;
		}
	}
	if(!b)
		printf("0\n");
	return 0;
}