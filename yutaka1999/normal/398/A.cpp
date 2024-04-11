#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 200050
#define INF 100000000000000000LL

using namespace std;
typedef long long int ll;

char str[SIZE];

int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	if(b==0)
	{
		printf("%llld\n",(ll)a*(ll)a);
		for(int i=0;i<a;i++) str[i]='o';
	}
	else if(a==0)
	{
		printf("%llld\n",-(ll)b*(ll) b);
		for(int i=0;i<b;i++) str[i]='x';
	}
	else if(b==1)
	{
		printf("%llld\n",(ll)a*(ll)a-(ll)b*(ll) b);
		for(int i=0;i<a;i++) str[i]='o';
		str[a]='x';
	}
	else
	{
		ll ret=-INF;
		int cnt=0;
		for(int i=2;i<=min(a+1,b);i++)
		{
			ll pl=(ll) (i-2)+(ll) (a-(i-2))*(ll) (a-(i-2));
			int on=b/i,zan=b-on*i;
			ll mn=(ll) on*(ll) on*(ll) (i-zan)+(ll) (on+1)*(ll) (on+1)*(ll) zan;
			ll score=pl-mn;
			if(ret<score)
			{
				ret=score;
				cnt=i;
			}
		}
		printf("%llld\n",ret);
		int on=b/cnt,zan=b-on*cnt;
		int now=0;
		bool up=true;
		int sa=a;
		for(int i=0;i<zan;i++)
		{
			for(int j=0;j<on+1;j++) str[now++]='x';
			if(a>0)
			{
				if(up)
				{
					for(int j=0;j<sa-(cnt-2);j++)
					{
						str[now++]='o';
						a--;
					}
					up=false;
				}
				else
				{
					str[now++]='o';
					a--;
				}
			}
		}
		for(int i=0;i<cnt-zan;i++)
		{
			for(int j=0;j<on;j++) str[now++]='x';
			if(a>0)
			{
				if(up)
				{
					for(int j=0;j<sa-(cnt-2);j++)
					{
						str[now++]='o';
						a--;
					}
					up=false;
				}
				else
				{
					str[now++]='o';
					a--;
				}
			}
		}
	}
	printf("%s\n",str);
	return 0;
}