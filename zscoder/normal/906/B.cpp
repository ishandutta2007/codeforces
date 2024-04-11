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

vector<vi> a;
set<ii> S;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
vector<vi> b;
void init(int n, int m)
{
	b.resize(n);
	for(int i=0;i<n;i++) b[i].resize(m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			b[i][j]=i*m+j+1;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			for(int k=0;k<4;k++)
			{
				int x=i+dx[k]; int y=j+dy[k];
				if(x>=0&&x<n&&y>=0&&y<m)
				{
					S.insert(mp(b[i][j],b[x][y]));
				}
			}
		}
	}
}

void check(int n, int m)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			for(int k=0;k<4;k++)
			{
				int x=i+dx[k]; int y=j+dy[k];
				if(x>=0&&x<n&&y>=0&&y<m)
				{
					if(S.find(mp(a[i][j],a[x][y])) != S.end())
					{
						cerr<<i+1<<' '<<j+1<<' '<<x+1<<' '<<y+1<<'\n';
						assert(0);
					}
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	init(n,m);
	a.resize(n);
	for(int i=0;i<n;i++) a[i].resize(m);
	if(max(n,m)>=4)
	{
		cout<<"YES\n";
		vi vec;
		vi vec2;
		vi vec3;
		vi vec4;
		for(int i=2;i<=n;i+=2) vec.pb(i);
		for(int i=1;i<=n;i+=2) vec.pb(i);
		for(int i=2;i<=m;i+=2) vec2.pb(i);
		for(int i=1;i<=m;i+=2) vec2.pb(i);
		if(m>=4)
		{
			if(m%2==0)
			{
				vec4=vec2; reverse(vec4.begin(),vec4.end());
				vec3=vec; reverse(vec3.begin(),vec3.end());
			}
			else
			{
				for(int i=1;i<=n;i+=2) vec3.pb(i);
				for(int i=2;i<=n;i+=2) vec3.pb(i);
				for(int i=1;i<=m;i+=2) vec4.pb(i);
				for(int i=2;i<=m;i+=2) vec4.pb(i);
			}
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					a[i][j]=i*m+vec2[j];
					cout<<i*m+vec2[j];
					if(j+1<m) cout<<' ';
				}
				swap(vec2,vec4);
				cout<<'\n';
			}
		}
		else
		{
			if(n%2==0)
			{
				vec4=vec2; reverse(vec4.begin(),vec4.end());
				vec3=vec; reverse(vec3.begin(),vec3.end());
			}
			else
			{
				for(int i=1;i<=n;i+=2) vec3.pb(i);
				for(int i=2;i<=n;i+=2) vec3.pb(i);
				for(int i=1;i<=m;i+=2) vec4.pb(i);
				for(int i=2;i<=m;i+=2) vec4.pb(i);
			}
			for(int j=0;j<m;j++)
			{
				for(int i=0;i<n;i++)
				{
					a[i][j] = (vec[i]-1)*m+j+1;
				}
				swap(vec,vec3);
			}
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					cout<<a[i][j];
					if(j+1<m) cout<<' ';
				}
				cout<<'\n';
			}

		}
		check(n,m);
		return 0;
	}	
	if(n==1)
	{
		if(m==1) cout<<"YES\n1\n";
		else cout<<"NO\n";
		check(n,m);
	}
	else if(n==2)
	{
		if(m==1) cout<<"NO\n";
		else if(m==2)
		{
			cout<<"NO\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}
	else
	{
		if(m==1) cout<<"NO\n";
		else if(m==2)
		{
			cout<<"NO\n";
		}
		else
		{
			a={{5,1,7},{3,8,2},{9,4,6}};
			cout<<"YES\n5 1 7\n3 8 2\n9 4 6\n";
			check(n,m);
		}
	}
}