import static java.math.BigInteger.valueOf;

import java.math.BigInteger;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class Sequence {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Sequence().run();
	}

	void debug(Object... o) {
		System.out.println(Arrays.deepToString(o));
	}

	class State {
		BigInteger cur, next;

		public State(BigInteger cur, BigInteger next) {
			// TODO Auto-generated constructor stub
			this.cur = cur;
			this.next = next;
		}

		@Override
		public int hashCode() {
			return cur.hashCode() * 13331 + next.hashCode();
		}

		@Override
		public boolean equals(Object obj) {
			State s = (State) obj;
			return cur.equals(s.cur) && next.equals(s.next);
		}
	}

	void run() {
		Scanner scan = new Scanner(System.in);
		BigInteger a = scan.nextBigInteger();
		Set<State> cur = new HashSet<Sequence.State>();
		cur.add(new State(valueOf(2), valueOf(13)));
		List<Integer> ids = new ArrayList<Integer>();
		Set<BigInteger> others = new HashSet<BigInteger>();

		for (int i = 1;; i++) {
			boolean ok = false;
			boolean impossible = true;
			for (State s : cur) {
				if (s.cur.equals(a)) {
					ok = true;
				}
				if (s.cur.compareTo(a) <= 0) {
					impossible = false;
				}
			}
			if (ok) {
				ids.add(i);
				for (State s : cur)
					others.add(s.cur);
			}
			if (impossible)
				break;

			Set<State> next = new HashSet<Sequence.State>();
			for (State s : cur) {
				next.add(new State(s.next, s.cur.multiply(valueOf(12))));
				next.add(new State(s.next, s.next.multiply(valueOf(13))
						.subtract(s.cur.multiply(valueOf(12)))));
			}
			cur = next;
		}

		if (ids.isEmpty()) {
			System.out.println("NO");
			return;
		}

		System.out.println("YES");
		System.out.println(ids.size());
		for (int i = 0; i < Math.min(1000, ids.size()); i++) {
			System.out.print(ids.get(i) + " ");
		}
		System.out.println();

		others.remove(a);
		BigInteger[] os = others.toArray(new BigInteger[0]);
		Arrays.sort(os);
		System.out.println(os.length);
		for (int i = 0; i < Math.min(1000, os.length); i++) {
			System.out.print(os[i] + " ");
		}
		System.out.println();
	}
}