#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <deque>
#include <cmath>
#include <string>
#define SIZE 200005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

char S[SIZE];
bool use[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	scanf("%s",&S);
	int d=(n-m)/2;
	for(int i=0;i<n;i++)
	{
		if(S[i]==')')
		{
			if(d>0)
			{
				d--;
				use[i]=true;
			}
		}
	}
	d=(n-m)/2;
	for(int i=n-1;i>=0;i--)
	{
		if(S[i]=='(')
		{
			if(d>0)
			{
				d--;
				use[i]=true;
			}
		}
	}
	for(int i=0;i<n;i++) if(!use[i]) printf("%c",S[i]);
	puts("");
	return 0;
}