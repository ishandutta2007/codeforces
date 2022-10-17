/*********************************************************************
    > File Name: 1399_D.cpp
    > Author: yuki
 *********************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn=200005;

char s[maxn];
int id[maxn];

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		scanf("%s", s+1);
		for(int i=1; i<=n; i++) id[i]=0;
		stack<int> s0, s1;
		for(int i=1; i<=n; i++)
		{
			if(s[i] == '0')
			{
				if(s1.size() == 0)
					id[i]=s0.size()+1;
				else
				{
					id[i]=s1.top();
					s1.pop();
				}
				s0.push(id[i]);
			}
			if(s[i] == '1')
			{
				if(s0.size() == 0)
					id[i]=s1.size()+1;
				else
				{
					id[i]=s0.top();
					s0.pop();
				}
				s1.push(id[i]);
			}
		}
		int ans=s0.size()+s1.size();
		printf("%d\n", ans);
		for(int i=1; i<n; i++) printf("%d ", id[i]);
		printf("%d\n", id[n]);
	}
	return 0;
}