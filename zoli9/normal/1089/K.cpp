#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a; i<(b); ++i)
#define trav(a,x) for(auto& a : x)
#define all(x) x.begin, x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

#define TESTING

#ifdef TESTING
#define TO
#else
#define TO if(0)
#endif
int maxn=1000005;

pair<int, ll> inp[300009];
const ll inf=1e18;
struct Node {
	Node *l=0, *r=0;
	long long int lo, hi, mset=inf, madd=0, val=-inf;
	Node(int lo, int hi):lo(lo), hi(hi){}
	Node(vector<ll> &v, int lo, int hi): lo(lo), hi(hi) {
		if(lo+1<hi) {
			int mid=lo+(hi-lo)/2;
			l=new Node(v, lo, mid);
			r=new Node(v, mid, hi);
			val=max(l->val, r->val);
		}
		else val=v[lo];
	}
	ll query(int L, int R) {
		if(R<=lo || hi<=L) return -inf;
		if(L<=lo && hi<=R) return val;
		push();
		return max(l->query(L, R), r->query(L, R));
	}
	void set(int L, int R, int x) {
		if(R<=lo || hi<=L) return;
		if(L<=lo && hi<=R) mset=val=x, madd=0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val=max(l->val, r->val);
		}
	}
	void add(int L, int R, ll x) {
		if(R<=lo || hi<=L) return;
		if(L<=lo && hi<=R) {
			if(mset!=inf) mset+=x;
			else madd+=x;
			val+=x;
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val=max(l->val, r->val);
		}
	}
	void push() {
		if(!l) {
			int mid=lo+(hi-lo)/2;
			l=new Node(lo, mid); r=new Node(mid, hi);
		}
		if(mset!=inf)
			l->set(lo, hi, mset), r->set(lo, hi, mset), mset=inf;
		else if(madd)
			l->add(lo, hi, madd), r->add(lo, hi, madd), madd=0;
	}
};


int q;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	vector<ll> v(maxn);
	for(int i=0; i<maxn; i++)
	{
		v[i]=i;
	}
	Node segtree(v, 0, maxn);
	cin>>q;
	for(int i=1; i<=q; i++)
	{
		char tp;
		cin>>tp;
		if(tp=='+')
		{
			cin>>inp[i].first>>inp[i].second;
			segtree.add(inp[i].first, maxn, -inp[i].second);
		}
		else if(tp=='-')
		{
			int idx;
			cin>>idx;
			segtree.add(inp[idx].first, maxn, inp[idx].second);
		}
		else
		{
			int ti;
			cin>>ti;
			ll maxi=segtree.query(0, ti);
			cout<<maxi+1-segtree.query(ti,ti+1)<<endl;
		}
	}

	return 0;
}