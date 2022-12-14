#include<bits/stdc++.h>
using namespace std;
 
int sz[1000001], pre[30000000], head[1000001];

void insert(int v,int h) {
	pre[h] = head[v];
	head[v] = h;
	sz[v]++;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			insert(abs(a[j] - a[i]), i * n + j + 1);
	vector<int> vis(1e6 + 1);
	for(int i=1;i<=1e6;i++) {
		int tot = 0;
		for(int j=i;j<=1e6;j+=i)
			tot += sz[j];
		if(tot > k * (k + 1) / 2)	continue;
		set<int> st;
		for(int j=i;j<=1e6;j+=i) {
			int cur = head[j];
			while(cur) {
				int x = (cur - 1) / n, y = (cur - 1) % n;
				st.insert(x), st.insert(y);
				cur = pre[cur];
			}
		}
		int cnt = 0;
		for(int x:st)
			if(vis[a[x] % i] == i)
				cnt++;
			else
				vis[a[x] % i] = i;
		if(cnt <= k)
			return  cout << i << endl, 0;
	}
	cout << 1e6 + 1 << endl;
}