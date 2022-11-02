#include<bits/stdc++.h>
using namespace std;
const int D=6,N=100010;
int n,a[N]={},num[N]={},tot=0,top=0,op[N+N]={};
priority_queue<int,vector<int>,greater<int> > q;
int main()
{
	scanf("%d",&n);
	char ch;
	int x;
	for(int i=1;i<=n+n;++i)
	{
		scanf("\n%c",&ch);
		if(ch=='+')
		{
			num[++top]=++tot;
			op[i]=0;
		}
		else
		{
			scanf("%d",&x);
			if(top==0)
			{
				puts("NO");
				return 0;
			}
			a[num[top--]]=x;
			op[i]=x;
		}
	}
	for(int i=1,now=0;i<=n+n;++i)
	{
		if(op[i])
		{
			if(q.top()!=op[i])
			{
				puts("NO");
				return 0;
			}
			q.pop();
		}
		else
			q.push(a[++now]);
	}
	puts("YES");
	for(int i=1;i<=n;++i)
		printf("%d ",a[i]);
}