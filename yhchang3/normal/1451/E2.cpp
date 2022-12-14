#include<bits/stdc++.h>
using namespace std;

int a[1 << 17];
vector<int> v[1 << 17];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	v[0].emplace_back(1);
	for(int i=2;i<=n;i++){
		cout << "XOR" << ' ' << 1 << ' ' << i << endl;
		cin >> a[i];
		v[a[i]].emplace_back(i);
	}
	int idx = -1;
	for(int i=0;i<n;i++)
		if(v[i].size() >= 2)
			idx = i;
	if(idx == -1) {
		cout << "AND" << ' ' << v[0][0] << ' ' << v[1][0] << endl;
		int m;
		cin >> m;
		cout << "AND" << ' ' << v[0][0] << ' ' << v[2][0] << endl;
		int z;
		cin >> z;
		if(z&1)
			m |= 1;
		cout << "!";
		for(int i=1;i<=n;i++)
			cout << ' ' << (a[i] ^ m);
		cout <<endl;
	}
	else{
		cout << "AND" << ' ' << v[idx][0] << ' ' << v[idx][1] << endl;
		int idxto;
		cin >> idxto;
		int m = idx ^ idxto;
		cout << "!";
		for(int i=1;i<=n;i++)
			cout << ' ' << (a[i] ^ m);
		cout <<endl;
	}
}