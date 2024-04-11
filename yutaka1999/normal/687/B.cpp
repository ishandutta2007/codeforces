#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 1000005

using namespace std;

bool cnt[SIZE];
bool use[SIZE];

int main()
{
	int n,X;
	scanf("%d %d",&n,&X);
	for(int i=0;i<n;i++)
	{
		int c;
		scanf("%d",&c);
		cnt[c]=true;
	}
	for(int j=2;j<SIZE;j++)
	{
		if(use[j]) continue;
		for(int k=j*2;k<SIZE;k+=j) use[k]=false;
		int now=j;
		while(now<SIZE)
		{
			bool up=false;
			for(int k=now;k<SIZE;k+=now) up|=cnt[k];
			if(!up) break;
			if(X%j==0) X/=j;
			if(now>=SIZE/j+1) break;
			now*=j;
		}
		if(X%j==0)
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}