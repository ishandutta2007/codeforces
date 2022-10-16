#include<cstdio>

using namespace std;

int a[200000];

int main()
{
	int n=0,q=0;scanf("%d%d",&n,&q);int cnt=0;for(int i=1;i<=n;i++)scanf("%d",&a[i]),cnt+=a[i];
	while(q--)
	{
		int op=0,k=0;scanf("%d%d",&op,&k);
		if(op==1){cnt-=a[k];a[k]^=1;cnt+=a[k];}
		else printf("%d\n",(int)k<=cnt);
//		/printf("%d\n",cnt);
	}
}