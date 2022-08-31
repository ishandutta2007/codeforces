import std.stdio, std.getopt, std.random, std.range, std.string, std.conv;
import std.algorithm;

const MD = 1_000_000_007;

int[] a, sum;
int n;

int[][] dp1;

int dfs(int x, int t) {
	//writeln("start", " ", gi, " ", i, " ", t, " ");
	if (t < 0) return 0;
	if (x == sum.length) {
		if (!t) return 1;
		else return 0;
	}
	if (dp1[x][t] != -1) return dp1[x][t];
	int res = dfs(x+1, t)+dfs(x, t-sum[x]);
	res %= MD;
/*	foreach (j; 0..(t+1)) {
		if (t-sum[x]*j < 0) break;
		res += dfs(gi, i+1, t-sum[x]*j);
		res %= MD;
	}*/
	//writeln(gi, " ", i, " ", t, " ", res);
	return dp1[x][t] = res;
}


int main(string[] args) {
	int n, q; long t;
	readf("%d %d %d\n", &n, &q, &t);
	sum = new int[n];
	a = readln().split().map!(to!int)().array;
	auto next = new int[n];
	auto back = new int[n];
	next[] = -1; back[] = -1;
	dp1 = new int[][](n, cast(int)(t+1));
	foreach (i; 0..n) {
		dp1[i][] = -1;
	}
	foreach (i; 0..q) {
		int b, c;
		readf("%d %d\n", &b, &c); b--; c--;
		next[b] = c;
		back[c] = b;
	}
	auto count = 0;
	foreach (i; 0..n) {
		if (next[i] > -1) continue;
		int j = i;
		int c = 0;
		count++;
		while (back[j] != -1) {
			j = back[j];
			c++;
			t -= c*a[j];
			count++;
		}
		sum[j] = a[j];
		while (next[j] != -1) {
			j = next[j];
			sum[j] = sum[back[j]] + a[j];
		}
	}
	if (count < n || t < 0) {
		writeln(0);
		return 0;
	}
//	writeln(g);
//	writeln(sum);
//	writeln(dp1);
//	writeln(t);
	writeln(dfs(0, cast(int)(t)));
	return 0;
}