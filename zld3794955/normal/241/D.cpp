#include<bits/stdc++.h>
using namespace std;
const int N=30;
int n,p,a[N]={},pos[N]={};
void init()
{
	scanf("%d%d",&n,&p);
	int tot=0;
	for(int i=1,x=0;i<=n;++i)
	{
		scanf("%d",&x);
		if(x<=25)
			++tot,a[tot]=x,pos[tot]=i;
	}
	n=tot;
}
void tryy(int t,int s,int s1,int s2)
{
	if(s && s1==0 && s2==0)
	{
		int w[N]={},tot=0;
		for(int i=1;i<=n;++i)
			if(s&(1<<i))
				w[++tot]=pos[i];
		printf("Yes\n%d\n",tot);
		for(int i=1;i<=tot;++i)
			printf("%d%c",w[i]," \n"[i==tot]);
		exit(0);
	}
	if(t>n)
		return;
	tryy(t+1,s,s1,s2);
	tryy(t+1,s|(1<<t),s1^a[t],(s2*(a[t]/10 ? 100 : 10)+a[t])%p);
}
int main()
{
	init();
	tryy(1,0,0,0);
	puts("No");
	return 0;
}