#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int n, a[MAXN];

int main(){
	scanf("%d", &n);
	
	vector <int> vx;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		vx.push_back(a[i]);
	}
	
	sort(vx.begin(), vx.end());
	vx.resize(unique(vx.begin(), vx.end()) - vx.begin());
	
	vector < pair <int, int> > w;
	for(int x : vx){
		for(int i = 0; i < n; i++)if(a[i] == x){
			for(int j = n - 1; j > i; j--)if(a[j] < x){
				w.push_back(make_pair(i + 1, j + 1));
			}
		}
	}
	
	printf("%d\n", (int)w.size());
	for(pair <int, int> p : w)
		printf("%d %d\n", p.first, p.second);
	
	return 0;
}