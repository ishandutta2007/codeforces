#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 100005

using namespace std;
typedef long long int ll;
typedef pair <int,ll> P;

int in[SIZE];
vector <P> vec;

int main()
{
	int n;
	ll k;
	scanf("%d %I64d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",&in[i]);
	sort(in,in+n);
	for(int i=0;i<n;i++)
	{
		if(vec.empty()||vec[vec.size()-1].first!=in[i]) vec.push_back(P(in[i],1));
		else vec[vec.size()-1].second++;
	}
	for(int i=0;i<vec.size();i++)
	{
		P p=vec[i];
		if((ll) p.second*n<k) k-=p.second*n;
		else
		{
			for(int j=0;j<vec.size();j++)
			{
				P q=vec[j];
				k-=p.second*q.second;
				if(k<=0)
				{
					printf("%d %d\n",p.first,q.first);
					break;
				}
			}
			break;
		}
	}
	return 0;
}