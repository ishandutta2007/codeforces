#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <stack>
#define SIZE 100005

using namespace std;
typedef pair <int,int> P;

stack <P> st;
int in[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&in[i]);
	int ret=0;
	for(int i=n-1;i>=0;i--)
	{
		P now=P(in[i],0);
		while(!st.empty())
		{
			P p=st.top();st.pop();
			if(now.first>p.first) now.second=max(now.second+1,p.second);
			else
			{
				st.push(p);
				break;
			}
		}
		st.push(now);
		ret=max(ret,now.second);
	}
	printf("%d\n",ret);
	return 0;
}