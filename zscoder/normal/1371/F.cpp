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
#define done return 
#define bf second
#define waifu first
#define spare second
#define in_a_relationship make_pair
#define zero 0
#define add_to_harem push_back
#define add_to_friend_list push_back
#define changed ^=1
#define add_to_plan push_back
#define remove_from_plan pop_back
#define give_up_chase return 
#define giveMGod return
#define wan 1
#define with +
#define without - 
#define self_multiplied 2*
#define next ++
#define ex --
#define rejected return false
#define accepted return true
#define initialize_playboy_mode ios_base::sync_with_stdio(0);
#define search_for_new_girls cin.tie(0);
#define girl int
#define single int
#define mgod main
#define ConfessionResult bool
#define couple pair<int,int>
#define couples vector<couple>
#define messed_up cout << -1 << endl;
#define reject cout<<"NO\n"
#define accept cout<<"YES\n"
#define learn_about cin >>
#define female 1
#define male 0
#define move_on_to_next_girl number_of_girls--;
#define confess sweettalk
#define end_up_being_single_anyway return 0;
#define i_only_chase_one_girl number_of_girls = 1;
#define leader rt
#define todolist vector<int>
#define sex int
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

struct FamilyMember
{
	int age;
	couple youth[2];
	couple old[2];
	int youth_power[2];
	int old_power[2];
	int power[2];
	int is_in_love; 
};

FamilyMember baby;
FamilyMember family_tree[2222222];

FamilyMember reproduce(const FamilyMember &wife, const FamilyMember &husband)
{
	//update youth
	FamilyMember new_parent;
	new_parent.age = wife.age + husband.age;
	new_parent.is_in_love = zero;
	for(int step = zero; step <= wan; next step)
	{
		if(wife.old[step].bf == husband.youth[step].bf && wife.old[step].gf == wife.age) 
		{
			new_parent.youth[step].gf = wife.old[step].gf + husband.youth[step].gf;
			new_parent.youth[step].bf = wife.old[step].bf;
		}
		else
		{
			new_parent.youth[step] = wife.youth[step];
		}
		if(wife.old[step].bf == husband.youth[step].bf && husband.youth[step].gf == husband.age) 
		{
			new_parent.old[step].gf = wife.old[step].gf + husband.youth[step].gf;
			new_parent.old[step].bf = wife.old[step].bf;
		}
		else
		{
			new_parent.old[step] = husband.old[step];
		}
		//youth_power 
		if(wife.old[step].gf == wife.age && wife.old[step].bf == wan) //full same sia and go to the right!
		{
			new_parent.youth_power[step] = wife.youth_power[step] + husband.youth_power[step];
		}
		else if(wife.youth_power[step] == wife.age && wife.old[step].bf == husband.youth[step].bf)
		{
			new_parent.youth_power[step] = wife.youth_power[step] + husband.youth_power[step];
		}
		else
		{
			new_parent.youth_power[step] = wife.youth_power[step];
		}
		//old power
		if(husband.old[step].gf == husband.age && husband.old[step].bf == zero) //full same sia and go to the left!
		{
			new_parent.old_power[step] = wife.old_power[step] + husband.old_power[step];
		}
		else if(husband.old_power[step] == husband.age && wife.old[step].bf == husband.youth[step].bf)
		{
			new_parent.old_power[step] = wife.old_power[step] + husband.old_power[step];
		}
		else
		{
			new_parent.old_power[step] = husband.old_power[step];
		}
		new_parent.power[step] = max(max(new_parent.old_power[step], new_parent.youth_power[step]), max(husband.power[step], wife.power[step]));
		//merge in the middle!
		if(wife.old[step].bf == husband.youth[step].bf) //same direction
		{
			if(wife.old[step].bf) //all to the right
			{
				new_parent.power[step] = max(new_parent.power[step],  wife.old[step].gf + husband.youth_power[step]);
			}
			else
			{
				new_parent.power[step] = max(new_parent.power[step],  husband.youth[step].gf + wife.old_power[step]); //all to the left
			}
		}
		else
		{
			if(wife.old[step].bf) //merge at the middle
			{
				new_parent.power[step] = max(new_parent.power[step], wife.old[step].gf + husband.youth[step].gf); //>>><<<<
			}
		}
	}
	return new_parent;
}

skill educate_children(single member, int birthyear, int deathyear)
{
	if(family_tree[member].is_in_love)
	{
		swap(family_tree[member].youth[zero], family_tree[member].youth[wan]);
		swap(family_tree[member].old[zero], family_tree[member].old[wan]);
		swap(family_tree[member].youth_power[zero], family_tree[member].youth_power[wan]);
		swap(family_tree[member].old_power[zero], family_tree[member].old_power[wan]);
		swap(family_tree[member].power[zero], family_tree[member].power[wan]);
		if(deathyear - birthyear >= self_multiplied wan)
		{
			single wife = self_multiplied member;
			single husband = wife with wan;	
			family_tree[wife].is_in_love changed;
			family_tree[husband].is_in_love changed;
		}
		family_tree[member].is_in_love = zero;
	}
}

string family_background;

void out(int id, int l, int r)
{
	cout<<"OUTPUTTING NODE "<<id<<'\n';
	cout<<"L = "<<l<<" R = "<<r<<'\n';
	FamilyMember tmp = family_tree[id];
	for(int i=0;i<2;i++)
	{
		cout<<"YOUTH: "<<tmp.youth[i].fi<<' '<<tmp.youth[i].se<<'\n';
		cout<<"OLD: "<<tmp.old[i].fi<<' '<<tmp.old[i].se<<'\n';
		cout<<"YOUTH POW: "<<tmp.youth_power[i]<<'\n';
		cout<<"OLD POW: "<<tmp.old_power[i]<<'\n';
		cout<<"POW: "<<tmp.power[i]<<'\n';
	}
	cout<<tmp.is_in_love<<'\n';
}

skill build_family_tree(single member, int birthyear, int deathyear)
{
	family_tree[member].age = deathyear - birthyear;
	family_tree[member].is_in_love = zero;
	if(family_tree[member].age == wan)
	{
		sex gender;
		if(family_background[birthyear]=='>') gender=female;
		else gender=male;
		for(int step = zero; step <= wan; next step)
		{
			family_tree[member].youth[step] = family_tree[member].old[step] = in_a_relationship(wan, gender);
			family_tree[member].youth_power[step] = family_tree[member].old_power[step] = family_tree[member].power[step] = wan;
			gender changed;
		}
		done;
	}
	int middle_age = (birthyear + deathyear)/2;
	build_family_tree(self_multiplied member, birthyear, middle_age);
	build_family_tree(self_multiplied member with wan, middle_age, deathyear);
	FamilyMember wife = family_tree[self_multiplied member];
	FamilyMember husband = family_tree[(self_multiplied member) with wan];
	family_tree[member] = reproduce(wife,husband);
}

skill update_family_tree(single member, int birthyear, int deathyear, int newbirthyear, int newdeathyear)
{
	educate_children(member, birthyear, deathyear);
	if(newbirthyear>=deathyear||birthyear>=newdeathyear) done;
	if(newbirthyear<=birthyear&&deathyear<=newdeathyear)
	{
		family_tree[member].is_in_love changed;
		educate_children(member, birthyear, deathyear);
		done;
	}
	int middle_age = (birthyear + deathyear)/2;
	update_family_tree(self_multiplied member, birthyear, middle_age, newbirthyear, newdeathyear);
	update_family_tree(self_multiplied member with wan, middle_age, deathyear, newbirthyear, newdeathyear);
	FamilyMember wife = family_tree[self_multiplied member];
	FamilyMember husband = family_tree[(self_multiplied member) with wan];
	family_tree[member] = reproduce(wife,husband);
}

FamilyMember get_background(single member, int birthyear, int deathyear, int targetbirthyear, int targetdeathyear)
{
	educate_children(member, birthyear, deathyear);
	if(targetbirthyear>=deathyear||birthyear>=targetdeathyear) giveMGod baby;
	if(targetbirthyear<=birthyear&&deathyear<=targetdeathyear) giveMGod family_tree[member];
	int middle_age = (birthyear + deathyear)/2;
	FamilyMember wife = get_background(self_multiplied member, birthyear, middle_age, targetbirthyear, targetdeathyear);
	FamilyMember husband = get_background(self_multiplied member with wan, middle_age, deathyear, targetbirthyear, targetdeathyear);
	giveMGod reproduce(wife,husband);
}

skill chase_girl()
{
	int family_size;
	int request_count;
	learn_about family_size;
	learn_about request_count;
	learn_about family_background;
	build_family_tree(wan, zero, family_size);
	/*
	out(1,0,family_size);
	out(2,0,family_size/2);
	out(3,family_size/2,family_size);
	out(6,4,6);
	out(7,6,8);
	*/
	for(int requestno = zero; requestno < request_count; next requestno)
	{
		single wife;
		single husband;
		learn_about wife;
		learn_about husband;
		ex wife;
		update_family_tree(wan, zero, family_size, wife, husband);
		FamilyMember her_cousin = get_background(wan, zero, family_size, wife, husband);
		confess(her_cousin.power[zero]);
	}
	give_up_chase;
}

single mgod()
{
	baby.age = zero;
	for(int step = zero; step <= wan; next step)
	{
		baby.old[step] = baby.youth[step] = in_a_relationship(zero, zero);
		baby.power[step] = baby.youth_power[step] = baby.old_power[step] = zero;
		baby.is_in_love = false;
	}
	initialize_playboy_mode;
	search_for_new_girls;
	int number_of_girls;
	i_only_chase_one_girl;
	while(number_of_girls > zero)
	{
		chase_girl();
		move_on_to_next_girl;
	}
	end_up_being_single_anyway;
}