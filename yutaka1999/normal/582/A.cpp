#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <cmath>
#define SIZE 505

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int A[SIZE];

int gcd(int a,int b)
{
	if(a==0) return b;
	return gcd(b%a,a);
}
int main()
{
	int n;
	scanf("%d",&n);
	multiset <int> ml;
	multiset <int>::iterator it;
	for(int i=0;i<n*n;i++)
	{
		int a;
		scanf("%d",&a);
		ml.insert(a);
	}
	vector <int> ans;
	for(int i=0;i<n;i++)
	{
		it=ml.end();it--;
		ans.push_back(*it);
		ml.erase(it);
		for(int j=0;j<i;j++)
		{
			it=ml.lower_bound(gcd(ans[i],ans[j]));
			ml.erase(it);
			it=ml.lower_bound(gcd(ans[i],ans[j]));
			ml.erase(it);
		}
	}
	for(int i=0;i<n;i++)
	{
		if(i!=0) printf(" ");
		printf("%d",ans[i]);
	}puts("");
	return 0;
}