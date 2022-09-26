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
typedef pair<int,ii> iii;

map<int,vi> ma;

int c, u;
int apply[200001];
int conn[200001];
int p[200001];
int s[200001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin>>n>>m;
	for(int i = 0; i<n; i++)
	{
		cin>>p[i];
		ma[p[i]].pb(i);
	}
	vector<ii> vec;
	for(int i = 0; i< m;i++)
	{
		cin>>s[i];
		vec.pb(mp(s[i], i));
	}
	sort(vec.begin(),vec.end());
	for(int z = 0; z < m; z++)
	{
		int i = vec[z].se;
		int tmp = s[i];
		int cnt = 0;
		while(tmp >= 1)
		{
			if(!ma[tmp].empty())
			{
				conn[int(ma[tmp].back())] = i + 1;
				apply[i] = cnt;
				ma[tmp].pop_back();
				c++; u += cnt;
				break;				
			}
			if(tmp > 1) tmp = (tmp+1)/2;
			else tmp = 0;
			cnt++;
		}
	}
	cout << c << ' ' << u << '\n';
	//int sum = 0;
	for(int i = 0; i < m; i++)
	{
		cout << apply[i] << ' ';
		//sum += apply[i];
	}
	//assert(sum == u);
	cout << '\n';
	//set<int> s; int tt = 0;
	for(int i = 0; i < n; i++)
	{
		cout << conn[i] << ' ';
		/*
		if(conn[i]!=0) 
		{
			s.insert(conn[i]); tt++;
		}
		*/
	}
	//assert(int(s.size()) == tt);
	//assert(tt == c);
}