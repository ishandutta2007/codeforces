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

char S[SIZE],T[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	scanf("%s",&S);
	scanf("%s",&T);
	bool up=false;
	for(int i=0;i<n;i++) if(S[i]=='*') up=true;
	if(!up&&n!=m)
	{
		puts("NO");
		return 0;
	}
	if(up&&n-1>m)
	{
		puts("NO");
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		if(S[i]=='*') break;
		if(i>=m||S[i]!=T[i])
		{
			puts("NO");
			return 0;
		}
	}
	int pos=m-1;
	for(int i=n-1;i>=0;i--)
	{
		if(S[i]=='*') break;
		if(pos<0||S[i]!=T[pos])
		{
			puts("NO");
			return 0;
		}
		pos--;
	}
	puts("YES");
	return 0;
}