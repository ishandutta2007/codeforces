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

int cnt[71];
char in[71];
int ma(char c)
{
	if(c>='a'&&c<='z') return c-'a';
	else if(c>='A'&&c<='Z') return c-'A'+26;
	else return c-'0'+52;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	string s; cin>>s;
	vi divisors;
	for(int i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			divisors.pb(i);
			if(i*i!=n) divisors.pb(n/i);
		}
	}
	for(int i=0;i<26;i++)
	{
		in[ma(char('a'+i))]=char('a'+i);
		in[ma(char('A'+i))]=char('A'+i);
		if(i<10) in[ma(char('0'+i))]=char('0'+i);
	}
	
	int cntodd=0;
	for(int i=0;i<n;i++)
	{
		cnt[ma(s[i])]++;
	}
	vi odd;
	for(int i=0;i<70;i++)
	{
		if(cnt[i]&1) 
		{
			odd.pb(i);
			cntodd++;
		}
	}
	vi V;
	for(int i=0;i<odd.size();i++) V.pb(odd[i]);
	for(int i=0;i<70;i++)
	{
		if(cnt[i]%2==0) V.pb(i);
	}
	sort(divisors.begin(),divisors.end());
	for(int i=0;i<divisors.size();i++)
	{
		int d=divisors[i]; int len=n/d;
		//d palindromes 
		if(len%2==0)
		{
			if(cntodd==0)
			{
				vector<string> res;
				for(int k=0;k<d;k++)
				{
					string ans(len,'?');
					int l=0; int r=len-1;
					for(int jj=0;jj<70;jj++)
					{
						int j = V[jj];
						if(l>r) break;
						while(l<r&&cnt[j]>0)
						{
							cnt[j]-=2;
							ans[l]=ans[r]=in[j];
							l++; r--;
						}
					}
					res.pb(ans);
				}
				cout<<d<<'\n';
				for(int i=0;i<d;i++)
				{
					cout<<res[i];
					if(i+1<d) cout<<' ';
				}
				cout<<'\n';
				return 0;
			}
			else continue;
		}
		else
		{
			if(cntodd<=d&&(d-cntodd)%2==0)
			{
				vector<string> res;
				
				for(int k=0;k<d;k++)
				{
					string ans(len,'?');
					res.pb(ans);
				}
				
				for(int k=0;k<odd.size();k++)
				{
					cnt[odd[k]]--;
					res[k][len/2] = in[odd[k]];
				}
				for(int k=odd.size();k<d;k+=2)
				{
					for(int j=0;j<70;j++)
					{
						if(cnt[j]>=2)
						{
							cnt[j]-=2;
							res[k][len/2]=res[k+1][len/2]=in[j];
							break;
						}
					}
				}
				
				for(int k=0;k<d;k++)
				{
					int l=0; int r=len-1;
					for(int jj=0;jj<70;jj++)
					{
						int j = V[jj];
						if(l>r) break;
						while(l<r&&cnt[j]>0)
						{
							cnt[j]-=2;
							res[k][l]=res[k][r]=in[j];
							l++; r--;
						}
					}
				}
				cout<<d<<'\n';
				for(int i=0;i<d;i++)
				{
					cout<<res[i];
					if(i+1<d) cout<<' ';
				}
				cout<<'\n';
				return 0;
			}
			else continue;
		}
	}
}