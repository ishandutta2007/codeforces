#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 105

using namespace std;

int now[SIZE];
int cur[SIZE];
int gen[SIZE];
int goal[SIZE];
int n;

void move1()
{
	for(int i=0;i<n;i++) cur[gen[i]]=now[i];
	for(int i=0;i<n;i++) now[i]=cur[i];
}
void move2()
{
	for(int i=0;i<n;i++) cur[i]=now[gen[i]];
	for(int i=0;i<n;i++) now[i]=cur[i];
}
void ready()
{
	for(int i=0;i<n;i++) now[i]=i;
}
bool ok()
{
	for(int i=0;i<n;i++)
	{
		if(goal[i]!=now[i]) return false;
	}
	return true;
}
int main()
{
	int k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&gen[i]);
		gen[i]--;
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&goal[i]);
		goal[i]--;
	}
	ready();
	bool up=ok();
	if(up)
	{
		puts("NO");
		return 0;
	}
	ready();
	move1();
	up=!ok();
	ready();
	move2();
	up|=!ok();
	if(!up)
	{
		if(k==1) puts("YES");
		else puts("NO");
		return 0;
	}
	ready();
	for(int i=1;i<=k;i++)
	{
		move1();
		if(ok())
		{
			if((k-i)%2==0)
			{
				puts("YES");
				return 0;
			}
			break;
		}
	}
	ready();
	for(int i=1;i<=k;i++)
	{
		move2();
		if(ok())
		{
			if((k-i)%2==0)
			{
				puts("YES");
				return 0;
			}
			break;
		}
	}
	puts("NO");
	return 0;
}