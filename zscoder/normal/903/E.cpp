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

string a[2511];
string sorted[2511];

bool valid(string &s, string &target)
{
	int cnt[26]; memset(cnt,0,sizeof(cnt));
	for(int i=0;i<s.length();i++) cnt[s[i]-'a']++;
	int dif=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]!=target[i]) dif++;
	}
	if(dif==0)
	{
		for(int i=0;i<26;i++)
		{
			if(cnt[i]>=2) return 1;
		}
		return 0;
	}
	else if(dif==2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k; cin>>k>>n;
	for(int i=0;i<k;i++)
	{
		cin>>a[i];
		sorted[i]=a[i];
		sort(sorted[i].begin(),sorted[i].end());
	}
	for(int i=1;i<k;i++)
	{
		if(sorted[i]!=sorted[i-1])
		{
			cout<<-1<<'\n'; return 0;
		}
	}
	for(int i = 0; i < k; i++)
	{
		if(a[0]!=a[i])
		{
			//solve here
			int diff=0;
			for(int j = 0; j < n; j++)
			{
				if(a[i][j]!=a[0][j])
				{
					diff=j; break;
				}
			}
			for(int j = 0; j < n; j++)
			{
				if(diff==j) continue;
				swap(a[0][j],a[0][diff]);
				bool pos=1;
				for(int z=1;z<k;z++)
				{
					if(!valid(a[z], a[0]))
					{
						//cerr<<j<<' '<<z<<' '<<"INVALID : "<<a[z]<<' '<<a[0]<<'\n';
						pos=0; break;
					}
				}
				if(pos)
				{
					cout<<a[0]<<'\n'; return 0;
				}
				swap(a[0][j],a[0][diff]);
			}
			for(int j = 0; j < n; j++)
			{
				if(diff==j) continue;
				swap(a[i][j],a[i][diff]);
				bool pos=1;
				for(int z=0;z<k;z++)
				{
					if(z==i) continue;
					if(!valid(a[z], a[i]))
					{
						//cerr<<j<<' '<<z<<' '<<"INVALID : "<<a[z]<<' '<<a[i]<<'\n';
						pos=0; break;
					}
				}
				if(pos)
				{
					cout<<a[i]<<'\n'; return 0;
				}
				swap(a[i][j],a[i][diff]);
			}
			cout<<-1<<'\n';
			return 0;
		}
	}
	swap(a[0][0],a[0][1]);
	cout<<a[0]<<'\n';
}