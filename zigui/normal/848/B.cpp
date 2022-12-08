#include<stdio.h>
#include<cmath>
#include<stdlib.h>
#include<algorithm>
#include<vector>

using namespace std;

typedef pair<int,int> pii;

const int MX = 100005;
int N, W, H;

struct node{
	int g, p, t, ch;
	bool operator<(const node &l)const{
		return p-t < l.p - l.t;
	}
} D[MX];

pii ans[MX];

pii value(node n){
	if( n.g == 1 ) return pii(n.p, H);
	else return pii(W, n.p);
}

int main(){
	scanf("%d%d%d", &N, &W, &H);
	for(int i = 1; i <= N; i++){
		scanf("%d%d%d", &D[i].g, &D[i].p, &D[i].t);
		D[i].ch = i;
	}
	sort(D+1, D+N+1);
	for(int i = 1, j = 1; i <= N; i = j){
		for(; j <= N && D[i].t - D[i].p == D[j].t - D[j].p; j++);
		vector<node> L, M;
		for(int k = i; k < j; k++) L.push_back(D[k]);
		M = L;
		sort(L.begin(), L.end(), [](node l, node r){ return l.g != r.g? l.g > r.g : l.g == 2 ? l.p > r.p : l.p < r.p; });
		sort(M.begin(), M.end(), [](node l, node r){ return l.g != r.g? l.g < r.g : l.g == 1 ? l.p < r.p : l.p > r.p; });
		for(int k = 0; k < L.size(); k++){
			ans[L[k].ch] = value(M[k]);
		}
	}
	for(int i = 1; i <= N; i++) printf("%d %d\n", ans[i].first, ans[i].second);
}