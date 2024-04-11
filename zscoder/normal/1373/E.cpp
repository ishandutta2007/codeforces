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
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

string getmin(const string &a, const string &b)
{
	if(b=="-1") return a;
	if(a=="-1") return b;
	if(a.length()!=b.length())
	{
		if(a.length()<b.length()) return a;
		else return b;
	}
	if(a<b) return a;
	else return b;
}

string solve1(int n) //S(x) = n
{
	if(n<0) return "-1";
	if(n==0) return "";
	if(n<=9) return string(1,'0'+n);
	string ans;
	while(n>=9)
	{
		ans+=string(1,'9');
		n-=9;
	}
	if(n>0) ans+=string(1,'0'+n);
	reverse(ans.begin(),ans.end());
	return ans;
}

string dp[13][13][222];

string solve2(int a, int b, int n) //aS(x)+bS(x+1)=n
{
	if(dp[a][b][n]!="-2") return dp[a][b][n];
	if(n==b) return (dp[a][b][n]="");
	string s="-1";
	for(int d=0;d<=8;d++)
	{
		int newsum = n-(a*d)-(b*(d+1));
		if(newsum>=0&&newsum%(a+b)==0)
		{
			string tmp = solve1(newsum/(a+b));
			s=getmin(s,tmp+string(1,'0'+d));
		}
	}
	//choose 9
	int newsum = n-(a*9);
	if(newsum>=0)
	{
		string tmp = solve2(a,b,newsum);
		if(tmp!="-1")
		{
			s=getmin(s,tmp+"9");
		}
	}
	return (dp[a][b][n]=s);
}

void solve()
{
	int n,k; cin>>n>>k;
	if(n==(k*(k+1))/2)
	{
		cout<<0<<'\n'; return ;
	}
	string s = "-1";
	for(int d=0;d<=9;d++)
	{
		int newsum = n;
		int cnt[2] = {0,0};
		for(int j=0;j<=k;j++)
		{
			if(d+j>=10)
			{
				cnt[1]++;
			}
			else
			{
				cnt[0]++;
			}
			newsum-=(d+j)%10;
		}
		//cerr<<d<<' '<<newsum<<'\n';
		if(newsum>=0)
		{
			string tmp = solve2(cnt[0],cnt[1],newsum);
			if(tmp!="-1")
			{
				s=getmin(s,tmp+string(1,'0'+d));
			}
		}
	}
	cout<<s<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	for(int i=0;i<13;i++)
	{
		for(int j=0;j<13;j++)
		{
			for(int k=0;k<222;k++) dp[i][j][k]="-2";
		}
	}
	int t; cin>>t;
	while(t--) solve();
}