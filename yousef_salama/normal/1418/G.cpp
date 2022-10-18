#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500005;

pair <int, int> tree[4 * MAXN];
int flag[4 * MAXN];

pair <int, int> combine(const pair <int, int>& a, const pair <int, int>& b){
	if(a.first > b.first)return a;
	if(a.first < b.first)return b;
	return make_pair(a.first, a.second + b.second);
}
void init(int i, int L, int R, int val){
	if(L == R){
		tree[i] = make_pair(val, 1);
		return;
	}
	
	int mid = (L + R) / 2;
	
	init(2 * i, L, mid, val);
	init(2 * i + 1, mid + 1, R, val);
	
	tree[i] = combine(tree[2 * i], tree[2 * i + 1]);
}
void push(int i, int L, int R){
	if(L < R){
		flag[2 * i] += flag[i];
		flag[2 * i + 1] += flag[i];
	}
	tree[i].first += flag[i];
	flag[i] = 0;
}
void update(int i, int L, int R, int u, int v, int val){
	push(i, L, R);
	if(v < L || R < u)return;
	if(u <= L && R <= v){
		flag[i] += val;
		push(i, L, R);
		return;
	}
	
	int mid = (L + R) / 2;
	
	update(2 * i, L, mid, u, v, val);
	update(2 * i + 1, mid + 1, R, u, v, val);
	
	tree[i] = combine(tree[2 * i], tree[2 * i + 1]);
}
pair <int, int> query(int i, int L, int R, int u, int v){
	push(i, L, R);
	if(v < L || R < u)return make_pair(-1, 0);
	if(u <= L && R <= v)return tree[i];
	
	int mid = (L + R) / 2;
	return combine(query(2 * i, L, mid, u, v), query(2 * i + 1, mid + 1, R, u, v));
}

void print(int i, int L, int R, bool line = true){
	push(i, L, R);
	
	if(L == R){
		cout << tree[i].first << ',' << tree[i].second;
		return;
	}
	
	int mid = (L + R) / 2;
	print(2 * i, L, mid, false);
	cout << " ";
	print(2 * i + 1, mid + 1, R, false);
	if(line)cout << endl;
}

int main(){
	int n;
	scanf("%d", &n);
	
	vector < vector <int> > v(n); 
	init(1, 0, n - 1, n);
	
	vector <int> a(n);
	long long res = 0;
	
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		a[i]--;
		
		if(v[a[i]].empty())update(1, 0, n - 1, 0, i, -1);
		else update(1, 0, n - 1, v[a[i]].back() + 1, i, -1);
		
		v[a[i]].push_back(i);
		if(v[a[i]].size() >= 3){
			int j = (int)v[a[i]].size() - 3;
			
			if(j == 0)update(1, 0, n - 1, 0, v[a[i]][j], 1);
			else{
				update(1, 0, n - 1, v[a[i]][j - 1] + 1, v[a[i]][j], 1);
				
				j--;
				if(j == 0)update(1, 0, n - 1, 0, v[a[i]][j], -1);
				else update(1, 0, n - 1, v[a[i]][j - 1] + 1, v[a[i]][j], -1);
			}
		}
		
		//print(1, 0, n - 1);
		
		pair <int, int> r = query(1, 0, n - 1, 0, i);
		if(r.first == n)res += r.second;
	}
	printf("%lld\n", res);
	
	return 0;
}