#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

deque<int> add(deque<int> dq1, deque<int> dq2)
{
	if(dq1.size()>dq2.size()) swap(dq1,dq2);
	deque<int> res(dq2.size());
	while(dq1.size()<dq2.size()) dq1.pb(0);
	for(int i=0;i<res.size();i++)
	{
		res[i]=dq1[i]+dq2[i];
	}
	return res;
}

bool good(deque<int> &res)
{
	for(int i=0;i<res.size();i++)
	{
		if(abs(res[i])>1) return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	deque<int> dq1 = {0,1};
	deque<int> dq2 = {1};
	for(int i=2;i<=n;i++)
	{
		deque<int> tmp = dq1;
		dq1.push_front(0);
		deque<int> res = add(dq1,dq2);
		if(!good(res))
		{
			for(int j=0;j<dq1.size();j++) dq1[j]*=-1;
			res=add(dq1,dq2);
		}
		assert(good(res));
		dq1=res;
		dq2 = tmp;
	}
	if(dq1.back()<0)
	{
		for(int i=0;i<dq1.size();i++) dq1[i]*=-1;
	}
	if(dq2.back()<0)
	{
		for(int i=0;i<dq2.size();i++) dq2[i]*=-1;
	}
	cout<<int(dq1.size())-1<<'\n';
	for(int i=0;i<dq1.size();i++)
	{
		cout<<dq1[i];
		if(i+1<dq1.size()) cout<<' ';
	}
	cout<<'\n';
	cout<<int(dq2.size())-1<<'\n';
	for(int i=0;i<dq2.size();i++)
	{
		cout<<dq2[i];
		if(i+1<dq2.size()) cout<<' ';
	}
	cout<<'\n';
}