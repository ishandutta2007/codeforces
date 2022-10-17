#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T,n;

char s[N];

vector<char>ans;

int c[2];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		int tot=0;
		for(int i=1;i<=n;i++)
			if(s[i]=='1')
				tot++;
		if(s[1]!='1'||s[n]!='1'||tot&1)
		{
			puts("NO");
			continue;
		}
		int now=0;
		ans.clear();
		for(int i=1;i<=n;i++)
			if(s[i]=='1')
			{
				if(now<tot/2)
					ans.push_back('(');
				else
					ans.push_back(')');
				now++;
			}
			else
			{
				if(c[0])
					ans.push_back(')');
				else
					ans.push_back('(');
				c[0]^=1;
			}
		puts("YES");
		for(int i=0;i<ans.size();i++)
				putchar(ans[i]);
		puts("");
		for(int i=0;i<ans.size();i++)
			if(s[i+1]=='1')
				putchar(ans[i]);
			else
				putchar(ans[i]=='('?')':'(');
		puts("");
	}
}