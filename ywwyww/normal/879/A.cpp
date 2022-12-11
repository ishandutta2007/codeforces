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
	int last=0;
	int n;
	scanf("%d",&n);
	int d,s;
	int i;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&s,&d);
		if(s>last)
			last=s;
		else
			last=((last-s+d)/d)*d+s;
	}
	printf("%d\n",last);
	return 0;
}