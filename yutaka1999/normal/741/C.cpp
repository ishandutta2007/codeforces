#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 200005

using namespace std;

vector <int> vec[SIZE];
int A[SIZE],B[SIZE];
int to[SIZE];
int f[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--,b--;
		vec[a/2].push_back(b/2);
		vec[b/2].push_back(a/2);
		A[i]=a,B[i]=b;
	}
	memset(to,-1,sizeof(to));
	for(int i=0;i<n;i++)
	{
		if(to[i]==-1)
		{
			int now=i;
			while(to[now]==-1)
			{
				int f=vec[now][0];
				if(to[f]!=-1)
				{
					f=vec[now][1];
					if(to[f]!=-1) f=i;
				}
				to[now]=f;
				now=f;
			}
		}
	}/*
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<vec[i].size();j++) printf("%d ",vec[i][j]);puts("");
		printf("%d ",to[i]);puts("");
	}*/
	for(int i=0;i<n;i++)
	{
		if(to[A[i]/2]==B[i]/2)
		{
			if(A[i]/2==B[i]/2||to[B[i]/2]!=A[i]/2) puts("1 2");
			else
			{
				int a=min(A[i],B[i]);
				bool up=f[a/2]==0;
				if(a==A[i]) up=!up;
				if(up) puts("1 2");
				else puts("2 1");
				f[a/2]++;
			}
		}
		else puts("2 1");
	}
	return 0;
}