#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define SIZE 100005
#define INF 100000000
#define VL 1.618033988749
#define EPS 1e-8

using namespace std;

char str[SIZE];
int in[SIZE];
int a[SIZE],b[SIZE];

int main()
{
	int la,lb;
	for(int i=0;i<2;i++)
	{
		scanf("%s",&str);
		int len=strlen(str);
		for(int j=0;j<SIZE;j++) in[j]=0;
		for(int j=0;j<len;j++) in[j]=str[len-j-1]=='0'?0:1;
		if(i==0)
		{
			for(int j=0;j<SIZE;j++) a[j]=in[j];
		}
		else
		{
			for(int j=0;j<SIZE;j++) b[j]=in[j];
		}
	}
	for(int i=0;i<SIZE;i++) in[i]=a[i]-b[i];
	for(int i=SIZE-1;i>=2;i--)
	{
		if(in[i]>INF)
		{
			puts(">");
			return 0;
		}
		if(in[i]<-INF)
		{
			puts("<");
			return 0;
		}
		in[i-1]+=in[i];
		in[i-2]+=in[i];
	}
	int f=in[1];
	int s=in[0];
	//printf("%d %d\n",f,s);
	if(f==0&&s==0) puts("=");
	else
	{
		double v=(double) f*VL+(double) s;
		if(v>EPS) puts(">");
		else puts("<");
	}
	return 0;
}