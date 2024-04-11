#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



const int mod = 998244353;
struct Mod {
public:
	int num;
	Mod() : Mod(0) { ; }
	Mod(long long int n) : num((n % mod + mod) % mod) {
		static_assert(mod<INT_MAX / 2, "mod is too big, please make num 'long long int' from 'int'");
	}
	Mod(int n) : Mod(static_cast<long long int>(n)) { ; }
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
Mod mod_pow(const Mod a, const int n) {
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
string st;
int N;
pair<Mod,Mod> dfs(int sz,int now,bool flag,vector<int>&used){
	//cout<<now<<endl;
	assert(!used[now]);
	used[now]=true;
	
	if(flag){
		int to=N-1-now;
		if(to==now){
			if(now>=sz){
				if(st[N-1-now]=='1')return make_pair(0,1);
				else if(st[N-1-now]=='0')return make_pair(1,0);
				else return make_pair(1,1);
			}
			if(st[N-1-now]=='1')return make_pair(1,1);
			else if(st[N-1-now]=='0')return make_pair(1,1);
			else return make_pair(2,2);
		}
		auto p=dfs(sz,to,!flag,used);

		if(now>=sz){
			//cout<<now<<endl;
			//cout<<p.first<<' '<<p.second<<endl;
			if(st[N-1-now]=='1'){
				return make_pair(0,p.second);
			}else if(st[N-1-now]=='0'){
				return make_pair(p.first,0);
			}else{
				return make_pair(p.first,p.second);
			}
		}else{
			if(st[N-1-now]=='1'){
				return make_pair(p.second,p.first);
			}else if(st[N-1-now]=='0'){
				return make_pair(p.first,p.second);
			}else{
				return make_pair(p.first+p.second,p.first+p.second);
			}
		}
	}else{
		int to=sz-1-now;
		if(now>=sz){
			if(st[N-1-now]=='1')return make_pair(0,1);
			else if(st[N-1-now]=='0')return make_pair(1,0);
			else return make_pair(1,1);
		}
		else if(to==now){
			if(st[N-1-now]=='1')return make_pair(1,1);
			else if(st[N-1-now]=='0')return make_pair(1,1);
			else return make_pair(2,2);
		}
		auto p=dfs(sz,to,!flag,used);
		if(st[N-1-now]=='1'){
			return make_pair(p.second,p.first);
		}else if(st[N-1-now]=='0'){
			return make_pair(p.first,p.second);
		}else{
			return make_pair(p.first+p.second,p.first+p.second);
		}
	}
	
}
int main() {
	cin>>st;
	if(st.back()=='1'){
		cout<<0<<endl;
		return 0;
	}else if(st.back()=='?')st.back()='0';
	 N=st.size();
	Mod answer=0;
	for(int sz=1;sz<N;++sz){
		vector<int>used(N);
		//cout<<"sz"<<" "<<sz<<endl;
		Mod nanswer=1;
		for(int x=N-1;x>=0;--x){
			//cout<<'x'<<endl;
			if(!used[x]){
				auto p=dfs(sz,x,true,used);
				nanswer*=p.first+p.second;
				//cout<<"na "<<nanswer.num<<endl;
			}
		}
		answer+=nanswer;
		//cout<<nanswer.num<<endl;
	}
	cout<<answer.num<<endl;
	return 0;
}