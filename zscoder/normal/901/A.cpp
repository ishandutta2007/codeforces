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

int a[222222];
int par[411111];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n; n++;
	int cnt=0; 
	for(int i=0;i<n;i++)
	{
		cin>>a[i]; cnt+=a[i];
	}
	for(int i=0;i+1<n;i++)
	{
		if(a[i]>1&&a[i+1]>1)
		{
			cout<<"ambiguous\n";
			par[0] = -1;
			int tmp = 0; int curpar = 0;
			for(int j=1;j<=i;j++)
			{
				for(int k=0;k<a[j];k++)
				{
					par[++tmp] = curpar;
				}
				curpar = tmp;
			}
			//j = i, i + 1
			for(int j=0;j<a[i+1];j++)
			{
				if(j==0) par[++tmp] = curpar-1;
				else par[++tmp] = curpar;
			}
			curpar=tmp;
			for(int j=i+2;j<n;j++)
			{
				for(int k=0;k<a[j];k++)
				{
					par[++tmp] = curpar;
				}
				curpar = tmp;
			}
			for(int j=0;j<cnt;j++)
			{
				cout<<par[j]+1;
				if(j+1<cnt) cout<<' ';
			}
			cout<<'\n';
			memset(par,-1,sizeof(par));

			par[0] = -1;
			tmp = 0; curpar = 0;
			for(int j=1;j<n;j++)
			{
				for(int k=0;k<a[j];k++)
				{
					par[++tmp] = curpar;
				}
				curpar = tmp;
			}
			for(int j=0;j<cnt;j++)
			{
				cout<<par[j]+1;
				if(j+1<cnt) cout<<' ';
			}
			cout<<'\n';
			return 0;
		}
	}
	cout<<"perfect\n";
}