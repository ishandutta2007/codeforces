#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#define SIZE 1024*1024+5

using namespace std;

bool use[SIZE];
stack <int> p,q;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		p.push(a);
		use[a]=true;
		while(!q.empty())
		{
			int f=q.top();q.pop();
			if(a!=(a|f)&&(a|f)!=f)
			{
				a|=f;
				p.push(a);
				use[a]=true;
			}
			else if((a|f)==f)
			{
				q.push(f);
				break;
			}
		}
		while(!p.empty())
		{
			q.push(p.top());
			p.pop();
		}/*
		stack <int> st=q;
		while(!st.empty())
		{
			printf("%d\n",st.top());
			st.pop();
		}printf("\n");*/
	}
	int ret=0;
	for(int i=0;i<SIZE;i++) if(use[i]) ret++;
	printf("%d\n",ret);
	return 0;
}