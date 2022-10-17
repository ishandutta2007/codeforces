#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

set<int>s;

int n,pos[N],now,ans[N],st[N],top;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n*2;i++)
	{
		char op[2];
		scanf("%s",op);
		if(op[0]=='+')
		{
			++now;
			s.insert(now);
		}
		else
		{
			int x;
			scanf("%d",&x);
			while(top&&x>st[top])
				top--;
			int lb=pos[st[top]]+1;
			st[++top]=x;
			auto it=s.lower_bound(lb);
			if(it==s.end())
			{
				puts("NO");
				return 0;
			}
			ans[*it]=x;
			s.erase(it);
			pos[x]=now;
		}
	}
	puts("YES");
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
}