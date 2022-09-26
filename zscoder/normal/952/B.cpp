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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

bool type2=0;

string query(int n)
{
	cout<<n<<'\n';
	fflush(stdout);
	string s; getline(cin,s);
	if(s!="no")
	{
		if((s[0]=='d'&&s[6]!='e')||s[0]=='c'||s[6]=='d'||(s[0]=='g'&&s[1]=='r'))
		{
			cout<<"normal\n"; fflush(stdout); exit(0);
		}
		else
		{
			cout<<"grumpy\n"; fflush(stdout); exit(0);
		}
	}
	return s;
}
int main()
{
	for(int i=0;i<100000;i++) query(i%10);
	if(type2)
	{
		cout<<"grumpy\n";
	}
	else
	{
		cout<<"normal\n";
	}
	fflush(stdout);
}