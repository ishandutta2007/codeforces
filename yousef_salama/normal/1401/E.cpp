#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MAX = 1000000;
const int MAXM = 1000005;

int n, m, xi, yi, li, ri;

int tree1[MAXM], tree2[MAXM];
void add(int* tree, int u){
	u++;
	
	while(u < MAXM){
		tree[u]++;
		u += u & (-u);
	}
}
int sum(int* tree, int u){
	u++;
	
	int ret = 0;
	while(u > 0){
		ret += tree[u];
		u -= u & (-u);
	}
	return ret;
}

int main(){
	scanf("%d %d", &n, &m);
	
	int hc = 0;
	long long res = 1;
	
	vector < pair <int, int> > v1, v2;
	
	for(int i = 0; i < n; i++){
		scanf("%d %d %d", &yi, &li, &ri);
		
		if(li == 0 && ri == MAX){
			res++;
			hc++;
			v1.push_back(make_pair(yi, ri));
		}else if(li == 0){
			v1.push_back(make_pair(yi, ri));
		}else{
			v2.push_back(make_pair(yi, li));
		}
	}
	
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	
	vector < pair <int, pair <int, int> > > q1, q2, e1, e2;
	
	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &xi, &li, &ri);
		
		if(li == 0 && ri == MAX){
			res++;
			q1.push_back(make_pair(MAX, make_pair(xi, MAX)));
			q2.push_back(make_pair(MAX, make_pair(0, xi)));
		}else if(li == 0){
			q1.push_back(make_pair(ri, make_pair(xi, MAX)));
			q2.push_back(make_pair(ri, make_pair(0, xi)));
		}else{
			q1.push_back(make_pair(MAX, make_pair(xi, MAX)));
			q2.push_back(make_pair(MAX, make_pair(0, xi)));
			
			e1.push_back(make_pair(li - 1, make_pair(xi, MAX)));
			e2.push_back(make_pair(li - 1, make_pair(0, xi)));
		}
	}
	
	sort(q1.begin(), q1.end());
	sort(q2.begin(), q2.end());
	sort(e1.begin(), e1.end());
	sort(e2.begin(), e2.end());
	
	int j1 = 0, j2 = 0, jq1 = 0, jq2 = 0, je1 = 0, je2 = 0;
	for(int y = 0; y <= MAX; y++){
		while(j1 < (int)v1.size() && v1[j1].first <= y){
			add(tree1, v1[j1].second);
			j1++;
		}
		while(j2 < (int)v2.size() && v2[j2].first <= y){
			add(tree2, v2[j2].second);
			j2++;
		}
		
		while(jq1 < (int)q1.size() && q1[jq1].first == y){
			res += sum(tree1, q1[jq1].second.second) - sum(tree1, q1[jq1].second.first - 1); 
			jq1++;
		}
		while(jq2 < (int)q2.size() && q2[jq2].first == y){
			res += sum(tree2, q2[jq2].second.second) - sum(tree2, q2[jq2].second.first - 1);
			jq2++;
		}
		
		while(je1 < (int)e1.size() && e1[je1].first == y){
			res -= sum(tree1, e1[je1].second.second) - sum(tree1, e1[je1].second.first - 1);
			je1++;
		}
		while(je2 < (int)e2.size() && e2[je2].first == y){
			res -= sum(tree2, e2[je2].second.second) - sum(tree2, e2[je2].second.first - 1);
			je2++;
		}
	}
	printf("%lld\n", res);
	
	return 0;
}