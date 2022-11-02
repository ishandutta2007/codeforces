import java.math.BigInteger;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Tree {
	int nV;
	V[] vs;
	Scanner scan = new Scanner(System.in);

	void debug(Object... a) {
		System.out.println(Arrays.deepToString(a));
	}

	class V extends ArrayList<V> {
		BigInteger[] am;
		BigInteger best;

		void dfs(V p) {
			am = new BigInteger[nV + 1];
			Arrays.fill(am, BigInteger.ZERO);
			am[1] = BigInteger.ONE;
			for (V v : this)
				if (v != p) {
					v.dfs(this);
					BigInteger[] nam = new BigInteger[nV + 1];
					Arrays.fill(nam, BigInteger.ZERO);
					BigInteger[] ch = v.am;
					for (int a = 1; a <= nV; a++) {
						if (am[a].signum() == 0)
							break;
						for (int b = 1; a + b <= nV; b++) {
							if (ch[b].signum() == 0)
								break;
							BigInteger by = am[a].multiply(ch[b]);
							if (by.compareTo(nam[a + b]) > 0) {
								nam[a + b] = by;
							}
						}
						BigInteger by = am[a].multiply(v.best);
						if (by.compareTo(nam[a]) > 0) {
							nam[a] = by;
						}
					}
					am = nam;
				}
			best = BigInteger.ZERO;
			for (int i = 1; i <= nV; i++) {
				BigInteger by = BigInteger.valueOf(i).multiply(am[i]);
				if (by.compareTo(best) > 0) {
					best = by;
				}
			}
		}
	}

	void readInput() {
		nV = scan.nextInt();
		vs = new V[nV];
		for (int i = 0; i < nV; i++) {
			vs[i] = new V();
		}
		for (int i = 0; i < nV - 1; i++) {
			int a = scan.nextInt() - 1, b = scan.nextInt() - 1;
			vs[a].add(vs[b]);
			vs[b].add(vs[a]);
		}
	}

	void work() {
		vs[0].dfs(null);
		System.out.println(vs[0].best);
	}

	void genInput() {
		nV = 700;
		vs = new V[nV];
		for (int i = 0; i < nV; i++) {
			vs[i] = new V();
		}
		for (int i = 1; i < 700; i++) {
			vs[i].add(vs[i / 2]);
			vs[i / 2].add(vs[i]);
		}
	}

	void run() {
		readInput();
		// genInput();
		work();
	}

	static public void main(String[] args) {
		new Tree().run();
	}
}