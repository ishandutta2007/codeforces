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

struct PBDS
{
	tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> t;
	int timer;
	
	PBDS(){timer = 0;}
	void insert(int x)
	{
		t.insert(mp(x, timer));
		timer++;
	}
	
	int lower(int x)
	{
		return t.order_of_key(ii(x, -1));
	}
	
	void del(int x) //make sure x exists
	{
		ii tmp = (*t.find_by_order(lower(x)));
		t.erase(tmp);
	}
	
	int higher(int x)
	{
		int tmp = lower(x+1);
		return (int(t.size()) - tmp);
	}
};

vector<ii> in[222222];
int special[222222];

class LazySegmentTree {
private:
	int size_;
	vector<long long> v, lazy;
	void update(int a, int b, long long x, int k, int l, int r) {
		push(k, l, r);
		if (r <= a || b <= l) return;
		if (a <= l && r <= b) {
			lazy[k] = x;
			push(k, l, r);
		}
		else {
			update(a, b, x, k * 2, l, (l + r) >> 1);
			update(a, b, x, k * 2 + 1, (l + r) >> 1, r);
			v[k] = merge(v[k * 2], v[k * 2 + 1]);
		}
	}
	long long query(int a, int b, int k, int l, int r) {
		push(k, l, r);
		if (r <= a || b <= l) return ll(1e18);
		if (a <= l && r <= b) return v[k];
		long long lc = query(a, b, k * 2, l, (l + r) >> 1);
		long long rc = query(a, b, k * 2 + 1, (l + r) >> 1, r);
		return merge(lc, rc);
	}
 
public:
	LazySegmentTree() : v(vector<long long>()), lazy(vector<long long>()) {};
	LazySegmentTree(int n) {
		for (size_ = 1; size_ < n;) size_ <<= 1;
		v.resize(size_ * 2,0);
		lazy.resize(size_ * 2,0);
	}
	inline void push(int k, int l, int r) {
		if (lazy[k] != 0) {
			v[k] += lazy[k];
			if (r - l > 1) {
				lazy[k * 2] += lazy[k];
				lazy[k * 2 + 1] += lazy[k];
			}
			lazy[k] = 0;
		}
	}
	inline long long merge(long long x, long long y) {
		return min(x,y);
	}
	inline void update(int l, int r, long long x) {
		update(l, r, x, 1, 0, size_);
	}
	inline long long query(int l, int r) {
		return query(l, r, 1, 0, size_);
	}
};

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	vector<ii> vec;
	for(int i=0;i<n;i++)
	{
		int l,r; cin>>l>>r;
		l--; r--;
		vec.pb({l,r});
		in[l].pb({r,i});
	}
	for(int i=0;i<n;i++)
	{
		sort(in[i].begin(),in[i].end());
	}
	//build the "optimal" solution
	vi p(n,0);
	multiset<ii> M;
	memset(special,-1,sizeof(special));
	for(int i=0;i<n;i++)
	{
		for(ii x:in[i])
		{
			M.insert(x);
		}
		//check for smallest stuff
		assert(!M.empty());
		auto it = M.begin();
		int num = (*it).fi; int id = (*it).se;
		p[id]=i;
		if(M.size()==1) special[i]=num;
		M.erase(M.begin());
	}
	M.clear();
	vi q(n,0);
	bool traitor=0;
	PBDS UNUSED;
	for(int i=0;i<n;i++)
	{
		for(ii x:in[i]) 
		{
			UNUSED.insert(x.fi); 
		}
	}
	map<ii,int> ma;
	int timer=0;
	for(ii x:UNUSED.t)
	{
		ma[x]=timer++;
	}
	LazySegmentTree st(n+10);
	for(auto X:ma)
	{
		st.update(X.se,X.se+1,X.fi.fi-X.se);
		////cerr<<X.fi.fi<<' '<<X.se<<'\n';
	}
	for(int i=0;i<n;i++)
	{
		//now L>=i
		for(ii x:in[i])
		{
			M.insert(x);
		}
		auto it = M.begin();
		int num = (*it).fi; int oriid = (*it).se;
		
		if((!traitor)&&(M.size()>1))
		{
			it++;
			//try to fit this stuff later
			//count number of elements <= num
			/*
			int cntnum = UNUSED.lower(num+1)-(it->fi==num);
			int fit = num-i;
			////cerr<<"HERE "<<cntnum<<' '<<fit<<'\n';
			int cntlarg = UNUSED.higher(it->fi-1)-1;//T.higher(it->fi-1)-1;
			int rem = n - it->fi;
			if(cntnum<=fit&&cntlarg>=rem)
			{
				traitor=1;
				q[it->se]=i;
				UNUSED.del(it->fi);
				M.erase(it);
			}
			else
			{
				M.erase(M.begin());
				UNUSED.del(num);
				q[id]=i;
			}
			*/
			/*
			UNUSED.del(num);
			bool pos=1;
			int mxnum = UNUSED.lower(it->fi+1); //# of numbers <= it->fi
			int lasnum = int(1e9);
			if(mxnum>1) lasnum=(*UNUSED.t.find_by_order(mxnum-2)).fi;
			if(lasnum<i+mxnum)
			{
				pos=0;
			}
			UNUSED.insert(num);
			int special2 = SPECIAL.lower(it->fi);
			int special1 = SPECIAL.lower(num+1);
			if(special1!=special2){pos=0;}
			*/
			int pos1 = UNUSED.lower(num+1);
			bool pos=1;
			////cerr<<num<<' '<<pos1<<'\n';
			if(num<i+pos1-1)
			{
				pos=0;
			}
			//if I remove m2 from the party
			auto val = (*UNUSED.t.lower_bound({it->fi,-110}));
			int id = ma[val];
			////cerr<<"BRUH "<<id<<'\n';
			st.update(id,id+1,ll(1e12));
			st.update(0,id,-1);
			//cerr<<"QUERY: "<<st.query(0,n)<<'\n';
			if(st.query(0,n)<0)
			{
				pos=0;
			}
			if(pos)
			{
				UNUSED.del(it->fi);
				traitor=1;
				q[it->se]=i;
				M.erase(it);
			}
			else
			{
				st.update(id,id+1,-ll(1e12));
				st.update(0,id,1);
				val = (*UNUSED.t.lower_bound({num,-110}));
				id = ma[val];
				st.update(id,id+1,ll(1e12));
				st.update(0,id,-1);
				M.erase(M.begin());
				UNUSED.del(num);
				//cerr<<"ID = "<<i<<'\n';
				q[oriid]=i;
				
			}
		}
		else
		{
			M.erase(M.begin());
			q[oriid]=i;
			auto val = (*UNUSED.t.lower_bound({num,-110}));
			int	id = ma[val];
			st.update(id,id+1,ll(1e12));
			st.update(0,id,-1);
			UNUSED.del(num);
		}
		/*
		for(int j=0;j<n;j++)
		{
			//cerr<<st.query(j,j+1)<<' ';
		}
		//cerr<<'\n';
		*/
	}
	if(!traitor)
	{
		cout<<"YES\n";
		for(int i=0;i<n;i++)
		{
			cout<<p[i]+1;
			if(i+1<n) cout<<' ';
		}
		cout<<'\n';
	}
	else
	{
		cout<<"NO\n";
		for(int i=0;i<n;i++)
		{
			cout<<p[i]+1;
			if(i+1<n) cout<<' ';
		}
		cout<<'\n';
		for(int i=0;i<n;i++)
		{
			cout<<q[i]+1;
			assert(q[i]>=vec[i].fi&&q[i]<=vec[i].se);
			if(i+1<n) cout<<' ';
		}
		cout<<'\n';
	}
}