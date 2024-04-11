import java.io.*;
import java.util.*;
import java.math.*;

import javax.management.MalformedObjectNameException;

public class B implements Runnable {
	private static BufferedReader in;
	private static PrintWriter out;
	private static StringTokenizer st;
	private static Random rnd;

	static class Edge {
		int to, type;

		public Edge(int to, int type) {
			this.to = to;
			this.type = type;
		}
	}

	final static long MODULO = 1000000000 + 7;

	static class Tree {
		final int MAXLOG = 20;

		int verticesCount;
		List<Edge>[] edges;
		int[] distanceToTop, heights;
		int[] downLevels, upLevels;
		int[][] lca;
		long resultDown, resultUp;

		Tree(int verticesCount) {
			this.verticesCount = verticesCount;
			this.edges = new ArrayList[verticesCount];
			this.downLevels = new int[verticesCount];
			this.upLevels = new int[verticesCount];
			for (int i = 0; i < verticesCount; i++)
				this.edges[i] = new ArrayList<>();
		}

		void addEdge(int from, int to, int type) {
			this.edges[from].add(new Edge(to, type));
		}

		void build() {
			heights = new int[verticesCount];
			lca = new int[verticesCount][MAXLOG];
			dfs(0, -1, 0);
		}

		private void dfs(int u, int parent, int height) {
			heights[u] = height;
			Arrays.fill(lca[u], -1);
			lca[u][0] = parent;
			for (int i = 1; i < MAXLOG; i++) {
				int v = lca[u][i - 1];
				if (v != -1) {
					lca[u][i] = lca[v][i - 1];
				}
			}
			for (Edge e : edges[u]) {
				if (e.to != parent) {
					dfs(e.to, u, height + 1);
				}
			}
		}

		private int lca(int u, int v) {
			if (heights[u] < heights[v]) {
				int t = u;
				u = v;
				v = t;
			}
			if (heights[u] > heights[v]) {
				for (int i = MAXLOG - 1; i >= 0; i--) {
					int j = (1 << i);
					if (heights[u] - j >= heights[v]) {
						u = lca[u][i];
					}
				}
			}
			if (heights[u] != heights[v])
				throw new AssertionError();
			if (u == v)
				return u;
			for (int i = MAXLOG - 1; i >= 0; i--) {
				int a = lca[u][i], b = lca[v][i];
				if (a != b) {
					u = a;
					v = b;
				}
			}
			u = lca[u][0];
			v = lca[v][0];
			if (u != v || u == -1 || v == -1)
				throw new AssertionError();
			return u;
		}

		public void update(int from, int to) {
			if (from == to)
				return;

			// out.println("Update: " + from + " " + to);
			// out.flush();

			int lca = lca(from, to);

			if (lca == from) {
				updateDown(from, to);
			} else if (lca == to) {
				updateUp(to, from);
			} else {
				updateUp(lca, from);
				updateDown(lca, to);
			}
		}

		private void updateDown(int from, int to) {
			if (heights[from] > heights[to])
				throw new AssertionError();
			downLevels[from] -= 1;
			downLevels[to] += 1;
		}

		private void updateUp(int from, int to) {
			if (heights[from] > heights[to])
				throw new AssertionError();
			upLevels[from] -= 1;
			upLevels[to] += 1;
		}

		public long getAns() {
			dfsUp(0, -1);
			dfsDown(0, -1);
			return (resultDown + resultUp) % MODULO;
		}

		private int dfsUp(int u, int parent) {
			int result = 0;

			for (Edge e : edges[u]) {
				if (e.to != parent) {
					int levels = dfsUp(e.to, u);
					if (e.type == 1) {
						resultUp += getPow(2, levels) - 1;
					}
					result += levels;
				}
			}

			return result + upLevels[u];
		}

		private int dfsDown(int u, int parent) {
			int result = 0;

			for (Edge e : edges[u]) {
				if (e.to != parent) {
					int levels = dfsDown(e.to, u);
					if (e.type == -1) {
						resultDown += getPow(2, levels) - 1;
					}
					result += levels;
				}
			}

			return result + downLevels[u];
		}
	}

	private static long getPow(long n, int p) {
		long result = 1;
		while (p != 0) {
			if ((p & 1) != 0)
				result = (result * n) % MODULO;
			n = (n * n) % MODULO;
			p >>= 1;
		}
		return result;
	}

	private void solve() throws IOException {
		int verticesCount = nextInt();
		Tree sourceTree = new Tree(verticesCount);
		for (int i = 0; i < verticesCount - 1; i++) {
			int from = nextInt() - 1, to = nextInt() - 1, type = nextInt();
			if (type == 0) {
				sourceTree.addEdge(from, to, 0);
				sourceTree.addEdge(to, from, 0);
			} else {
				sourceTree.addEdge(from, to, type);
				sourceTree.addEdge(to, from, type - 2);
			}
		}
		sourceTree.build();
		int currentVertex = 0;
		int queriesCount = nextInt();
		for (int q = 0; q < queriesCount; q++) {
			int vertex = nextInt() - 1;
			sourceTree.update(currentVertex, vertex);
			currentVertex = vertex;
		}
		long result = sourceTree.getAns();
		if (result < 0)
			result += MODULO;
		result %= MODULO;
		out.println(result);
	}

	public static void main(String[] args) {
		new B().run();
	}

	public void run() {
		try {
			final String className = this.getClass().getName().toLowerCase();

			try {
				in = new BufferedReader(new FileReader(className + ".in"));
				out = new PrintWriter(new FileWriter(className + ".out"));
				// in = new BufferedReader(new FileReader("input.txt"));
				// out = new PrintWriter(new FileWriter("output.txt"));
			} catch (FileNotFoundException e) {
				in = new BufferedReader(new InputStreamReader(System.in));
				out = new PrintWriter(System.out);
			}

			rnd = new Random();

			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(42);
		}
	}

	private String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = in.readLine();

			if (line == null)
				return null;

			st = new StringTokenizer(line);
		}

		return st.nextToken();
	}

	private int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	private long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	private double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}