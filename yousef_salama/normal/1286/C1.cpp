#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int n, cnt[26], cnt2[26];
string s;
multiset <string> q1[MAXN];
vector <string> q2[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	
	if(n == 1){
		cout << "? " << 1 << " " << n << endl;
		cout.flush();

		cin >> s;
		cout << "! " << s << endl;
		
		return 0;
	}
	
	cout << "? " << 1 << " " << n << endl;
	cout.flush();
	
	for(int i = 0; i < n * (n + 1) / 2; i++){
		cin >> s;
		sort(s.begin(), s.end());
		q1[s.size()].insert(s);
	}
	
	cout << "? " << 2 << " " << n << endl;
	cout.flush();
	
	for(int i = 0; i < n * (n - 1) / 2; i++){
		cin >> s;
		sort(s.begin(), s.end());
		q2[s.size()].push_back(s);
	}
	
	cout << "! ";
	
	for(int i = 0; i < n; i++){
		for(string q : q2[i + 1])
			if(q1[i + 1].count(q))q1[i + 1].erase(q1[i + 1].lower_bound(q));
		string nq = *q1[i + 1].begin();
		
		for(int i = 0; i < 26; i++)cnt2[i] = cnt[i];
		for(char c : nq)cnt2[c - 'a']--;
		
		for(int i = 0; i < 26; i++)if(cnt2[i] != 0){
			cout << (char)(i + 'a');
			cnt[i]++;
		}
	}
	
	cout << endl;
	
	return 0;
}