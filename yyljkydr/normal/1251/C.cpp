#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1e3+7;

char s[N];

int cnt[2][N];

vector<int>ans;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans.clear();
		scanf("%s",s);
		int n=strlen(s);
		cnt[0][0]=cnt[1][0]=0;
		for(int i=0;i<n;i++)
		{
			int x=s[i]-'0';
			cnt[x&1][++cnt[x&1][0]]=x;
		} 
		int c1=1,c2=1;
		while(c1<=cnt[0][0]&&c2<=cnt[1][0])
		{
			if(cnt[0][c1]<cnt[1][c2])
				ans.push_back(cnt[0][c1]),c1++;
			else
				ans.push_back(cnt[1][c2]),c2++;
		}
		while(c1<=cnt[0][0])
			ans.push_back(cnt[0][c1]),c1++;
		while(c2<=cnt[1][0])
			ans.push_back(cnt[1][c2]),c2++;
		for(int i=0;i<n;i++)
			printf("%d",ans[i]);
		puts("");
	} 
}