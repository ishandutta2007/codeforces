#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef long double ld; 

const ll INF = ll(2e18);
const ll MOD = 1e9 + 7;

#define root 0
#define N 200001
#define LN 18

vector <ll> adj[N], costs[N], indexx[N];
ll baseArray[N], ptr;
int chainNo, chainInd[N], chainHead[N], posInBase[N];
int depth[N], pa[LN][N], otherEnd[N], subsize[N];
ll st[N*4], qt[N*4];

ll mult(ll a, ll b)
{
	if(a > INF/b)
	{
		return INF;
	}
	else
	{
		return a*b;
	}
}

/*
 * make_tree:
 * Used to construct the segment tree. It uses the baseArray for construction
 */
void make_tree(ll cur, ll s, ll e) {
	if(s == e-1) {
		st[cur] = baseArray[s];
		return;
	}
	ll c1 = (cur<<1), c2 = c1 | 1, m = (s+e)>>1;
	make_tree(c1, s, m);
	make_tree(c2, m, e);
	st[cur] = mult(st[c1], st[c2]);
}

/*
 * update_tree:
 * Poll update. Update a single element of the segment tree.
 */
void update_tree(ll cur, ll s, ll e, ll x, ll val) {
	if(s > x || e <= x) return;
	if(s == x && s == e-1) {
		st[cur] = val;
		return;
	}
	ll c1 = (cur<<1), c2 = c1 | 1, m = (s+e)>>1;
	update_tree(c1, s, m, x, val);
	update_tree(c2, m, e, x, val);
	st[cur] = mult(st[c1], st[c2]);
}

/*
 * query_tree:
 * Given S and E, it will return the maximum value in the range [S,E)
 */
void query_tree(ll cur, ll s, ll e, ll S, ll E) {
	if(s >= E || e <= S) {
		qt[cur] = 1;
		return;
	}
	if(s >= S && e <= E) {
		qt[cur] = st[cur];
		return;
	}
	ll c1 = (cur<<1), c2 = c1 | 1, m = (s+e)>>1;
	query_tree(c1, s, m, S, E);
	query_tree(c2, m, e, S, E);
	qt[cur] = mult(qt[c1], qt[c2]);
}

/*
 * query_up:
 * It takes two nodes u and v, condition is that v is an ancestor of u
 * We query the chain in which u is present till chain head, then move to next chain up
 * We do that way till u and v are in the same chain, we query for that part of chain and break
 */

ll query_up(ll u, ll v) {
	if(u == v) return 1; // Trivial
	ll uchain, vchain = chainInd[v], ans = 1;
	// uchain and vchain are chain numbers of u and v
	while(1) {
		uchain = chainInd[u];
		if(uchain == vchain) {
			// Both u and v are in the same chain, so we need to query from u to v, update answer and break.
			// We break because we came from u up till v, we are done
			if(u==v) break;
			query_tree(1, 0, ptr, posInBase[v]+1, posInBase[u]+1);
			// Above is call to segment tree query function
			ans = mult(ans, qt[1]); // Update answer
			break;
		}
		query_tree(1, 0, ptr, posInBase[chainHead[uchain]], posInBase[u]+1);
		// Above is call to segment tree query function. We do from chainHead of u till u. That is the whole chain from
		// start till head. We then update the answer
		ans = mult(ans, qt[1]);
		u = chainHead[uchain]; // move u to u's chainHead
		u = pa[0][u]; //Then move to its parent, that means we changed chains
	}
	return ans;
}

/*
 * LCA:
 * Takes two nodes u, v and returns Lowest Common Ancestor of u, v
 */
ll LCA(ll u, ll v) {
	if(depth[u] < depth[v]) swap(u,v);
	ll diff = depth[u] - depth[v];
	for(ll i=0; i<LN; i++) if( (diff>>i)&1 ) u = pa[i][u];
	if(u == v) return u;
	for(ll i=LN-1; i>=0; i--) if(pa[i][u] != pa[i][v]) {
		u = pa[i][u];
		v = pa[i][v];
	}
	return pa[0][u];
}

ll query(ll u, ll v) {
	/*
	 * We have a query from u to v, we break it llo two queries, u to LCA(u,v) and LCA(u,v) to v
	 */
	ll lca = LCA(u, v);
	//printf("%lld\n", lca);
	ll ans = query_up(u, lca); // One part of path
	//printf("%lld %lld\n", lca, ans);
	ll temp = query_up(v, lca); // another part of path
	ans = mult(ans, temp);
	return ans;
}

/*
 * change:
 * We just need to find its position in segment tree and update it
 */
void change(ll i, ll val) {
	ll u = otherEnd[i];
	update_tree(1, 0, ptr, posInBase[u], val);
}

/*
 * Actual HL-Decomposition part
 * Initially all entries of chainHead[] are set to -1.
 * So when ever a new chain is started, chain head is correctly assigned.
 * As we add a new node to chain, we will note its position in the baseArray.
 * In the first for loop we find the child node which has maximum sub-tree size.
 * The following if condition is failed for leaf nodes.
 * When the if condition passes, we expand the chain to special child.
 * In the second for loop we recursively call the function on all normal nodes.
 * chainNo++ ensures that we are creating a new chain for each normal child.
 */
void HLD(ll curNode, ll cost, ll prev) {
	if(chainHead[chainNo] == -1) {
		chainHead[chainNo] = curNode; // Assign chain head
	}
	chainInd[curNode] = chainNo;
	posInBase[curNode] = ptr; // Position of this node in baseArray which we will use in Segtree
	baseArray[ptr++] = cost;

	ll sc = -1, ncost;
	// Loop to find special child
	for(ll i=0; i<adj[curNode].size(); i++) if(adj[curNode][i] != prev) {
		if(sc == -1 || subsize[sc] < subsize[adj[curNode][i]]) {
			sc = adj[curNode][i];
			ncost = costs[curNode][i];
		}
	}

	if(sc != -1) {
		// Expand the chain
		HLD(sc, ncost, curNode);
	}

	for(ll i=0; i<adj[curNode].size(); i++) if(adj[curNode][i] != prev) {
		if(sc != adj[curNode][i]) {
			// New chains at each normal node
			chainNo++;
			HLD(adj[curNode][i], costs[curNode][i], curNode);
		}
	}
}

/*
 * dfs used to set parent of a node, depth of a node, subtree size of a node
 */
void dfs(ll cur, ll prev, ll _depth=0) {
	pa[0][cur] = prev;
	depth[cur] = _depth;
	subsize[cur] = 1;
	for(ll i=0; i<adj[cur].size(); i++)
		if(adj[cur][i] != prev) {
			otherEnd[indexx[cur][i]] = adj[cur][i];
			dfs(adj[cur][i], cur, _depth+1);
			subsize[cur] += subsize[adj[cur][i]];
		}
}

int main() 
{
	ptr = 0;
	ll n, q;
	scanf("%lld %lld", &n, &q);
	// Cleaning step, new test case
	for(ll i=0; i<n; i++) {
		adj[i].clear();
		costs[i].clear();
		indexx[i].clear();
		chainHead[i] = -1;
		for(ll j=0; j<LN; j++) pa[j][i] = -1;
	}
	for(ll i=1; i<n; i++) {
		ll u, v, c;
		scanf("%lld %lld %lld", &u, &v, &c);
		u--; v--;
		adj[u].push_back(v);
		costs[u].push_back(c);
		indexx[u].push_back(i-1);
		adj[v].push_back(u);
		costs[v].push_back(c);
		indexx[v].push_back(i-1);
	}
	chainNo = 0;
	dfs(root, -1); // We set up subsize, depth and parent for each node
	HLD(root, -1, -1); // We decomposed the tree and created baseArray
	make_tree(1, 0, ptr); // We use baseArray and construct the needed segment tree
		// Below Dynamic programming code is for LCA.
	for(ll i=1; i<LN; i++)
		for(ll j=0; j<n; j++)
			if(pa[i-1][j] != -1)
				pa[i][j] = pa[i-1][pa[i-1][j]];
	for(int i = 0; i < q; i++)
	{
		int t;
		scanf("%d", &t);
		ll a, b, c;
		scanf("%lld %lld", &a, &b);
		if(t == 1)
		{
			scanf("%lld", &c);
		}
		//printf("%d %lld %lld %lld\n", t, a, b, c);
		if(t == 1)
		{
			ll ans = query(a-1, b-1);
			//printf("%lld\n", ans);
			printf("%lld\n", c/ans);
		} 
		else 
		{
			change(a-1, b);
		}
	}
}