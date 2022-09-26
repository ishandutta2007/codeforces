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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	string s; cin>>s;
	char a,b; //a(L,R) b(U,D)
	a=b='$';
	int cnt = 1;
	for(int i = 0; i < n; i++)
	{
		if(s[i]=='L')
		{
			if(a=='R')
			{
				cnt++;
				a='L';
				b='$';
			}
			a=s[i];
		}
		else if(s[i]=='R')
		{
			if(a=='L')
			{
				cnt++;
				a='R';
				b='$';
			}
			a=s[i];
		}
		else if(s[i]=='U')
		{
			if(b=='D')
			{
				cnt++;
				b='U';
				a='$';
			}
			b=s[i];
		}
		else
		{
			if(b=='U')
			{
				cnt++;
				b='D';
				a='$';
			}
			b=s[i];
		}
	}
	cout<<cnt;
}