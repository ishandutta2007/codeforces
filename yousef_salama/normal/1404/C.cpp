#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300005;

int n, q, a[MAXN], xi, yi;

vector <int> v[4 * MAXN];

void build(int i, int L, int R){
	if(L == R){
		if(a[L] == L){
			v[i].push_back(0);
		}else if(a[L] < L){
			v[i].push_back(L - a[L]);
		}
	}else{
		int mid = (L + R) / 2;
		
		build(2 * i, L, mid);
		build(2 * i + 1, mid + 1, R);
		
		int x = 0, y = 0, cz = 0;
		
		while(x < (int)v[2 * i].size() || y < (int)v[2 * i + 1].size()){
			if(x == (int)v[2 * i].size()){
				v[i].push_back(v[2 * i + 1][y] - cz);
				y++;
			}else if(y == (int)v[2 * i + 1].size()){
				v[i].push_back(v[2 * i][x]);
				x++;
			}else{
				if(v[2 * i][x] < v[2 * i + 1][y] - cz){
					v[i].push_back(v[2 * i][x]);
					x++;
					cz++;
				}else{
					v[i].push_back(v[2 * i + 1][y] - cz);
					y++;
				}
			}
		}
	}
}

void print(int i, int L, int R){
	cout << i << ' ' << L << ',' << R << ' ' << " ::: ";
	for(int e : v[i])cout << e << ' ';
	cout << endl;
	
	if(L < R){
		int mid = (L + R) / 2;
		print(2 * i, L, mid);
		print(2 * i + 1, mid + 1, R);
	}
}

int query(int i, int L, int R, int l, int r, int cz){
	if(r < L || R < l)return 0;
	
	if(l <= L && R <= r){
		int cur = upper_bound(v[i].begin(), v[i].end(), cz) - v[i].begin();
		return cur;
	}
	
	int mid = (L + R) / 2;
	
	int r1 = query(2 * i, L, mid, l, r, cz);
	int r2 = query(2 * i + 1, mid + 1, R, l, r, cz + r1);
	
	return (r1 + r2);
}

int main(){
	scanf("%d %d", &n, &q);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		a[i]--;
	}
		
	build(1, 0, n - 1);
	//print(1, 0, n - 1);
	
	while(q--){
		scanf("%d %d", &xi, &yi);
		printf("%d\n", query(1, 0, n - 1, xi, n - 1 - yi, 0));
	}
	
	return 0;
}