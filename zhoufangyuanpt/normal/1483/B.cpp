#include<cstdio>
#include<cstring>
using namespace std;
int a[110000],l[110000],r[110000];
int list[110000];
inline int gcd(int x,int y){return y==0?x:gcd(y,x%y);}
int Ans[110000],ss;
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<n;i++)r[i]=i+1;
		r[n]=1;
		l[1]=n;
		for(int i=2;i<=n;i++)l[i]=i-1;
		int head=1,tail=1;
		for(int i=2;i<=n+1;i++)
		{
			if(gcd(a[i-1],a[(i-1)%n+1])==1){list[tail++]=(i-1)%n+1;i++;}
		}
		ss=0;
		while(head<tail)
		{
			int x=list[head];
			Ans[++ss]=x;
			if(ss==n)break;
			l[r[x]]=l[x];r[l[x]]=r[x];
			if(list[tail-1]!=l[x]&&gcd(a[l[x]],a[r[x]])==1)list[tail++]=r[x];
			head++;
		}
		printf("%d",ss);
		for(int i=1;i<=ss;i++)printf(" %d",Ans[i]);
		putchar('\n');
	}
	return 0;
}