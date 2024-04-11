#include <bits/stdc++.h>
using namespace std;

bool losewin[6];

typedef pair<int,int> pii;

struct Ans {
	int na,nb;
	vector<pii> v;
	Ans(){}
	Ans(vector<pii> _v,int _na,int _nb):na(_na),nb(_nb),v(_v){}
};

bool better(Ans a,Ans b) {
//return a should replace b
	if (b.na == -1 && b.nb == -1) return true;
	if (a.na - a.nb > b.na - b.nb) return true;
	return false;
}

Ans all_ans[44006];

void show_ans(Ans ans) {
	if (ans.na == 0 && ans.nb == 0) {
		cout << "Impossible" << endl;
	}
	else {
		cout << ans.na << ":" << ans.nb << endl;
		for (int i=0;i<ans.v.size();++i) {
			if (i) cout << ' ';
			cout << ans.v[i].first << ":" << ans.v[i].second;
		}
		cout << endl;
	}
}

bool haha(int sa,int sb) {
	++sa;
	++sb;
	int val = (sa) * 202 + sb;
	if (all_ans[val].na != -1) {
		show_ans(all_ans[val]);
		return true;
	}
	else return false;
}

void savedata(Ans ans,int sa,int sb) {
	++sa;
	++sb;
	int val = (sa) * 202 + sb;
	all_ans[val] = ans;
	show_ans(ans);
}

int sa[5],sb[5];

int full_score(int x) {
	if (x == 4) return 15;
	else return 25;
}

int n;

int tota,totb;

void get_tot() {
	tota = 0;
	totb = 0;
	for (int i=0;i<n;++i) {
		tota += sa[i];
		totb += sb[i];
	}
}

vector<pii> get_v() {
	vector<pii> ret;
	for (int i=0;i<n;++i) {
		ret.push_back(make_pair(sa[i],sb[i]));
	}
	return ret;
}

void solve() {
	int a,b;
	cin >> a >> b;
	if (haha(a,b)) return;
	Ans ans;
	ans.na = ans.nb = -1;
	for (int len=3;len<=5;++len) {
		set<pii> st;
		for (int mask=0;mask<(1<<len);++mask) {
			int win[2] = {0,0};
			for (int j=0;j<len;++j) {
				if (((1<<j)&mask) != 0) losewin[j] = true;
				else losewin[j] = false; //losewin[j] == false means team A lose
				win[ 1-losewin[j] ]++;
				if (win[0] == 3 || win[1] == 3) break;
			}
			if (win[0] + win[1] == len && max(win[0],win[1]) == 3 && min(win[0],win[1]) < 3) {
				;
			}
			else continue;
			// if (st.find(make_pair(win[0],win[1])) != st.end()) continue;
			st.insert(make_pair(win[0],win[1]));
			n = len;
			tota=0,totb=0;
			for (int i=0;i<n;++i) {
				if (losewin[i]) {
					sa[i] = full_score(i);
					sb[i] = 0;
				}
				else {
					sb[i] = full_score(i);
					sa[i] = 0;
				}
				tota += sa[i];
				totb += sb[i];
				// cout << "n = " << n << " , sa "
			}
			if (tota > a || totb > b) continue;
			// cout << "len = " << len << endl;
			for (int duce=0;duce < 3;duce++) {
				for (int i=0;i<n;++i) {
					if (losewin[i]) {
						sa[i] = full_score(i);
						sb[i] = 0;
					}
					else {
						sb[i] = full_score(i);
						sa[i] = 0;
					}
				}
				if (duce) {
					get_tot();
					// cout << "tota = " << tota << " , totb = " << totb << " , a = " << a << " , b = " << b << endl;
					tota = a-tota;
					totb = b-totb;
					int duce_p;
					if (duce == 1) duce_p = 0;
					else if (len < 5) duce_p = 0;
					else duce_p = 4;
					// get_tot();
					// cout << "duce_p = " << duce_p << endl;
					if (losewin[duce_p]) {
						int need = full_score(duce_p) - 2;
						totb -= need;
						sb[duce_p] += need;
						if (totb<0) continue;
					}
					else {
						int need = full_score(duce_p) - 2;
						tota -= need;
						sa[duce_p] += need;
						if (tota<0) continue;
					}
					// cout << "final tota = " << tota << " , totb = " << totb << endl;
					int x = min(tota,totb);
					sa[duce_p] += x;
					sb[duce_p] += x;
					tota -= x;
					totb -= x;
					// cout << "hahaha" << endl;
					// get_tot();
					// tota = a-tota;
					// totb = b-totb;
					for (int i=0;i<n;++i) {
						// cout << "i = " << i << " , ori sa = " << sa[i] << " , roi sb = " << sb[i] << endl;
						if (i == duce_p) continue;
						if (losewin[i]) {
							int del = min(full_score(i)-2,totb);
							sb[i] += del;
							totb -= del;
						}
						else {
							int del = min(full_score(i)-2,tota);
							sa[i] += del;
							tota -= del;
						}
					}
					if (tota == 0 && totb == 0) {
						Ans tmp = Ans(get_v(),win[0],win[1]);
						if (better(tmp,ans)) ans = tmp;
					}
				}
				else {
					get_tot();
					tota = a-tota;
					totb = b-totb;
					// cout << "hahahahahhaha" << endl;
					for (int i=0;i<n;++i) {
						if (losewin[i]) {
							int del = min(full_score(i)-2,totb);
							sb[i] += del;
							totb -= del;
						}
						else {
							int del = min(full_score(i)-2,tota);
							sa[i] += del;
							tota -= del;
						}
					}
					if (tota == 0 && totb == 0) {
						Ans tmp = Ans(get_v(),win[0],win[1]);
						// cout << "innnn" << endl;
						if (better(tmp,ans)) ans = tmp;
					}
					// break;
				}
			}
		}
	}
	if (ans.na == -1) ans.na = ans.nb = 0;
	savedata(ans,a,b);
}

int main () {
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	for (int i=0;i<44006;++i) {
		all_ans[i].na = all_ans[i].nb = -1;
	}
	while (T--) {
		solve();
	}
}