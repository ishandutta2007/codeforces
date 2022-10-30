import java.awt.geom.Area;
import java.awt.geom.Path2D;
import java.awt.geom.PathIterator;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
	Scanner scan = new Scanner(System.in);

	void debug(Object... o) {
		System.out.println(Arrays.deepToString(o));
	}

	void run() {
		int n = scan.nextInt();
		Area all = new Area();
		double total = 0;
		for (int i = 0; i < n; i++) {
			double[] ps = new double[8];
			for (int j = 0; j < 8; j++) {
				ps[j] = scan.nextDouble();
			}
			Area cur = makeArea(ps);
			total += evalArea(cur);
			all.add(cur);
		}
		System.out.println(total / evalArea(all));
	}

	Area makeArea(double[] ps) {
		Path2D.Double p = new Path2D.Double();
		p.moveTo(ps[0], ps[1]);
		for (int i = 2; i < ps.length; i += 2)
			p.lineTo(ps[i], ps[i + 1]);
		p.closePath();
		return new Area(p);
	}

	double evalArea(Area a) {
		double ret = 0;
		PathIterator iter = a.getPathIterator(null);
		double[] buffer = new double[6];
		List<Double> ps = new ArrayList<Double>();
		while (!iter.isDone()) {
			switch (iter.currentSegment(buffer)) {
			case PathIterator.SEG_MOVETO:
			case PathIterator.SEG_LINETO:
				ps.add(buffer[0]);
				ps.add(buffer[1]);
				break;
			case PathIterator.SEG_CLOSE:
				ps.add(ps.get(0));
				ps.add(ps.get(1));
				Double[] qs = ps.toArray(new Double[0]);
				for (int i = 0; i + 2 < ps.size(); i += 2) {
					ret -= qs[i] * qs[i + 3] - qs[i + 1] * qs[i + 2];
				}
				ps.clear();
				break;
			}
			iter.next();
		}
		return ret;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Main().run();
	}
}