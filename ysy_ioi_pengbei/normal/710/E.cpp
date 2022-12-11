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
ll x,y,dps[23333333];
int dq[23333333],h=0,t=0;
ll f(int i)
{
	return i*2*x+dps[i];
}
int main()
{
	memset(dps,127/3,sizeof(dps));
	cin>>n>>x>>y;
	ll min2=200000000000000000LL;
	dps[0]=0;
	for(int i=0;i<=n;i++)
	{
		if(i>1)
		{
		while(h!=t&&dq[h]<=i/2) ++h;
		while(h!=t&&f(dq[t])>f(i-1)) --t;
		dq[t++]=i-1;
		}
		if(i>0)
		{
		if(i%2==0) dps[i]=min(dps[i],dps[i/2]+y);
		if(i>1) dps[i]=min(dps[i],f(dq[h])-i*x+y);
		dps[i]=min(dps[i],min2+i*x);
		}
		min2=min(min2,-i*x+dps[i]);
	}
	cout<<dps[n]<<"\n";
}