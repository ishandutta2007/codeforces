#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T;

int n,k;

char s[N];

vector<int>v;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		int ans=0;
		int e=0;
		v.clear();
		for(int i=1,j;i<=n;i=j+1)
		{
			j=i;
			if(s[i]=='W')
			{
				ans+=s[i-1]=='W'?2:1;
				continue;
			}
			while(j+1<=n&&s[j+1]=='L')
				j++;
			if(i==1||j==n)
				e+=j-i+1;
			else
				v.push_back(j-i+1);
		}
		if(!ans)
		{
			printf("%d\n",max(2*k-1,0));
			continue;
		}
		sort(v.begin(),v.end());
		for(int i=0;i<v.size();i++)
		{
			if(!k)
				break;
			int o=min(k,v[i]);
			ans+=o*2;
			if(o==v[i])
				ans++;
			k-=o;
		}
		if(k)
		{
			int o=min(k,e);
			ans+=o*2;
			k-=o;
		}
		printf("%d\n",ans);
	}
}