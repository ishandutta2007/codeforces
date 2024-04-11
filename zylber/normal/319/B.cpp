#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n), s(n);
	
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		s[i] = i+1;
	}

	queue<int> batch;
	for(int i = n-1; i >= 0; i--) {
		batch.push(i);
	}

	int ans = -1;
	while(!batch.empty()) {
		queue<int> nextbatch;
		while(!batch.empty()) {
			int act = batch.front();
			batch.pop();
			if(s[act] < n && a[s[act]] < a[act]) {
				a[s[act]] = 0;
				s[act] = s[s[act]];
				nextbatch.push(act);
			}
		}
		ans++;
		batch = nextbatch;
	}

	cout << ans << endl;
}