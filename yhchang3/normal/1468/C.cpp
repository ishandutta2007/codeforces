#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	vector<bool> vis(500001);
	int cus = 0;
	priority_queue<pair<int,int>> pq;
	queue<int> q;
	while(T--) {
		int op;
		cin >> op;
		if(op == 1) {
			++cus;
			int m;
			cin >> m;
			q.emplace(cus);
			pq.emplace(m, -cus);
		}
		else if(op == 2) {
			while(vis[q.front()])	q.pop();
			vis[q.front()] = true;
			cout << q.front() << ' ';
		}
		else {
			while(vis[-pq.top().second])	pq.pop();
			vis[-pq.top().second] = true;
			cout << -pq.top().second << ' ';
		}
	}
	cout << endl;
}