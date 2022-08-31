#include <bits/stdc++.h>
#define SIZE 1005
using namespace std;

int A[SIZE];
bool use[SIZE];
int n;
int MEX()
{
	for(int i=0;i<=n;i++) use[i]=false;
	for(int i=0;i<n;i++) use[A[i]]=true;
	int r=0;
	while(use[r]) r++;
	return r;
}
void solve()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	vector <int> ans;
	while(MEX()<n)
	{
		int p=MEX();
		ans.push_back(p);
		A[p]=p;
	}
	for(int i=0;i<n;i++)
	{
		if(A[i]==i) continue;
		ans.push_back(i);
		A[i]=n;
		while(MEX()<n)
		{
			int p=MEX();
			ans.push_back(p);
			A[p]=p;
		}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++) printf("%d ",ans[i]+1);puts("");
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
}