#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
int n,m;
char buf[33];
bool ok(char s)
{
	return s=='B'||s=='W'||s=='G';
}
int main()
{
	scanf("%d%d",&n,&m);
	bool orz=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%s",buf);
			orz&=ok(buf[0]);
		}
	}
	if(orz) puts("#Black&White");
	else puts("#Color");
}