#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
using namespace std;

typedef long double ld;



const int mod = 1000000007;
struct Mod {
public:
	int num;
	Mod():num(0){
	}
	Mod(long long int n) : num((n % mod + mod) % mod) {
		static_assert(mod<INT_MAX / 2, "mod is too big, please make num 'long long int' from 'int'");
	}
	operator int() { return num; }
};

Mod operator+(const Mod a, const Mod b) { return Mod((a.num + b.num) % mod); }
Mod operator+(const long long int a, const Mod b) { return Mod(a) + b; }
Mod operator+(const Mod a, const long long int  b) { return b + a; }
Mod operator++(Mod &a) { return a + Mod(1); }
Mod operator-(const Mod a, const Mod b) { return Mod((mod + a.num - b.num) % mod); }
Mod operator-(const long long int a, const Mod b) { return Mod(a) - b; }
Mod operator--(Mod &a) { return a - Mod(1); }
Mod operator*(const Mod a, const Mod b) { return Mod(((long long)a.num * b.num) % mod); }
Mod operator*(const long long int a, const Mod b) { return Mod(a)*b; }
Mod operator*(const Mod a, const long long int b) { return Mod(b)*a; }
Mod operator*(const Mod a, const int b) { return Mod(b)*a; }
Mod operator+=(Mod &a, const Mod b) { return a = a + b; }
Mod operator+=(long long int &a, const Mod b) { return a = a + b; }
Mod operator-=(Mod &a, const Mod b) { return a = a - b; }
Mod operator-=(long long int &a, const Mod b) { return a = a - b; }
Mod operator*=(Mod &a, const Mod b) { return a = a * b; }
Mod operator*=(long long int &a, const Mod b) { return a = a * b; }
Mod operator*=(Mod& a, const long long int &b) { return a = a * b; }
Mod operator^(const Mod a, const int n) {
	if (n == 0) return Mod(1);
	Mod res = (a * a) ^ (n / 2);
	if (n % 2) res = res * a;
	return res;
}
Mod mod_pow(const Mod a, const long long  int n) {
	if (n == 0) return Mod(1);
	Mod res = mod_pow((a * a), (n / 2));
	if (n % 2) res = res * a;
	return res;
}
Mod inv(const Mod a) { return a ^ (mod - 2); }
Mod operator/(const Mod a, const Mod b) {
	assert(b.num != 0);
	return a * inv(b);
}
Mod operator/(const long long int a, const Mod b) {
	return Mod(a) / b;
}
Mod operator/=(Mod &a, const Mod b) {
	return a = a / b;
}

#define MAX_MOD_N 1024000

Mod fact[MAX_MOD_N], factinv[MAX_MOD_N];
void init(const int amax = MAX_MOD_N) {
	fact[0] = Mod(1); factinv[0] = 1;
	for (int i = 0; i < amax - 1; ++i) {
		fact[i + 1] = fact[i] * Mod(i + 1);
		factinv[i + 1] = factinv[i] / Mod(i + 1);
	}
}
Mod comb(const int a, const int b) {
	return fact[a] * factinv[b] * factinv[a - b];
}

Mod solve(int M,int now,vector<int>&as,vector<int>&bs){
	if(now==as.size()){
		return Mod(0);
	}else{
		
		Mod ans=0;
		Mod awin,draw,bwin;
		if(as[now]==0&&bs[now]==0){
			awin=Mod(M-1)/Mod(M)/Mod(2);
			draw=Mod(1)/Mod(M);
			bwin=Mod(M-1)/Mod(M)/Mod(2);
		}else if(as[now]==0){
			assert(bs[now]);
			 awin=Mod(bs[now]-1)/Mod(M);
			 draw=Mod(1)/Mod(M);
			 bwin=Mod(M-bs[now])/Mod(M);
		}else if(bs[now]==0){
			assert(as[now]);
			awin=Mod(M-as[now])/Mod(M);
			draw=Mod(1)/Mod(M);
			bwin=Mod(as[now]-1)/Mod(M);

		}else{
			if(as[now]==bs[now]){
				awin=Mod(0);
				draw=Mod(1);
				bwin=Mod(0);
			}else{
				if(as[now]<bs[now]){
					awin=Mod(1);
					draw=Mod(0);
					bwin=Mod(0);
				}else{
					awin=Mod(0);
					draw=Mod(0);
					bwin=Mod(1);
				}
			}
		}
		ans+=solve(M,now+1,as,bs)*draw;
		ans+=bwin;
		return ans;
	}
}

struct Node{
	int num;
	vector<shared_ptr<Node>>chs;


	Node(int _num):num(_num),chs(2){
	}
	Node(const shared_ptr<Node>&l,const shared_ptr<Node>&r):num(0),chs(0){
		chs.push_back(l);
		chs.push_back(r);
	}
};



shared_ptr<Node> solve(string st,int&a){
	if(a==st.size()){
		assert(false);
	}
	if(isdigit(st[a])){
		auto node_it= make_shared<Node>(st[a]-'0');
		a++;
		return node_it;
	}else if(st[a]=='('){
		a++;
		auto lt(solve(st,a));
		char ch(st[a]);
		assert(ch=='?');
		a++;
		auto rt(solve(st,a));
		assert(st[a]==')');
		a++;
		return make_shared<Node>(lt,rt);
	}else{
		assert(false);
	}
}

vector<pair<int,int>> solve(const shared_ptr<Node>&it,int amax,bool is_plus){
	if(it->num==0){
		vector<pair<int,int>>lv(solve(it->chs[0],amax,is_plus));
		vector<pair<int,int>>rv(solve(it->chs[1],amax,is_plus));

		vector<pair<int,int>>ansv(min(amax+1,int(lv.size()+rv.size())),make_pair(1e9,-1e9));

		for(int i=0;i<lv.size();++i){
			auto lp(lv[i]);
			for(int j=0;j<rv.size();++j){
				auto rp(rv[j]);
				for(int use=0;use<2;++use){
				if(i+j+use>=ansv.size())continue;
					int mx,mi;
					if(use^is_plus){
						mx=lp.second-rp.first;
						mi=lp.first-rp.second;
					}else{
						mx=lp.second+rp.second;
						mi=lp.first+rp.first;
					}
					ansv[i+j+use].first=min(ansv[i+j+use].first,mi);
					ansv[i+j+use].second=max(ansv[i+j+use].second,mx);
				}
			}
		}
		return ansv;
	}else{
		vector<pair<int,int>>v(1,make_pair(it->num,it->num));
		return v;
	}
}

int main() { 
	
	string st;cin>>st;
	int a=0;
	auto root_it=solve(st,a);

	int Pl,Mi;cin>>Pl>>Mi;
	vector<pair<int,int>>v;
	int ans;
	if(Pl>Mi){
		v=(solve(root_it,Mi,false));
		ans=v[Mi].second;
	}else{
		v=(solve(root_it,Pl,true));
		ans=v[Pl].second;
	}
	cout<<ans<<endl;
	return 0;

}