#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 1005

using namespace std;

bool ok[SIZE][SIZE];
int id[SIZE];

void add(int a,int b)
{
	ok[a][b]=ok[b][a]=true;
}
int main()
{
	int k;
	scanf("%d",&k);
	int s=0;
	for(int j=1;j<=30;j++)
	{
		add(s,j*3-1);
		add(s,j*3);
		add(j*3-1,j*3+1);
		add(j*3,j*3+1);
		s=j*3+1;
	}s++;
	for(int j=1;j<=80;j++)
	{
		if(j==1) add(1,s);
		else add(s-1,s);
		id[j]=s;
		s++;
	}
	for(int j=0;j<=30;j++)
	{
		if(k>>j&1)
		{
			int st=j==0?0:j*3+1;
			int end=id[70-2*j];
			add(st,end);
		}
	}
	printf("%d\n",s);
	for(int i=0;i<s;i++)
	{
		for(int j=0;j<s;j++) printf(ok[i][j]?"Y":"N");
		puts("");
	}
	return 0;
}