#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define BT (1<<20)+5

using namespace std;
typedef long long int ll;

int cnt[BT];
char str[20];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",&str);
		if(str[0]=='+')
		{
			ll A;
			scanf("%lld",&A);
			int now=0,t=1;
			while(A>0)
			{
				if(A%2==1) now+=t;
				A/=10;
				t<<=1;
			}
			cnt[now]++;
		}
		else if(str[0]=='-')
		{
			ll A;
			scanf("%lld",&A);
			int now=0,t=1;
			while(A>0)
			{
				if(A%2==1) now+=t;
				A/=10;
				t<<=1;
			}
			cnt[now]--;
		}
		else
		{
			scanf("%s",&str);
			int L=strlen(str);
			int now=0;
 			for(int i=0;i<L;i++) if(str[L-i-1]=='1') now|=1<<i;
			printf("%d\n",cnt[now]);
		}
	}
	return 0;
}