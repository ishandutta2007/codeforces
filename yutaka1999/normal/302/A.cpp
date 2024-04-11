#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 200005

using namespace std;

int mn=0,one=0;
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		if(a==1) one++;
		else mn++;
	}
	int cnt=min(mn,one);
	for(int i=0;i<m;i++)
	{
		int l,r;
		scanf("%d %d",&l,&r);
		int len=r-l+1;
		if(len%2==1||cnt<len/2) puts("0");
		else puts("1");
	}
	return 0;
}