#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T,n,a[N],s[N];

int b[2];

vector<int>ans;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),s[i]=s[i-1]^a[i];
		if(s[n]!=0)
		{
			puts("NO");
			continue;
		}
		b[0]=b[1]=1;
		for(int i=0;i<=n;i++)
			b[i&1]&=s[i];
		if(b[0]||b[1])
		{
			puts("NO");
			continue;
		}
		puts("YES");
		int p=-1;
		for(int i=1;i<=n;i+=2)
			if(s[i]==0)
				p=i;
		ans.clear();
		for(int i=0;i+3<=p;i+=2)
			ans.push_back(i+1);
		for(int i=p-2;i-3>=0;i-=2)
			ans.push_back(i-2);
		for(int i=p;i+3<=n;i+=2)
			ans.push_back(i+1);
		for(int i=p-1;i+3<=n;i+=2)
			ans.push_back(i+1);
		printf("%d\n",ans.size());
		for(auto x:ans)
			printf("%d ",x);
		puts("");
	}
}