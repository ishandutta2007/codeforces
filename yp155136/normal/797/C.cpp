#include <iostream>
#include <stack>
using namespace std;

int cnt[777];

int main () {
	string ss;
	cin >> ss;
	stack<char> s;
	for (char i:ss) cnt[i]++;
	int id='a';
	cnt['z'+1]=1;
	for (int i=0;ss.size()>i;i++) {
		while (cnt[id] == 0) {
			id++;
		}
		while (!s.empty() && (cnt[s.top()] == 0 && s.top() <= id || s.top()==id)) {
			cout<<s.top();
			s.pop();
		}
		if (ss[i] == id) {
			cout<<ss[i];
			cnt[id]--;
		}
		else {
			s.push(ss[i]);
			cnt[ss[i]]--;
		}
	}
	while (!s.empty()) {
		cout<<s.top();
		s.pop();
	}
	cout<<endl;
}