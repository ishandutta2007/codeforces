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
char s[23];
int main()
{
	scanf("%s",s);
	int x=s[0]-'a',y=s[1]-'1';
	int ans=-1;
	for(int i=-1;i<=1;i++)
	{
		for(int j=-1;j<=1;j++)
		{
			int xx=x+i,yy=y+j;
			if(xx>=0&&yy>=0&&xx<8&&yy<8) ++ans;
		}
	}
	printf("%d\n",ans);
}