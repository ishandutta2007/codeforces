#include<bits/stdc++.h>
using namespace std;


int a[200010];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> v;
	for(int i=1;i<=n;i++){
		v.emplace_back(i*2-1);
		cin >> a[i*2-1];
	}
	sort(v.begin(),v.end(),[&](int x,int y){
		return a[x] > a[y];
	});
	for(int i=1;i<n;i++)
		cout << v[i-1] << ' ' << v[i] << '\n';
	for(int i=0;i<n;i++){
		int j = i + a[v[i]] - 1;
		cout << v[j] << ' ' << v[i] + 1 << '\n';
		if(j==v.size() - 1)
			v.emplace_back(v[i] + 1);
	}
}