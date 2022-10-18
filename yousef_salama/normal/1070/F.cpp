#include <bits/stdc++.h>

using namespace std;

vector<int> arr[4];
int n;
char tmp[5];

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf(" %s %d",tmp,&x);
		int v=(tmp[0]-'0')*2+(tmp[1]-'0');
		arr[v].push_back(x);
	}
	for(int i=0;i<4;i++)
	{
		sort(arr[i].rbegin(),arr[i].rend());
	}
	int m=min(arr[1].size(),arr[2].size());
	long long ans=0;
	for(int i=0;i<m;i++)
		ans+=arr[1][i]+arr[2][i];
	for(int i=0;i<arr[3].size();i++)
		ans+=arr[3][i];
	for(int i=min(arr[1].size(),arr[2].size());i<max(arr[1].size(),arr[2].size());i++)
	{
		if(i<arr[1].size()) arr[0].push_back(arr[1][i]);
		if(i<arr[2].size()) arr[0].push_back(arr[2][i]);
	}
	sort(arr[0].rbegin(),arr[0].rend());
	for(int i=0;i<min(arr[0].size(),arr[3].size());i++)
		ans+=arr[0][i];
	printf("%lld\n",ans);
}