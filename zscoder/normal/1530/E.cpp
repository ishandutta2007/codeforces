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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

int cnt[26];

void prt(vector<char> &vec)
{
	for(char c:vec)
	{
		cout<<c;
	}
	cout<<'\n';
}

void solve()
{
	string s; cin>>s; int n=s.length();
	memset(cnt,0,sizeof(cnt));
	for(char c:s) cnt[c-'a']++;
	string t=s;
	sort(t.begin(),t.end());
	if(t[0]==t[n-1])
	{
		cout<<t<<'\n'; return ;
	}
	//else has >= 2 chars
	//if ans can be 0, i.e. exist occur 1x
	vector<char> vec;
	for(int i=0;i<26;i++)
	{
		if(cnt[i]==1)
		{
			vec.pb(i+'a');
			cnt[i]--;
			for(int j=0;j<26;j++)
			{
				for(int k=0;k<cnt[j];k++) vec.pb(j+'a');
			}
			prt(vec); return ;
		}
	}
	//else if the smallest letter can appear twice
	vi tmpcnt(26,0);
	for(int i=0;i<26;i++) tmpcnt[i]=cnt[i];
	for(int i=0;i<26;i++)
	{
		if(cnt[i]>0)
		{
			//try to see if 
			assert(cnt[i]>=2); //else alrdy ended
			cnt[i]-=2;
			vec.pb(i+'a'); vec.pb(i+'a');
			while(vec.size()<n)
			{
				int id=-1;
				for(int j=0;j<26;j++)
				{
					if(cnt[j]>0)
					{
						if(vec.back()==i+'a'&&j==i)
						{
							//no i-is
						}
						else
						{
							id=j; break;
						}
					}
				}
				if(id==-1) break;
				vec.pb(id+'a'); cnt[id]--;
			}
			if(vec.size()==n)
			{
				prt(vec); return ; //we win
			}
			break;
		}
	}
	for(int i=0;i<26;i++) cnt[i]=tmpcnt[i];
	//start with ab
	vec.clear();
	for(int i=0;i<26;i++)
	{
		if(cnt[i]>0)
		{
			//try to see if 
			cnt[i]--;
			vec.pb(i+'a'); 
		}
		if(vec.size()>=2) break;
	}
	//cerr<<vec[0]<<' '<<vec[1]<<'\n';
	while(vec.size()<n)
	{
		int id=-1;
		for(int j=0;j<26;j++)
		{
			if(cnt[j]>0)
			{
				if(vec.back()==vec[0]&&j+'a'==vec[1])
				{
					//no i-js
				}
				else
				{
					if(j+'a'!=vec[0]) //if j is not vec[0], it's safe
					{
						id=j; break;
					}
					else
					{
						//can we put vec[0]?
						if(cnt[vec[1]-'a']==0) //no more 2nd char to spoil
						{
							id=j; break;
						}
						//exist 2nd char
						bool pos=0;
						for(int k=0;k<26;k++)
						{
							if(k+'a'!=vec[0]&&k+'a'!=vec[1]&&cnt[k]>0){pos=1; break;}
						}
						//exist a distinct char
						if(pos)
						{
							id=j; break;
						}
					}
				}
			}
		}
		if(id==-1) break;
		vec.pb(id+'a'); cnt[id]--;
	}
	if(vec.size()==n)
	{
		prt(vec); return ; //we win
	}
	else assert(0);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}