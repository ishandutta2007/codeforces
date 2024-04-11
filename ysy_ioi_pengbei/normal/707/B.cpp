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
#define SZ 666666
int n,m,k,va[SZ],vb[SZ],vc[SZ];
bool gg[SZ];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%d%d%d",va+i,vb+i,vc+i);
	for(int i=1;i<=k;i++)
	{
		int x; scanf("%d",&x);
		gg[x]=1;
	}
	int ans=2000000000;
	for(int i=1;i<=m;i++) if(gg[va[i]]+gg[vb[i]]==1)
	ans=min(ans,vc[i]);
	if(ans==2000000000) ans=-1;
	printf("%d\n",ans);
}