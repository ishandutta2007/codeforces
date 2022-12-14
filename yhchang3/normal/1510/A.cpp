#include <bits/stdc++.h>

using namespace std;

typedef vector<string> au;
typedef pair<vector<string>, int>  node;

string ls = "+->", rs = "->+";
char str[501];
string bl[1001], mi[1001];
au extend(au s, char ch) {
	au tmp; tmp.clear();
	if (ch == '+') {
		for (int i = 0; i < s.size(); i ++) {
			if (i == 0) tmp.push_back(bl[3] + s[i] + bl[3]);
			else if (i == 1) tmp.push_back(ls + s[i] + rs);
			else tmp.push_back("|" + bl[2] + s[i] + bl[2] + "|");
		}
		tmp.push_back("|" + bl[s[0].size() + 4] + "|");
		tmp.push_back("+<" + mi[s[0].size() + 3] + "+");

	}
	else if (ch == '?') {
		tmp.push_back(bl[s[0].size() + 6]);
		tmp.push_back("+" + mi[s[0].size() + 3] + ">+");
		tmp.push_back("|" + bl[s[0].size() + 4] + "|");
		for (int i = 0; i < s.size(); i ++) {
			if (i == 1) tmp.push_back(ls + s[i] + rs);
			else if (i == 0) tmp.push_back("|" + bl[2] + s[i] + bl[2] + "|");
			else tmp.push_back(bl[3] + s[i] + bl[3]);
		}
	}
	else {
		tmp.push_back(bl[s[0].size() + 6]);
		tmp.push_back("+" + mi[s[0].size() + 3] + ">+");
		tmp.push_back("|" + bl[s[0].size() + 4] + "|");
		for (int i = 0; i < s.size(); i ++) {
			if (i == 1) tmp.push_back(ls + s[i] + rs);
			else tmp.push_back("|" + bl[2] + s[i] + bl[2] + "|");
		}
		tmp.push_back("|" + bl[s[0].size() + 4] + "|");
		tmp.push_back("+<" + mi[s[0].size() + 3] + "+");
	}
	return tmp;
}

au link(au s1, au s2) {
	au tmp; tmp.clear();
	int all = max(s1.size(), s2.size());
	for (int i = 0; i < all; i ++) {
		string xa, xb;
		if (i < s1.size()) xa = s1[i];
		else xa = bl[s1[0].size()];
		if (i < s2.size()) xb = s2[i];
		else xb = bl[s2[0].size()];
		
		if (i == 1) tmp.push_back(xa + "->" + xb);
		else tmp.push_back(xa + bl[2] + xb);
	}
	return tmp;
}

node mexpr(au s1, node x) {
	vector<string> tmp; tmp.clear();
	au s2 = x.first;
	int mx = s1[0].size() + 6;
	if (x.second == 0) mx = max(mx, (int )s2[0].size() + 6);
	else mx = max(mx, (int )s2[0].size());
	
	for (int i = 0; i < s1.size(); i ++) {
		string cur;
		int def = mx - s1[i].size() - 6;
		if (i == 1) tmp.push_back(ls + s1[i] + mi[def] + rs);
		else if (i == 0) tmp.push_back(bl[3] + s1[i] + bl[3 + def]);
		else tmp.push_back("|" + bl[2] + s1[i] + bl[2 + def] + "|");
	}
	tmp.push_back("|" + bl[mx - 2] + "|");
	if (x.second == 0) {
		for (int i = 0; i < s2.size(); i ++) {
			int def = mx - s2[i].size() - 6;
			if (i == 1) tmp.push_back(ls + s2[i] + mi[def] + rs);
			else if (i != 0) tmp.push_back(bl[3] + s2[i] + bl[3 + def]);
			else tmp.push_back("|" + bl[2] + s2[i] + bl[2 + def] + "|");
		}
	}
	else {
		for (int i = 0; i < s2.size(); i ++) {
			int def = mx - s2[i].size();
			if (i == 0 && s2[i][0] == ' ') tmp.push_back("|" + s2[i].substr(1, s2[i].size() - 2) + bl[def] + "|");
			else {
				if (s2[i][s2[i].size() - 1] == '+')
					tmp.push_back(s2[i].substr(0, s2[i].size() - 2) + mi[def] + ">+");
				else
					tmp.push_back(s2[i].substr(0, s2[i].size() - 1) + bl[def] + s2[i][s2[i].size() - 1]);
			}
		}
	}

	return make_pair(tmp, 1);
}

bool extra(char ch) {
	return ch == '+' || ch == '?' || ch == '*';
}
node gaoexpr(int l, int r);
int lst[1001];
au gaoterm(int l, int r) {
	for (int i = l; i <= r; i ++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			int j = i;
			string ss = "";
			while (j <= r && str[j] >= 'A' && str[j] <= 'Z') {
				ss += str[j];
				++ j;
			}
			-- j;
			au cur; cur.clear(); 
			if (j == r) {
				cur.push_back("+-" + mi[j - i + 1] + "-+");
				cur.push_back("+ " + ss + " +");
				cur.push_back("+-" + mi[j - i + 1] + "-+");
				return cur;
			}
			int tmp = j;
			if (extra(str[j + 1])) {
				cur.push_back("+-" + mi[1] + "-+");
				cur.push_back("+ " + ss.substr(ss.size() - 1, ss.size()) + " +");
				cur.push_back("+-" + mi[1] + "-+");
				tmp = j + 1;
				while (tmp <= r && extra(str[tmp])) {
					cur = extend(cur, str[tmp]);
					++ tmp;
				}
				-- tmp;
				if (ss.size() > 1) {
					au cur1; cur1.clear();
					cur1.push_back("+-" + mi[j - i] + "-+");
					cur1.push_back("+ " + ss.substr(0, ss.size() - 1) + " +");
					cur1.push_back("+-" + mi[j - i] + "-+");
					cur = link(cur1, cur);
				}
			}
			else {
				cur.push_back("+-" + mi[j - i + 1] + "-+");
				cur.push_back("+ " + ss + " +");
				cur.push_back("+-" + mi[j - i + 1] + "-+");
			}
			if (tmp + 1 <= r) return link(cur, gaoterm(tmp + 1, r));
			else return cur;
		}
		else if (str[i] == '(') {
			int j = lst[i];
			au cur = gaoexpr(i + 1, j - 1).first;
			int tmp = j + 1;
			while (tmp <= r && extra(str[tmp])) {
				cur = extend(cur, str[tmp]);
				++ tmp;
			}
			-- tmp;
			if (tmp + 1 <= r) return link(cur, gaoterm(tmp + 1, r));
			else return cur;
		}
	}
}

node gaoexpr(int l, int r) {
	if (lst[l] == r) {
		return make_pair(gaoexpr(l + 1, r - 1).first, 0);
	}
	int cnt = 0;
	for (int i = l; i <= r; i ++) {
		if (str[i] == '(') ++  cnt;
		else if (str[i] == ')') -- cnt;
		if (str[i] == '|') {
			if (cnt == 0)
			return mexpr(gaoterm(l, i - 1), gaoexpr(i + 1, r));
		}
	}
	return make_pair(gaoterm(l, r), 0);
}

int top = 0, stk[1001];
int main( ) {
	int n;
	scanf("%s", str + 1);
	n = (int )strlen(str + 1);
	for (int i = 1; i <= n; i ++) {
		if (str[i] == '(') stk[++ top] = i;
		else if (str[i]  == ')') {
			lst[stk[top]] = i;
			-- top;
		}
	}
	for (int i = 1; i <= 1000; i ++) {
		bl[i] = bl[i - 1] + " ";
		mi[i] = mi[i - 1] + "-";
	}
	au ans = gaoexpr(1, n).first;
	printf("%d %d\n", ans.size(), ans[0].size() + 6);
	for (int i = 0; i < ans.size(); i ++) {
		if (i != 1) cout << bl[3] + ans[i] + bl[3] << endl;
		else cout << "S->" + ans[i] + "->F" << endl;
	}
	return 0;
}