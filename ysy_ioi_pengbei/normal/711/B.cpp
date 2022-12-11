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
long long s[666][666];
#define QAQ {puts("-1"); return 0;}
int main()
{
	scanf("%d",&n);
	int zx=0,zy=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&s[i][j]);
			if(!s[i][j]) zx=i, zy=j;
		}
	}
	if(n==1)
	{
		puts("1");
		return 0;
	}
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		if(i==zx) continue;
		for(int j=1;j<=n;j++) sum+=s[i][j];
		break;
	}
	long long qaq=sum;
	for(int i=1;i<=n;i++) qaq-=s[zx][i];
	if(qaq<=0) QAQ
	s[zx][zy]=qaq;
	for(int i=1;i<=n;i++)
	{
		ll cur=0;
		for(int j=1;j<=n;j++) cur+=s[i][j];
		if(cur!=sum) QAQ
	}
	for(int i=1;i<=n;i++)
	{
		ll cur=0;
		for(int j=1;j<=n;j++) cur+=s[j][i];
		if(cur!=sum) QAQ
	}
	{
		ll cur=0;
		for(int i=1;i<=n;i++) cur+=s[i][i];
		if(cur!=sum) QAQ
	}
	{
		ll cur=0;
		for(int i=1;i<=n;i++) cur+=s[i][n+1-i];
		if(cur!=sum) QAQ
	}
	printf("%I64d\n",s[zx][zy]);
}