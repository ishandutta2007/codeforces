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

int A[SIZE],pos[SIZE];
vector <P> ans;

void swp(int s,int t)
{
	swap(A[s],A[t]);
	swap(pos[A[s]],pos[A[t]]);
	ans.push_back(P(s,t));
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
		A[i]--;
		pos[A[i]]=i;
	}
	for(int i=1;i+1<n;i++)
	{
		if(A[i]==i) continue;
		int p=pos[i];
		int to=abs(p-0)>=abs(n-p-1)?0:n-1;
		int back=abs(i-0)>=abs(n-i-1)?0:n-1;
		swp(p,to);
		if(to!=back) swp(to,back);
		swp(i,back);
	}
	if(A[0]!=0) swp(0,n-1);
	//for(int i=0;i<n;i++) printf("%d ",A[i]);puts("");
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first+1,ans[i].second+1);
	return 0;
}