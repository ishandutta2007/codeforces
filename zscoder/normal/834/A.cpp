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

char F[4] = {'v','<','^','>'};
map<int,int> ma;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	char c,d; cin>>c>>d;
	int n; cin>>n;
	for(int i=0;i<4;i++) ma[F[i]]=i;
	n%=4;
	int cw=0;
	int ccw=0;
	{
		char e=c;
		for(int i=0;i<n;i++) 
		{
			int tmp = ma[e];
			tmp++; tmp%=4;
			e=F[tmp];
		}
		if(e==d){cw=1;}
	}
	n=(4000-n)%4;
	{
		char e=c;
		for(int i=0;i<n;i++) 
		{
			int tmp = ma[e];
			tmp++; tmp%=4;
			e=F[tmp];
		}
		if(e==d){ccw=1;}
	}
	if(cw^ccw)
	{
		if(cw) cout<<"cw\n";
		else cout<<"ccw\n";
	}
	else cout<<"undefined\n";
}