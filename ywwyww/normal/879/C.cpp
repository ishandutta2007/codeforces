#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<cmath>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
void sort(int &a,int &b)
{
	if(a>b)
		swap(a,b);
}
void open(const char *s)
{
#ifndef ONLINE_JUDGE
	char str[100];
	sprintf(str,"%s.in",s);
	freopen(str,"r",stdin);
	sprintf(str,"%s.out",s);
	freopen(str,"w",stdout);
#endif
}
int main()
{
	int n;
	char op[5];
	int x;
	scanf("%d",&n);
	int i;
	int _or=0,_xor=0,_and=1023;
	for(i=1;i<=n;i++)
	{
		scanf("%s%d",op,&x);
		if(op[0]=='^')
		{
			int y;
			y=x&(_or|(1023^_and));
			_or^=y;
			_and^=y;
			x^=y;
			_xor^=x;
		}
		else if(op[0]=='&')
		{
			_or&=x;
			_and&=x;
			_xor&=x;
		}
		else if(op[0]=='|')
		{
			_or|=x;
			_and|=x;
			_xor&=(1023^x);
		}
	}
	printf("3\n& %d\n| %d\n^ %d\n",_and,_or,_xor);
	return 0;
}