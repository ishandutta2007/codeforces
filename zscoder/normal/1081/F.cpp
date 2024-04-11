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

const int DEBUG=0;
int queries=0;
int hidden[555];
int tmp[555];
int a[555];
int n,t;
int flip(int l, int r)
{
	if(DEBUG)
	{
		queries++;
		if(rand()&1)
		{
			for(int i=0;i<=r;i++) tmp[i]^=1;
			//cerr<<"FLIP "<<0<<' '<<r<<'\n';
		}
		else
		{
			for(int i=l;i<n;i++) tmp[i]^=1;
			//cerr<<"FLIP "<<l<<' '<<n-1<<'\n';
		}
		int as=0;
		for(int i=0;i<n;i++) as+=tmp[i];
		//cerr<<as<<'\n';
		return as;
	}
	cout<<"? "<<l+1<<' '<<r+1<<'\n';
	fflush(stdout);
	int x; cin>>x; return x;
}

int S[555];
int cur;
int getpref(int x) //first x numbers
{
	//x is even, # of numbers is odd
	int ori = cur;
	flip(0,n-1);
	int nw = flip(x+1,n-1);
	if(nw==ori)
	{
		return getpref(x);
	}
	int l = x+1;
	int diff = nw - ori;
	//cerr<<"DIFF : "<<l<<' '<<diff<<'\n';
	int ans = (l-diff)/2;
	while(nw!=ori)
	{
		flip(0,n-1);
		nw = flip(x+1,n-1);
	}
	return ans;
}

const int C = 28;
int getpref2(int x) //x is odd
{
	int ori = cur;
	flip(0,n-1);
	int nw = flip(x+1,n-1);
	int ct = 0;
	while(ct<C&&nw==ori)
	{
		flip(0,n-1);
		nw = flip(x+1,n-1);
		ct++;
	}
	int l = x+1;
	int diff = nw - ori;
	int ans = (l-diff)/2;
	while(nw!=ori)
	{
		flip(0,n-1);
		nw = flip(x+1,n-1);
	}
	return ans;
}

int main()
{
	for(int cc=1;;cc++)
	{
		if(!DEBUG) cin>>n>>t;
		else n=rand()%300+1;
		if(DEBUG)
		{
			t=0;
			for(int i=0;i<n;i++) 
			{
				hidden[i]=rand()&1; tmp[i]=hidden[i]; t+=hidden[i];
				//cerr<<hidden[i];
			}
			//cerr<<'\n';
		}
		cur=t;
		S[n-1]=t;
		queries=0;
		for(int i=0;i<n-1;i+=2)
		{
			S[i] = getpref(i);
		}
		for(int i=1;i<n-1;i+=2)
		{
			S[i] = getpref2(i);
		}
		for(int i=0;i<n;i++)
		{
			a[i]=S[i];
			if(i>0) a[i]-=S[i-1];
		}
		if(!DEBUG)
		{
			cout<<"! ";
			for(int i=0;i<n;i++) cout<<a[i];
			cout<<'\n'; fflush(stdout);
			return 0;
		}
		else
		{
			for(int i=0;i<n;i++)
			{
				assert(a[i]==hidden[i]);
			}
		}
		cerr<<"Case #"<<cc<<" complete\n";
		cerr<<"Q : "<<queries<<'\n';
		assert(queries<=10000);
	}
}