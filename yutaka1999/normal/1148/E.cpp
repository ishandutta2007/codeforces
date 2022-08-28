#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <string>
#include <cmath>
#include <cassert>
#define SIZE 300005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
typedef pair <P,int> PP;

P A[SIZE];
int B[SIZE];
P st[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		A[i]=P(x,i);
	}
	for(int i=0;i<n;i++) scanf("%d",&B[i]);
	sort(A,A+n);
	sort(B,B+n);
	vector <PP> ans;
	int sz=0;
	for(int i=0;i<n;i++)
	{
		int f=A[i].first-B[i];
		int v=A[i].second;
		while(sz>0&&f>0)
		{
			P p=st[sz-1];
			int mn=min(p.first,f);
			p.first-=mn;
			f-=mn;
			ans.push_back(PP(P(p.second,v),mn));
			st[sz-1]=p;
			if(p.first==0) sz--;
		}
		if(f>0)
		{
			puts("NO");
			return 0;
		}
		if(f<0) st[sz++]=P(-f,v);
	}
	if(sz>0)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
	{
		P p=ans[i].first;
		printf("%d %d %d\n",p.first+1,p.second+1,ans[i].second);
	}
	return 0;
}