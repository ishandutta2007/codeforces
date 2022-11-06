#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
vector<int>primes;
void hurui(const int amax) {
	static bool flag = false;
	if (flag)return;
	vector<int>sos;
	sos = vector<int>(amax + 1, true);
	sos[0] = false; sos[1] = false;
	for (int i = 2; i <= amax; ++i) {
		if (sos[i]) {
			for (int j = 2 * i; j <= amax; j += i)sos[j] = false;
		}
	}
	for (int i = 0; i <= amax; ++i) {
		if (sos[i]) {
			primes.push_back(i);
		}
	}
	flag = true;
}
long long int gcd(long long int l, long long int r) {
	if (l > r)return gcd(r, l);
	else {
		if (r%l) {
			return gcd(l, r%l);

		}
		else {
			return l;
		}
	}
}
map<long long int, int>soinnsuu(long long int a) {
	hurui(1e5+10);
	map<long long int, int>ans;
	for (auto i : primes) {
		if (i> a)break;
		while (a%i == 0) {
			ans[i]++;
			a /= i;
		}
	}
	if (a != 1)ans[a]++;
	return ans;
}
long long int calc(const map<long long int,int>&mp) {
	long long int ans=1;
	for (auto m : mp) {
		ans*=1+m.second;
	}
	return ans;
}
int main() {
	int N;cin>>N;
	vector<string>sts;
	for (int i = 0; i < N; ++i) {
		string st;cin>>st;
		sts.push_back(st);
	}
	vector<int>used(26);
	vector<int>tos(26,-1);
	vector<int>froms(26,-1);
	bool ok=true;
	for (int i = 0; i < N; ++i) {
		used[sts[i][0]-'a']=true;
		for (int j = 0; j < sts[i].size() - 1; ++j) {
			char ch=sts[i][j]-'a';
			used[ch]=true;
			char nch=sts[i][j+1]-'a';
			used[nch]=true;
			if(tos[ch]!=-1&&tos[ch]!=nch)ok=false;
			else {
				tos[ch]=nch;
			}
			if(froms[nch]!=-1&&froms[nch]!=ch)ok=false;
			else {
				froms[nch]=ch;
			}
		}
	}
	vector<string>ans_sts;
	for (int i = 0; i < 26; ++i) {
		if (froms[i] == -1 && used[i]) {
			int now=i;
			string a_st;
			a_st.push_back('a'+now);
			while (tos[now] != -1) {
				now=tos[now];
				a_st.push_back('a' + now);
				if (a_st.size() >= 5000) {
					ok=false;
					break;
				}
			}
			ans_sts.push_back(a_st);
		}
	}
	sort(ans_sts.begin(),ans_sts.end());
	int sum=0;
	for(auto st:ans_sts)sum+=st.size();
	if(sum!=accumulate(used.begin(),used.end(),0))ok=false;
	if (ok) {
		for(auto ans_st:ans_sts)cout<<ans_st;
		cout<<endl;
	}
	else {
		cout<<"NO"<<endl;
	}
	return 0;
}