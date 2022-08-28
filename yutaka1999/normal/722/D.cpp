#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	set <int> st;
	set <int>::iterator it;
	for(int i=0;i<n;i++)
	{
		int y;
		scanf("%d",&y);
		st.insert(y);
	}
	while(!st.empty())
	{
		it=st.end();it--;
		int v=*it;
		int x=v;
		while(x>0)
		{
			x/=2;
 			if(st.count(x)==0) break;
		}
		if(x==0) break;
		st.erase(v);
		st.insert(x);
	}
	for(it=st.begin();it!=st.end();it++)
	{
		if(it!=st.begin()) printf(" ");
		printf("%d",*it);
	}puts("");
	return 0;
}