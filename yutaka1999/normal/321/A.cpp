#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define SIZE 105

using namespace std;
typedef long long int ll;

int x[SIZE],y[SIZE];
char in[SIZE];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int a,b;

int tc(char c)
{
	if(c=='U') return 1;
	if(c=='D') return 3;
	if(c=='L') return 2;
	if(c=='R') return 0;
	return -1;
}
bool can(int x,int y,int lx,int ly)
{
	if(lx==0)
	{
		if(x!=a) return false;
	}
	else
	{
		if((a-x)%lx!=0||(a-x)/lx<0) return false;
	}
	if(ly==0)
	{
		if(y!=b) return false;
	}
	else
	{
		if((b-y)%ly!=0||(b-y)/ly<0) return false;
	}
	if((ll) (a-x)*ly!=(ll) (b-y)*lx) return false;
	return true;
}
int main()
{
	scanf("%d %d",&a,&b);
	scanf("%s",&in);
	int sz=strlen(in);
	x[0]=y[0]=0;
	for(int i=0;i<sz;i++)
	{
		int dr=tc(in[i]);
		x[i+1]=x[i]+dx[dr];
		y[i+1]=y[i]+dy[dr];
	}
	int lx=x[sz],ly=y[sz];
	for(int i=0;i<=sz;i++)
	{
		if(can(x[i],y[i],lx,ly))
		{
			puts("Yes");
			return 0;
		}
	}
	puts("No");
	return 0;
}