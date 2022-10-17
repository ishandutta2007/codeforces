#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 60
using namespace std;

int n,m,p[N],g,ans;

void ask(int now,int l,int r)
{
	int mid=((l+r)>>1),tmp;
	printf("%d\n",mid);fflush(stdout);
	scanf("%d",&tmp);
	if(!tmp) exit(0);
	tmp*=p[(now-1)%n+1];
	if(tmp==1) ask(now+1,mid+1,r);
	else ask(now+1,l,mid-1);
}

int main()
{
	int i,j;
	cin>>m>>n;
	for(i=1;i<=n;i++)
	{
		printf("1\n");fflush(stdout);
		scanf("%d",&p[i]);
		if(!p[i])
			exit(0);
	}
	ask(1,2,m);
}