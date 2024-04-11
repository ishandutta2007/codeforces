#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T,n;

char s[N];

vector<int>v;

int main()
{
	// freopen("a.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		v.clear();
		scanf("%d",&n);
		scanf("%s",s+1);
		for(int i=1,j;i<=n;i=j+1)
		{
			j=i;
			while(j+1<=n&&s[j+1]==s[i])
				j++;
			v.push_back(j-i+1);
		}
		reverse(v.begin(),v.end());
		int j=v.size()-1,ans=0;
		while(v.size())
		{
			while(j>=(int)v.size()||(j>=0&&v[j]==1))
				j--;
			if(j<0)
			{
				ans+=(v.size()+1)/2;
				break;
			}
			v[j]--;
			v.pop_back();
			ans++;
		}
		printf("%d\n",ans);
	}
}