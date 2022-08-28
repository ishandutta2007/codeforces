#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <string>
#include <set>
#include <map>
#include <cassert>
#include <cmath>
#define SIZE 100005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int A[SIZE];

int main()
{
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	int ret=n;
	vector <int> vx;
	for(int i=0;i+1<n;i++)
	{
		vx.push_back(A[i+1]-A[i]-1);
	}
	sort(vx.begin(),vx.end());
	for(int i=0;i<n-k;i++)
	{
		ret+=vx[i];
	}
	printf("%d\n",ret);
	return 0;
}