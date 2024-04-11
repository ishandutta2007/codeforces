#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

char a[555][555];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	int l1=11110; int r1=111119; int l2=0; int r2=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='B')
			{
				l1=min(l1,i); r1=min(r1,j);
				l2=max(l2,i); r2=max(r2,j);
			}
		}
	}
	cout<<(l1+l2)/2+1<<' '<<(r1+r2)/2+1<<'\n';
}