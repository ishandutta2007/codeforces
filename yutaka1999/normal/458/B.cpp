#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define SIZE 100005
#define LIM 1000000000000000LL

using namespace std;
typedef long long int ll;

ll A[SIZE],B[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) scanf("%I64d",&A[i]);
	for(int i=0;i<m;i++) scanf("%I64d",&B[i]);
	sort(A,A+n);
	sort(B,B+m);
	ll S=0;
	for(int i=0;i<n;i++) S+=A[i];
	ll T=0;
	for(int i=0;i<m;i++) T+=B[i];
	ll now=T;
	ll ret=-1;
	for(int i=1;i<=m;i++)
	{
		now-=B[m-i];
		if(S>LIM/i+1) break;
		ll val=S*(ll) i+now;
		if(ret==-1) ret=val;
		else ret=min(ret,val);
	}
	now=S;
	for(int i=1;i<=n;i++)
	{
		now-=A[n-i];
		if(T>LIM/i+1) break;
		ll val=T*(ll) i+now;
		if(ret==-1) ret=val;
		else ret=min(ret,val);
	}
	printf("%I64d\n",ret);
	return 0;
}