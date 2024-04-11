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
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

string a[100001];
ll score[100001];
ii hashes[100001];
ii revhash[100001];

const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;
const int c = 2017;

ll hsh(string &s, int MOD)
{
	ll cur = 1; ll ans = 0;
	for(int i = 0; i < s.length(); i++)
	{
		ans += (ll(s[i]-'a'+1)*cur)%MOD;
		ans%=MOD;
		cur=(cur*c)%MOD;
	}
	ans%=MOD;
	if(ans<0) ans+=MOD;
	return ans;
}

ll hshmap(ii x)
{
	return (x.fi*(mod2+100)+x.se);
}

map<ll,ll> rever;
map<ll,vi> ma;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k; cin>>n>>k;
	for(int i = 0; i < n; i++)
	{
		cin>>a[i]>>score[i];
		hashes[i]=mp(hsh(a[i],mod1),hsh(a[i],mod2));
		reverse(a[i].begin(),a[i].end());
		revhash[i]=mp(hsh(a[i],mod1),hsh(a[i],mod2));
		ll h1 = hshmap(hashes[i]);
		ll h2 = hshmap(revhash[i]);
		ma[h1].pb(i);
		rever[h1]=h2;
		rever[h2]=h1;
		//cerr<<h1<<' '<<h2<<'\n';
	}
	ll ans = 0;
	vector<ll> best;
	for(map<ll,vi>::iterator it = ma.begin(); it != ma.end(); it++)
	{
		ll rev = rever[it->fi];
		assert(rever[rev]==it->fi);
		if(rev==it->fi)
		{
			vector<ll> tmp;
			for(int i = 0; i < it->se.size(); i++)
			{
				tmp.pb(score[it->se[i]]);
			}
			sort(tmp.begin(),tmp.end());
			for(int i = int(tmp.size()) - 1; i >= 0; i -= 2)
			{
				if(i-1>=0)
				{
					if(tmp[i]>=0&&tmp[i-1]>=0)
					{
						ans+=tmp[i]+tmp[i-1];
					}
					else if(tmp[i]>=0&&tmp[i]+tmp[i-1]>=0)
					{
						best.pb(-tmp[i-1]);
						ans+=tmp[i]+tmp[i-1];
					}
					else if(tmp[i]>=0) best.pb(tmp[i]);
					else break;
				}
				else
				{
					if(tmp[i]>0)
					{
						best.pb(tmp[i]);
					}
				}
			}
		}
		else if(it->fi<rev)
		{
			vector<ll> tmp1,tmp2;
			for(int i = 0; i < it->se.size(); i++)
			{
				tmp1.pb(score[it->se[i]]);
			}
			for(int i = 0; i < ma[rev].size(); i++)
			{
				tmp2.pb(score[ma[rev][i]]);
			}
			sort(tmp1.begin(),tmp1.end());
			sort(tmp2.begin(),tmp2.end());
			reverse(tmp1.begin(),tmp1.end());
			reverse(tmp2.begin(),tmp2.end());
			for(int i = 0; i < min(int(tmp1.size()),int(tmp2.size())); i++)
			{
				if(tmp1[i]+tmp2[i]>0)
				{
					//cerr<<tmp1[i]<<' '<<tmp2[i]<<'\n';
					ans+=tmp1[i]+tmp2[i];
				}
			}
		}
	}
	sort(best.begin(),best.end());
	if(!best.empty()&&best.back()>0) ans+=best.back();
	cout<<ans;
}