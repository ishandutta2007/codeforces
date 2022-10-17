// boring writing. Copy from others; 

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using std::max;
const int N = 300011;
int n, pedge, root, rootSize, pblock, size[N], head[N], v2b[N], block[N], lef[N], rig[N];
bool used[N];
struct Edge{
	int ver, w, nex;
}edge[N * 2 + 1];

long long __[N], _ = 0;
void mulab(int u, int _fa){
	_ += __[u];
	for(int i = head[u]; i; i = edge[i].nex){
		int v = edge[i].ver, w = edge[i].w;
		if(v != _fa){
			__[v] = __[u] + w;
			mulab(v, u);
		}
	}
}
long long calc(int root){
	__[root] = 0;
	mulab(root, 0);
	return 2 * _;
}

struct List : public std::vector<int>{
	int last(){
		return size() ? back() : n + 1;
	}
	int pop(){
		int a = back();
		pop_back();
		return a;
	}
}b2v[N];

struct TTree{
	int tree[N * 2 + 1];
	bool (*cmp)(int, int);
	void init(){
		for(int i = 1; i <= pblock; i++)
			tree[i + pblock - 1] = i;
		for(int i = pblock - 1; i >= 1; i--)
			tree[i] = cmp(tree[i << 1], tree[(i << 1) | 1]) ? tree[i << 1] : tree[(i << 1) | 1];
	}
	int root(){
		return tree[1];
	}
	void update(int a){
		for(int i = (a + pblock - 1) >> 1; i >= 1; i >>= 1)
			tree[i] = cmp(tree[i << 1], tree[(i << 1) | 1]) ? tree[i << 1] : tree[(i << 1) | 1];
	}
	void hide(int a){
		//printf("hide %d\n", a);
		tree[a + pblock - 1] = 0;
		update(a);
		// for(int i = 1; i <= pblock * 2 - 1; i++)
		// 	printf("%d ", tree[i]);
		// printf("tree\n");
	}
	void show(int a){
		tree[a + pblock - 1] = a;
		update(a);
	}
}restT, numT;

bool restCmp(int a, int b){
	return lef[a] + rig[a] > lef[b] + rig[b];
}

bool numCmp(int a, int b){
	return b2v[a].last() < b2v[b].last();
}

void ins(int u, int v, int w){
	pedge ++;
	edge[pedge].ver = v, edge[pedge].w = w, edge[pedge].nex = head[u];
	head[u] = pedge;
}

void init(){
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		ins(u, v, w); ins(v, u, w);
	}
	rootSize = n + 1;
}

void dfs(int a){
	int ma = 0;
	size[a] = 1;
	for(int i = head[a]; i; i = edge[i].nex)
		if(!size[edge[i].ver]){
			dfs(edge[i].ver);
			size[a] += size[edge[i].ver];
			ma = max(ma, size[edge[i].ver]);
		}
	ma = max(ma, n - size[a]);
	if(rootSize > ma){
		rootSize = ma;
		root = a;
	}
}

void redfs(int a){
	v2b[a] = pblock;
	block[pblock]++;
	b2v[pblock].push_back(a);
	for(int i = head[a]; i; i = edge[i].nex)
		if(!v2b[edge[i].ver])
			redfs(edge[i].ver);
}

void rebuild(){
	lef[1] = rig[1] = block[1] = v2b[root] = pblock = 1;
	b2v[1].push_back(root);
	for(int i = head[root]; i; i = edge[i].nex){
		pblock++;
		redfs(edge[i].ver);
		std::sort(b2v[pblock].begin(), b2v[pblock].end(), [](int a, int b){
			return a > b;
		});
		lef[pblock] = rig[pblock] = block[pblock];
	}
//	fprintf(stderr, "root = %d\n", root);
	// for(int i = 1; i <= pblock; i++)
	// 	printf("%d ", rig[i]);
	// printf("block\n");
	// for(int i = 1; i <= pblock; i++){
	// 	for(auto j : b2v[i])
	// 		printf("%d ", j);
	// 	printf("| block[%d]\n", i);
	// }
}

void solve(){
	printf("%lld\n", calc(root));
	restT.cmp = restCmp;
	restT.init();
	numT.cmp = numCmp;
	numT.init();
	for(int i = 1; i <= n; i++){
		//printf("step = %d\n", i);
		restT.hide(v2b[i]);
		int rt = restT.root(), ans;
		restT.show(v2b[i]);
		//printf("rt = %d lef = %d rig = %d eq = %d\n", rt, lef[rt], rig[rt], n - i + 1);
		if(rt != 1 && lef[rt] + rig[rt] == n - i + 1){
			ans = b2v[rt].pop();
			numT.update(rt);
		}else{
			//printf("v2b = %d\n", v2b[i]);
			if(v2b[i] != 1){
				numT.hide(v2b[i]);
				rt = numT.root();
				numT.show(v2b[i]);
			}else
				rt = numT.root();
			//printf("rt = %d\n", rt);fflush(stdout);
			ans = b2v[rt].pop();
			numT.update(rt);
		}
		lef[v2b[i]]--;
		restT.update(v2b[i]);
		rig[v2b[ans]]--;
		restT.update(v2b[ans]);
		printf("%d%c", ans, " \n"[i == n]);
		// printf("##\n");
		// for(int i = 1; i <= pblock; i++){
		// 	for(auto j : b2v[i])
		// 		printf("%d ", j);
		// 	printf("| block[%d]\n", i);
		// }
	}
}

int main(){
	init();
	dfs(1);
	rebuild();
	solve();
	return 0;
}