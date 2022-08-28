#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long int ll;

char str[11];
int main()
{
	int a,b,m;
	scanf("%d %d %d",&a,&b,&m);
	ll ten=1;
	for(int i=0;i<9;i++)
	{
		ten*=10;
		ten%=m;
	}
	bool up=true;
	for(int i=0;i<=min(a,m);i++)
	{
		ll n=(ten*i)%m;
		if(n!=0&&n<m-b)
		{
			memset(str,0,sizeof(str));
			for(int j=8;j>=0;j--)
			{
				str[j]='0'+(i%10);
				i/=10;
			}
			printf("%d %s\n",1,str);
			up=false;
			break;
		}
	}
	if(up) printf("%d\n",2);
	return 0;
}