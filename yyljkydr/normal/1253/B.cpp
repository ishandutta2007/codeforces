#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int n,a[N];

int cnt,in[N];

vector<int>ans;

set<int>S;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	bool flag=true;
	int last=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>0)
		{
			if(S.find(a[i])!=S.end())
				flag=false;
			else
			{
				S.insert(a[i]);
				in[a[i]]=1;
				cnt++;
			}
		}
		else
		{
			a[i]=-a[i];
			if(!in[a[i]])
				flag=false;
			else
			{
				cnt--;
				in[a[i]]=0;
			}
		}
		if(!cnt)
			ans.push_back(i-last),last=i,S.clear();
	}
	if(cnt)
		flag=false;
	if(!flag)
		puts("-1");
	else
	{
		printf("%d\n",(int)ans.size());
		for(int i=0;i<ans.size();i++)
			printf("%d ",ans[i]);
	}
}