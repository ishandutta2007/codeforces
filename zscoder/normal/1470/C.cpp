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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void print(vi a)
{
	vector<ii> vec;
	int curnum=-1; int cnt=0;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]==curnum)
		{
			cnt++;
		}
		else
		{
			if(cnt!=0) vec.pb({curnum,cnt});
			cnt=1;
		}
		curnum=a[i];
	}
	vec.pb({curnum,cnt});
	for(int i=0;i<vec.size();i++)
	{
		ii x=vec[i];
		cout<<"{";
		cout<<x.fi<<","<<x.se<<"}";
		if(i+1<vec.size()) cout<<",";
	}
	cout<<'\n';
}

unordered_map<int,int> ma;
int total_cnt=0;
int n,k; 

vi pass(vi a, bool maintain=0)
{
	ma.clear(); total_cnt=n;
	vi b(a.size(),0);
	for(int i=0;i<a.size();i++)
	{
		if(i==0)
		{
			b[i+1]+=a[i];
		}
		else
		{
			b[i-1]+=a[i]/2;
			b[(i+1)%int(a.size())]+=(a[i]+1)/2;
		}
	}
	if(maintain)
	{
		for(int x:b) 
		{
			if(x!=k) ma[x]++;
			else total_cnt--;
		}
	}
	return b;
}

void simulate(int n, int k)
{
	vi a(n);
	for(int i=0;i<n;i++)
	{
		a[i]=k;
	}
	for(int z=0;z<100;z++)
	{
		
		if(z>=90)
		{
			cout<<"ROUND "<<z<<": ";
			print(a);
		}
		
		int cnt=0;
		for(int x:a)
		{
			if(x==k) cnt++;
		}
		//cerr<<"COUNT "<<z<<": "<<cnt<<"/"<<n<<'\n';
		//vi b=a;
		a=pass(a);
	}
}


int ask(int player)
{
	player%=n;if(player<0) player+=n;
	cout<<"? "<<player+1<<'\n';
	fflush(stdout);
	ll cnt; cin>>cnt;
	return cnt;
}

void answer(int player)
{
	player%=n;if(player<0) player+=n;
	cout<<"! "<<player+1<<'\n';
	fflush(stdout);
}

const int C = 200;

int main()
{
	cin>>n>>k; //assert(n>=4&&k%2==0); simulate(n,k); return 0;
	vi a(n);
	for(int i=0;i<n;i++)
	{
		a[i]=k;
	}
	int lasans=0;
	for(int i=0;i<C;i++)
	{
		lasans=ask(0);
		if(i==C-1) a=pass(a,1);
		else a=pass(a,0);
	}
	int cnt=0;
	//now action starts
	int cur=0;
	int mode=0; //initial mode
	int yolo_size=int(1e9);
	while(1)
	{
		int gap_size = total_cnt/2;
		if(mode==0)
		{
			if(lasans==k)
			{
				cur+=gap_size;
				lasans=ask(cur);
			}
			else if(lasans<k)
			{
				/*
				mode=1;
				yolo_size=gap_size;
				*/
				for(int i=20;i>=0;i--)
				{
					if(gap_size<(1<<i)) continue;
					int res = ask(cur+(1<<i));
					if(res<k)
					{
						cur+=(1<<i);
					}
					else if(res==k)
					{
						answer(cur+(1<<i)); return 0;
					}
					else
					{
						
					}
				}
			}
			else
			{
				for(int i=20;i>=0;i--)
				{
					if(gap_size<(1<<i)) continue;
					int res = ask(cur-(1<<i));
					if(res>k)
					{
						cur-=(1<<i);
					}
					else if(res==k)
					{
						answer(cur-(1<<i)); return 0;
					}
					else
					{
						
					}
				}
			}
		}
		/*
		if(mode==1)
		{
			
		}
		else if(mode==2)
		{
			
		}
		a=pass(a,1);
		*/
	}
}