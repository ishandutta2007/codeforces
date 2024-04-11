#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#define MX 52

using namespace std;
typedef pair <string,string> P;

char pos[60];
int now;

void init()
{
	for(int i=0;i<MX/2;i++) pos[i]='a'+i;
	for(int i=MX/2;i<MX;i++) pos[i]='A'+(i-MX/2);
}
P solve(int n)
{
	if(n==1)
	{
		now=1;
		return P("","a");
	}
	if(n%2==1)
	{
		P p=solve(n/2);
		char c=pos[now++];
		p.first+=c;
		p.first+=c;
		p.second+=c;
		return p;
	}
	else
	{
		P p=solve(n-1);
		char c=pos[now++];
		p.first+=c;
		p.second+=c;
		return p;
	}
}
int main()
{
	init();
	int n;
	scanf("%d",&n);
	P p=solve(n);
	string A=p.second+p.first;
	string B=p.second;
	printf("%s %s\n",A.c_str(),B.c_str());
	return 0;
}