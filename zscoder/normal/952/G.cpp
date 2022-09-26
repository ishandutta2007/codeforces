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

const int N = 500;
char a[N+1][N+1];

void minu(int &cur)
{
	cur=(cur+255)%256;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin>>s;
	//freopen("puzzle.out","w",stdout);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			a[i][j]='.';
		}
	}
	int cur = 0;
	int curx=1; int cury=1;
	for(int i=0;i<s.length();i++)
	{
		do
		{
			cury+=2;
			if(cury>=N)
			{
				cury=1; curx+=2;
			}
			a[curx][cury]='X'; minu(cur);
		}while(cur!=int(s[i]));
		curx++;
		a[curx][cury]='X';
		curx+=2;
		cury=1;
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout<<a[i][j];
		}
		cout<<'\n';
	}
}