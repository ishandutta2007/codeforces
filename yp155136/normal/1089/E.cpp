#include <bits/stdc++.h>
using namespace std;

int n = 8;

char a[8];

void gett() {
	random_shuffle(a,a+8);
}

vector<pair<char,int> > ans;

int saki;

void show_ans() {
	for (int i=0;i<ans.size();++i) {
		if (i) cout << ' ';
		cout << ans[i].first << ans[i].second;
	}
	cout << endl;
	assert(ans.size() == saki+1);
	exit(0);
}

void putt(char c,int j) {
	ans.push_back(make_pair(c,j));
}

int main () {
	int x;
	cin >> x;
	saki = x;
	for (int i=0;i<n;++i) {
		a[i] = char('a'+i);
	}
	char nowi = 'a'; //a ~ h
	int nowj = 1;
	putt('a',1);
	while (x >= 8) {
		if (x == 8) {
			while (a[0] != nowi || a[7] != 'h') gett();
			for (int i=1;i<=7;++i) putt(a[i],nowj);
			putt('h',8);
			show_ans();
		}
		else if (x == 9) {
			while (a[0] != nowi || a[7] == 'h') gett();
			for (int i=1;i<=7;++i) putt(a[i],nowj);
			nowi = a[7];
			++nowj;
			x -= 7;
			if (nowj == 8) {
				putt(nowi,nowj);
				--x;
			}
		}
		else {
			while (a[0] != nowi || a[7] == 'h') gett();
			for (int i=1;i<=7;++i) putt(a[i],nowj);
			putt(a[7],nowj+1);
			++nowj;
			nowi = a[7];
			x -= 8;
		}
	}
	if (nowj != 8) {
		--x;
		putt(nowi,8);
		// cout << "innnn" << endl;
	}
	nowj = 8;
	// cout << "geee" << endl;
	// cout << "nowi = " << nowi << " , nowj = " << nowj << endl;
	while (a[0] != nowi || a[x] != 'h') gett();
	for (int i=1;i<=x;++i) putt(a[i],nowj);
	show_ans();
}