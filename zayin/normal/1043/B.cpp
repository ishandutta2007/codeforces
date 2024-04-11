#include<bits/stdc++.h>
#define maxn 1050
using namespace std;

int n;
int a[maxn];

vector<int> ans;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for (int i=n;i;--i)
		a[i]-=a[i-1];
	
	for (int len=1;len<=n;++len)
	{
		bool flag=1;	
		for (int i=1;i<=len;++i)
			for (int j=i;j<=n;j+=len)
				if (a[j]!=a[i])
					flag=0;
		if (flag)
			ans.push_back(len);
	} 
	
	cout<<ans.size()<<endl;
	for (auto x:ans)
		cout<<x<<" ";
	return 0;
}