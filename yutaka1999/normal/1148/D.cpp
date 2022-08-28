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

int main()
{
	int n;
	scanf("%d",&n);
	vector <P> up,down;
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		if(a<b)
		{
			up.push_back(P(-b,i));
		}
		else
		{
			down.push_back(P(b,i));
		}
	}
	sort(up.begin(),up.end());
	sort(down.begin(),down.end());
	if(up.size()>=down.size()) swap(down,up);
	printf("%d\n",down.size());
	for(int i=0;i<down.size();i++) printf("%d ",down[i].second+1);puts("");
	return 0;
}