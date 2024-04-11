#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n, m, k, ki, ai, bi;
bool marked[MAXN];
vector <int> G[MAXN];

struct node{
	int index, degree, cdegree;
} A[MAXN];

bool operator <(node a, node b){
	long long x = 1LL * a.cdegree * b.degree - 1LL * b.cdegree * a.degree;
	if(x != 0)return x < 0;
	else return a.index < b.index;
}

int erased[MAXN];
int main(){
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < k; i++){
		scanf("%d", &ki);
		marked[ki - 1] = true;
	}

	for(int i = 0; i < m; i++){
		scanf("%d %d", &ai, &bi);
		ai--, bi--;

		G[ai].push_back(bi);
		G[bi].push_back(ai);
	}

	set <node> S;

	node r = {-1, 0, 1};
	for(int i = 0; i < n; i++)if(!marked[i]){
		int c = 0;
		for(int j : G[i])
			c += !marked[j];

		A[i] = {i, G[i].size(), c};
		if(A[i] < r)r = A[i];

		S.insert(A[i]);
		erased[i] = 1 << 30;
	}

	int t = 0, ct = 1;
	while(S.size() > 1){
		node cr = *S.begin();

		erased[cr.index] = ct;
		S.erase(cr);


		for(int j : G[cr.index]){
			auto d = S.lower_bound(A[j]);
			if(d != S.end() && d->index == j){
				S.erase(d);

				A[j].cdegree--;
				S.insert(A[j]);
			}
		}

		if(r < (*S.begin())){
			r = (*S.begin());
			t = ct;
		}

		ct++;
	}

	vector <int> v;
	for(int i = 0; i < n; i++)
		if(erased[i] > t)v.push_back(i + 1);

	printf("%d\n", v.size());
	for(int i = 0; i < v.size(); i++){
		if(i > 0)printf(" ");
		printf("%d", v[i]);
	}
	printf("\n");

	return 0;
}