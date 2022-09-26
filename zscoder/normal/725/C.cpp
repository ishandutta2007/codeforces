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

void no(){cout << "Impossible" << endl;}

int pos[26];
char a[2][13];

void out()
{
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 13; j++)
		{
			cout << a[i][j];
		}
		cout<<'\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	cin>>s;
	int l, r;
	memset(pos,-1,sizeof(pos));
	for(int i = 0; i < 27; i++)
	{
		if(pos[s[i]-'A']==-1)
		{
			pos[s[i]-'A'] = i;
		}
		else
		{
			l = pos[s[i]-'A'];
			r = i;
		}
	}
	if(r-l==1)
	{
		no();
		return 0;
	}
	if((r-l)%2==0)
	{
		s += s;
		int pt = (r-l)/2;
		int cur = pt-1; int z = 0;
		for(int i = l; i < r; i++)
		{
			a[z][cur] = s[i];
			if(z==0) cur--;
			else cur++;
			if(cur<0)
			{
				cur=0;
				z = 1;
			}
		}
		cur = pt; z = 0;
		for(int i = r + 1; i <= l + 26; i++)
		{
			a[z][cur] = s[i];
			if(z==0) cur++;
			else cur--;
			if(cur >= 13)
			{
				cur = 12;
				z = 1;
			}
		}	
		out();
		return 0;
	}
	else
	{
		s += s;
		int pt = (r-l)/2 + 1;
		//cerr<<pt<<'\n';
		int cur = pt-1; int z = 0;
		for(int i = l; i < r; i++)
		{
			a[z][cur] = s[i];
			//cerr<<i<<' '<<s[i]<<' '<<z<<' '<<cur<<'\n';
			if(z==0) cur--;
			else cur++;
			if(cur<0)
			{
				cur=0;
				z = 1;
			}
		}
		cur = pt-1; z = 1;
		for(int i = r + 1; i <= l + 26; i++)
		{
			a[z][cur] = s[i];
			if(z==1) cur++;
			else cur--;
			if(cur >= 13)
			{
				cur = 12;
				z = 0;
			}
		}	
		out();
	}
}