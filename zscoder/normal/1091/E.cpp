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
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ll a[555555];
ll suf[555555];
ll pre[555555];

ll P(int id)
{
	if(id<0) return 0;
	return pre[id];
}

ll S(int id)
{
	id=max(id,0);
	return suf[id];
}

int n; 
ll compute_point(int i) //d[0],...,d[i-1] on the left, d[i],....,d[n-1] on the right
{
	ll sum = P(i-1);
	int lo = i; int hi = n - 1;
	int ans = i-1;
	while(lo<=hi)
	{
		int mid=(lo+hi)>>1;
		if(a[mid]>=i)
		{
			ans=mid; lo=mid+1;
		}
		else
		{
			hi=mid-1;
		}
	}
	sum -= S(ans+1);
	sum -= ll(i)*ll(ans+1-i);
	return sum;
}

const int INF = int(1e9);
int t[3][555555*2];

void build(int id) {  // build the tree
  for (int i = n - 1; i > 0; --i) t[id][i] = max(t[id][i<<1], t[id][i<<1|1]);
}

void modify(int id, int p, ll value) {  // set value at position p
	value=max(value,-ll(INF));
  for (t[id][p += n] = value; p > 1; p >>= 1) t[id][p>>1] = max(t[id][p], t[id][p^1]);
}

int query(int id, int l, int r) {  // max on interval [l, r)
	if(l>=r) return -INF;
  int res = -INF;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = max(res, t[id][l++]);
    if (r&1) res = max(res, t[id][--r]);
  }
  return res;
}
int cnt[656666];

vi solve_naive()
{
	vi vec; ll sum=0;
	for(int i=0;i<n;i++) sum+=a[i];
	for(int d=n;d>=0;d--)
	{
		if((sum+d)&1) continue;
		vector<int> nw;
		for(int j=0;j<n;j++) nw.pb(a[j]);
		nw.pb(d);
		sort(nw.rbegin(),nw.rend());
		bool pos=1;
		for(int j=0;j<=n;j++)
		{
			ll sum=0;
			for(int k=0;k<=j;k++)
			{
				sum+=nw[k];
			}
			sum-=ll(j+1)*ll(j);
			for(int k=j+1;k<=n;k++)
			{
				sum-=min(nw[k],j+1);
			}
			if(sum>0){pos=0; break;}
		}
		if(pos) vec.pb(d);
	}
	reverse(vec.begin(),vec.end());
	return vec;
}
const bool DEBUG=0;
struct Fenwick
{
	vector<ll> t;
    Fenwick(int n)
    {
        t.assign(n+111,0);
    }
    void reset(int n)
    {
		t.assign(n+111, 0);
	}
    void update(int p, ll v)
    {
		p++;
        for (; p < (int)t.size(); p += (p&(-p))) t[p] += v;
    }
    ll query(int r) //finds [1, r] sum
    {                     
		r++;
        ll sum = 0;
        for (; r; r -= (r&(-r))) sum += t[r];
        return sum;
    }
};
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	for(int cc=1;;cc++)
	{
		if(!DEBUG) cin>>n;
		else n=rand()%100+1;
		ll sum=0;
		for(int i=0;i<n;i++) 
		{
			if(!DEBUG) cin>>a[i];
			else a[i]=rand()%(n+1);
			sum+=a[i];
		}
		sort(a,a+n);
		reverse(a,a+n);
		memset(suf,0,sizeof(suf)); memset(pre,0,sizeof(pre)); memset(cnt,0,sizeof(cnt));
		for(int i=0;i<n;i++)
		{
			pre[i]=a[i]-2*i;
			if(i>0) pre[i]+=pre[i-1];
		}
		for(int i=n-1;i>=0;i--)
		{
			suf[i]=a[i]+suf[i+1];
		}
		vi vec;
		for(int j=0;j<n;j++)
		{
			ll tmp = min(ll(INF), max(-ll(INF), compute_point(j+1)));
			//cerr<<"COMP "<<j<<" : "<<tmp<<'\n';
			for(int i=0;i<3;i++)
			{
				t[i][j+n]=tmp;
				t[i][j+n]-=i*(j+1);
			}
		}
		/*
		for(int j=0;j<n;j++)
		{
			cout<<t[2][j+n]<<' ';
		}
		cout<<'\n';
		*/
		int C=0;
		Fenwick fen(n+10);
		for(int j=n-1;j>=0;j--)
		{
			t[2][j+n]-=(C-fen.query(j+1));
			C++;
			fen.update(a[j],1);
		}
		/*
		for(int j=0;j<n;j++)
		{
			cout<<t[2][j+n]<<' ';
		}
		cout<<'\n';
		*/
		for(int j=0;j<3;j++)
		{
			build(j);
		}
		int id=0;
		for(int d=n;d>=0;d--)
		{
			if((sum+d)&1) continue;
			id=max(id,0);
			while(id<n&&a[id]>=d) id++;
			id--;
			int mx = -INF;
			mx = max(mx, query(1,0,min(n,min(id,d)+1)));
			//cerr<<d<<' '<<mx<<'\n';
			mx = max(mx, query(0,d,id+1)-d);
			//cerr<<d<<' '<<query(0,d,id+1)-d<<'\n';
			//compute S_d
			{
				ll sum = P(id)+d-2*(id+1);
				//cout<<d<<' '<<id<<' '<<P(id)<<' '<<sum<<'\n';
				int lo = id+1; int hi = n - 1;
				int ans = id;
				while(lo<=hi)
				{
					int mid=(lo+hi)>>1;
					if(a[mid]>=id+2)
					{
						ans=mid; lo=mid+1;
					}
					else
					{
						hi=mid-1;
					}
				}
				sum -= S(ans+1);
				sum -= ll(id+2)*ll(ans+1-(id+1));
				sum = max(sum, -ll(INF));
				sum = min(sum, ll(INF));
				//cerr<<d<<' '<<sum<<'\n';
				mx = max(mx, int(sum));
			}
			mx = max(mx, query(2,id+1,n)+d);
			//cerr<<d<<' '<<query(2,id+1,n)+d<<'\n';
			if(mx<=0) vec.pb(d);
		}
		reverse(vec.begin(),vec.end());
		if(DEBUG)
		{
			vi v2 = solve_naive();
			cerr<<"INTENDED : ";
			for(int v:v2) cerr<<v<<' ';
			cerr<<'\n';
			cerr<<"MY : ";
			for(int v:vec) cerr<<v<<' ';
			cerr<<'\n';
			if(vec!=v2)
			{
				freopen("new-year-estimation.txt","w",stdout);
				cout<<n<<'\n';
				for(int i=0;i<n;i++)
				{
					cout<<a[i]<<' ';
				}
				cout<<'\n'; return 0;
			}
		}
		if(!DEBUG)
		{
			if(vec.empty()) cout<<-1<<'\n';
			else
			{
				for(int i=0;i<vec.size();i++)
				{
					cout<<vec[i];
					if(i+1<vec.size()) cout<<' ';
				}
				cout<<'\n';
			}
			return 0;
		}
		
		cerr<<"Case #"<<cc<<" complete\n";
	}
}