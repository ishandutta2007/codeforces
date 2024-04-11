#include<bits/stdc++.h>
using namespace std;

const int N=5e5+1e3+7;

int T,n;

set<int>s;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		s.clear();
		scanf("%d",&n);
		int last=0;
		bool ok=1;
		s.insert(-2e9);
		s.insert(2e9);
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			s.insert(x);
			if(i>1&&x!=last)
			{
				auto it=s.lower_bound(last);
				if(last<=x)
					it++;
				else
					it--;
				if(*it!=x)
					ok=0;
			}
			last=x;
		}
		puts(ok?"YES":"NO");
	}
}