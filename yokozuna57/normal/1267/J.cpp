#include <bits/stdc++.h>
#define SIZE 2000005
using namespace std;

int cnt[SIZE];

void solve()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int c;
		scanf("%d",&c);c--;
		cnt[c]++;
	}
	vector <int> vx;
	for(int i=0;i<n;i++)
	{
		if(cnt[i]>0)
		{
			vx.push_back(cnt[i]);
			cnt[i]=0;
		}
	}
	sort(vx.begin(),vx.end());
	for(int i=vx[0]+1;i>=0;i--)
	{
		bool up=true;
		int sum=0;
		for(int j=0;j<vx.size();j++)
		{
			int c=vx[j]/i,zan=vx[j]%i;
			if(zan==0) sum+=c;
			else
			{
				if(zan+c>=i-1) sum+=c+1;
				else up=false;
			}
		}
		if(up)
		{
			printf("%d\n",sum);
			break;
		}
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}