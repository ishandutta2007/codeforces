#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define SIZE 100005

using namespace std;

int cnt[10];
int f[SIZE],s[SIZE],t[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		cnt[a]++;
	}
	int p=0;
	while(cnt[4]>0)
	{
		cnt[4]--;
		cnt[2]--;
		cnt[1]--;
		f[p]=1;
		s[p]=2;
		t[p]=4;
		p++;
	}
	while(cnt[3]>0)
	{
		cnt[6]--;
		cnt[3]--;
		cnt[1]--;
		f[p]=1;
		s[p]=3;
		t[p]=6;
		p++;
	}
	while(cnt[6]>0)
	{
		cnt[6]--;
		cnt[2]--;
		cnt[1]--;
		f[p]=1;
		s[p]=2;
		t[p]=6;
		p++;
	}
	for(int i=0;i<10;i++)
	{
		if(cnt[i]!=0)
		{
			puts("-1");
			return 0;
		}
	}
	for(int i=0;i<p;i++) printf("%d %d %d\n",f[i],s[i],t[i]);
	return 0;
}