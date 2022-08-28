#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

vector <int> in;

int solve(int n)
{
	int ret=0;
	stack <int> st;
	for(int i=0;i<n;i++)
	{
		while(!st.empty()&&st.top()<in[i])
		{
			ret=max(ret,st.top()^in[i]);
			st.pop();
		}st.push(in[i]);
	}return ret;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		in.push_back(a);
	}
	int ret=solve(n);
	reverse(in.begin(),in.end());
	printf("%d\n",max(solve(n),ret));
	return 0;
}