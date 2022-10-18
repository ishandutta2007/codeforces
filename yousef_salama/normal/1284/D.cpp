#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

struct triplet{
	int key, L, R;
	triplet(int key, int L, int R): key(key), L(L), R(R){}
};
bool operator <(triplet a, triplet b){
	return a.key < b.key;
}

int n, a1[MAXN], b1[MAXN], a2[MAXN], b2[MAXN];
vector <triplet> A, B;

vector <int> tree[4 * MAXN][4];
void build(int i, int L, int R){
	if(L == R){
		tree[i][0].push_back(A[L].L);
		tree[i][1].push_back(A[L].R);
		tree[i][2].push_back(B[L].L);
		tree[i][3].push_back(B[L].R);
	}else{
		int mid = (L + R) / 2;
		
		build(2 * i, L, mid);
		build(2 * i + 1, mid + 1, R);
		
		merge(tree[2 * i][0].begin(), tree[2 * i][0].end(), tree[2 * i + 1][0].begin(), tree[2 * i + 1][0].end(),
			back_inserter(tree[i][0]));
		merge(tree[2 * i][1].begin(), tree[2 * i][1].end(), tree[2 * i + 1][1].begin(), tree[2 * i + 1][1].end(),
			back_inserter(tree[i][1]));
		merge(tree[2 * i][2].begin(), tree[2 * i][2].end(), tree[2 * i + 1][2].begin(), tree[2 * i + 1][2].end(),
			back_inserter(tree[i][2]));
		merge(tree[2 * i][3].begin(), tree[2 * i][3].end(), tree[2 * i + 1][3].begin(), tree[2 * i + 1][3].end(),
			back_inserter(tree[i][3]));
	}
}

int cntA(int i, int L, int R, int u, int a, int b){
	if(b < a)return 0;
	
	if(R < u)return 0;
	if(L >= u){
		int c1 = upper_bound(tree[i][0].begin(), tree[i][0].end(), b) - tree[i][0].begin();
		int c2 = lower_bound(tree[i][1].begin(), tree[i][1].end(), a) - tree[i][1].begin();
		/*
		cout << "===> ";
		for(int x : tree[i][0])
			cout << x << ' ';
		cout << endl;
		cout << ">>>>> " << L << ',' << R << ' ' << u << ',' << a << ',' << b << ' ' << c1 << ',' << c2 << endl;
		*/
		return (R - L + 1) - c1 + c2;
	}
	
	int mid = (L + R) / 2;
	return cntA(2 * i, L, mid, u, a, b) + cntA(2 * i + 1, mid + 1, R, u, a, b);
}
int cntB(int i, int L, int R, int u, int a, int b){
	if(b < a)return 0;
	
	if(L > u)return 0;
	if(R <= u){
		int c1 = upper_bound(tree[i][2].begin(), tree[i][2].end(), b) - tree[i][2].begin();
		int c2 = lower_bound(tree[i][3].begin(), tree[i][3].end(), a) - tree[i][3].begin();
		
		return (R - L + 1) - c1 + c2;
	}
	
	int mid = (L + R) / 2;
	return cntB(2 * i, L, mid, u, a, b) + cntB(2 * i + 1, mid + 1, R, u, a, b);
}

bool solve(){
	A.clear();
	B.clear();
	
	for(int i = 0; i < 4 * MAXN; i++)
	for(int j = 0; j < 4; j++)
		tree[i][j].clear();
	
	for(int i = 0; i < n; i++){
		A.push_back(triplet(a1[i], a2[i], b2[i]));
		B.push_back(triplet(b1[i], a2[i], b2[i]));
	}
	
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	
	build(1, 0, n - 1);
	
	bool ok = true;
	for(int i = 0; i < n; i++){
		int jA = upper_bound(A.begin(), A.end(), triplet(b1[i], 0, 0)) - A.begin();
		if(n - jA != cntA(1, 0, n - 1, jA, a2[i], b2[i])){
			ok = false;
			break;
		}
		
		int jB = lower_bound(B.begin(), B.end(), triplet(a1[i], 0, 0)) - B.begin();
		if(jB != cntB(1, 0, n - 1, jB - 1, a2[i], b2[i])){
			ok = false;
			break;
		}
		/*
		cout << ok << " ==== " << a1[i] << ',' << b1[i] << ' ' << a2[i] << ',' << b2[i] << ' ' << jA << '-' << jB << endl;
		cout << cntA(1, 0, n - 1, jA, a2[i], b2[i]) << ' ' << cntB(1, 0, n - 1, jB - 1, a2[i], b2[i]) << endl;
		*/
	}
	
	return ok;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d %d %d %d", &a1[i], &b1[i], &a2[i], &b2[i]);
	
	if(!solve())printf("NO\n");
	else{
		for(int i = 0; i < n; i++){
			swap(a1[i], a2[i]);
			swap(b1[i], b2[i]);
		}
		if(!solve())printf("NO\n");
		else printf("YES\n");
	}
	
	return 0;
}