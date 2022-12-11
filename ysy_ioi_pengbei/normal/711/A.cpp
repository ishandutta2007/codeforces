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
int n;
char s[2333][2333];
int main()
{
	scanf("%d",&n);
	bool ok=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s[i]);
		if(!ok&&s[i][0]=='O'&&s[i][1]=='O')
		{
			s[i][0]=s[i][1]='+';
			ok=1;
		}
		if(!ok&&s[i][3]=='O'&&s[i][4]=='O')
		{
			s[i][3]=s[i][4]='+';
			ok=1;
		}
	}
	if(!ok)
	{
	puts("NO");
	return 0;
	}
	puts("YES");
	for(int i=1;i<=n;i++) puts(s[i]);
}