#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
#define SIZE 100005

using namespace std;

set <int> st;
set <int>::iterator it;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		while(!st.empty())
		{
			it=st.lower_bound(a);
			if(it!=st.end()&&*it==a)
			{
				st.erase(a);
				a++;
			}
			else break;
		}
		st.insert(a);
	}
	int sz=st.size();
	it=st.end();it--;
	int t=*it;
	printf("%d\n",t+1-sz);
	return 0;
}