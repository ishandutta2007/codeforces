import std.stdio, std.getopt, std.random, std.range, std.string, std.conv;
import std.algorithm, std.container, std.datetime;

int n, m, d;
bool[] isE;
int[][] g;
int md, mv;
int[] dps;
void dfs(int v, int b, int dp) {
	if (isE[v] && md < dp) {
		md = dp;
		mv = v;
	}
	dps[v] = dp;
	foreach (u; g[v]) {
		if (u == b) continue;
		dfs(u, v, dp+1);
	}
}

void dfs2(int v, int b, int dp) {

}
int solve() {
	readf("%d %d %d\n", &n, &m, &d);
	auto p = readln().split().map!(s => to!int(s)-1).array;
	isE.length = n;
	foreach (u; p) {
		isE[u] = true;
	}
	g.length = n;
	foreach (i; 0..n-1) {
		int a, b;
		readf("%d %d\n", &a, &b); a--; b--;
		g[a] ~= b;
		g[b] ~= a;
	}
	dps.length = n;
	md = mv = -1;
	dfs(p[0], -1, 0);
	auto v = mv;
	md = mv = -1;
	dfs(v, -1, 0);
	auto dp1 = dps.dup;
	dfs(mv, -1, 0);
	auto dp2 = dps.dup;
	int res = 0;
	foreach (i; 0..n) {
		if (dp1[i] <= d && dp2[i] <= d) {
			res++;
		}
	}
//	if (md > d*2) return 0;
	return res;
}

int main() {
	writeln(solve());
    return 0;
}