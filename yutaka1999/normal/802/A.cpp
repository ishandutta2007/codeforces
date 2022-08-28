#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#define SIZE 400005

using namespace std;
typedef pair <int,int> P;

int A[SIZE];
int nxt[SIZE];
int last[SIZE];

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
		A[i]--;
	}
	for(int i=0;i<n;i++) last[i]=n;
	for(int i=n-1;i>=0;i--)
	{
		nxt[i]=last[A[i]];
		last[A[i]]=i;
	}
	set <P> st;
	set <P>::iterator it;
	int ret=0;
	for(int i=0;i<n;i++)
	{
		if(st.count(P(i,A[i]))==0)
		{
			ret++;
			if(st.size()==k)
			{
				it=st.end();it--;
				st.erase(it);
			}
		}
		else st.erase(P(i,A[i]));
		st.insert(P(nxt[i],A[i]));
	}
	printf("%d\n",ret);
	return 0;
}