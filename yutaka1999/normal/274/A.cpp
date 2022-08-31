#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
#define SIZE 100005

using namespace std;
typedef long long int ll;

int in[SIZE];
set <ll> st;

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",&in[i]);
	sort(in,in+n);
	int ret=0;
	for(int i=n-1;i>=0;i--)
	{
		if(!st.count((ll) in[i]*(ll) k))
		{
			st.insert(in[i]);
		}
	}
	printf("%d\n",st.size());
	return 0;
}