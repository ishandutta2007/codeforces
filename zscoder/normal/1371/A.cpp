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
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

//Disclaimer: This code is a result of a challenge by MGod for me to solve this round using "his" new "language": Flirt++
//This code is totally not representative of anything happening irl and is just for meme purposes.

//Riajuu Template (incomplete)

#define gf first
#define bf second
#define waifu first
#define spare second
#define in_a_relationship make_pair
#define add_to_harem push_back
#define add_to_friend_list push_back
#define add_to_plan push_back
#define remove_from_plan pop_back
#define give_up_chase return 
#define giveMGod return
#define wan 1
#define with +
#define without - 
#define self_multiplied 2*
#define split_into_two /2
#define next ++
#define rejected return false
#define accepted return true
#define initialize_playboy_mode ios_base::sync_with_stdio(0);
#define search_for_new_girls cin.tie(0);
#define single int
#define mgod main
#define ConfessionResult bool
#define couple pair<ll,ll>
#define couples vector<couple>
#define messed_up cout << -1 << endl;
#define reject cout<<"NO\n"
#define accept cout<<"YES\n"
#define learn_about cin >>
#define move_on_to_next_girl number_of_girls--;
#define confess sweettalk
#define end_up_being_single_anyway return 0;
#define i_only_chase_one_girl number_of_girls = 1;
#define leader rt
#define todolist vector<int>
#define skill void

void think(ll x)
{
	cerr<<x<<'\n';
}
void think(string x)
{
	cerr<<x<<'\n';
}
void think(ld x)
{
	cerr<<fixed<<setprecision(12)<<x<<'\n';
}
void think(const vector<int> &vec)
{
	for(int i=0;i<vec.size();i++)
	{
		cerr<<vec[i];
		if(i+1<vec.size()) cerr<<' ';
	}
	cerr<<'\n';
}

void sweettalk(ll x)
{
	cout<<x<<'\n';
}

void sweettalk(string x)
{
	cout<<x<<'\n';
}

void sweettalk(const vector<int> &vec)
{
	for(int i=0;i<vec.size();i++)
	{
		cout<<vec[i];
		if(i+1<vec.size()) cout<<' ';
	}
	cout<<'\n';
}

const int MASHIRO = 1e9+7;
const int RIO = 998244353;

vector<int> fact;
vector<int> ifact;
vector<int> inv;
vector<int> pow2;

int add(int a, int b)
{
	a+=b;
	while(a>=MASHIRO) a-=MASHIRO;
	return a;
}
void direct_add(int &a, int b)
{
	a=add(a,b); 
}
int multiply(int a, int b)
{
	return (a*1LL*b)%MASHIRO;
}
void direct_multiply(int &a, int b)
{
	a=multiply(a,b);
}
int ascension(int a, int b)
{
	int r=1;
	while(b)
	{
		if(b&1) r=multiply(r,a);
		a=multiply(a,a);
		b>>=1;
	}
	return r;
}
int ways_to_choose_girls(int a, int b)
{
	if(a<b) return 0;
	if(b==0) return 1;
	if(a==b) return 1;
	return multiply(fact[a],multiply(ifact[b],ifact[a-b]));
}
int inverse(int a)
{
	return ascension(a,MASHIRO-2);
}
void initialize_counting_protocol(int _n)
{
	fact.clear(); ifact.clear(); inv.clear(); pow2.clear();
	fact.resize(_n+1);
	ifact.resize(_n+1);
	inv.resize(_n+1);
	pow2.resize(_n+1);
	pow2[0]=1;
	ifact[0]=1;
	fact[0]=1;
	for(int i=1;i<=_n;i++)
	{
		pow2[i]=add(pow2[i-1],pow2[i-1]);
		fact[i]=multiply(fact[i-1],i);
		//ifact[i]=mult(ifact[i-1],inv[i]);
	}
	ifact[_n] = inverse(fact[_n]);
	for(int i=_n-1;i>=1;i--)
	{
		ifact[i] = multiply(ifact[i + 1], i + 1);
	}
	for(int i=1;i<=_n;i++)
	{
		inv[i] = multiply(fact[i-1],ifact[i]);
	}
}

struct Family
{
	int S;
	
	struct person
	{
		int p; ll sum;
	};
	vector<person> ship;
	
	Family(int n)
	{
		S = n;
		for(int i = 0; i < n; i++)
		{
			person tmp;
			tmp.p = i; tmp.sum = 0;
			ship.pb(tmp);
		}
	}
	
	void reset(int n)
	{
		ship.clear();
		S = n;
		for(int i = 0; i < n; i++)
		{
			person tmp;
			tmp.p = i; tmp.sum = 0;
			ship.pb(tmp);
		}
	}
	
	int rt(int u)
	{
		if(ship[u].p == u) return u;
		ship[u].p = rt(ship[u].p);
		return ship[u].p;
	}
	
	void unify(int u, int v)
	{
		u = rt(u); v = rt(v);
		if(u == v) return ;
		if(rand()&1) swap(u, v);
		ship[v].p = u;
		ship[u].sum += ship[v].sum;
	}
	
	bool married(int u, int v)
	{
		if(rt(u) == rt(v)) return true;
		return false;
	}
	
	ll family_size(int u)
	{
		return ship[rt(u)].sum;
	}
};

skill chase_girl()
{
	single girl;
	learn_about girl;
	confess((girl with wan) split_into_two);	
	give_up_chase;
}

single mgod()
{
	initialize_playboy_mode;
	search_for_new_girls;
	int number_of_girls;
	learn_about number_of_girls; //i_only_chase_one_girl;
	while(number_of_girls>0)
	{
		chase_girl();
		move_on_to_next_girl;
	}
	end_up_being_single_anyway;
}