#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
int n, s;
const int MAX_N = 100 + 10;
struct Segment {
	int speed, dur;
	Segment(int speed, int dur) :
			speed(speed), dur(dur) {
	}
};
struct Car {
	vector<Segment> segments;
	void read() {
		int k;
		cin >> k;
		for (int i = 0; i < k; ++i) {
			int s, d;
			cin >> s >> d;
			segments.push_back(Segment(s, d));
		}
	}
};

int main() {
	cin >> n >> s;
	vector<Car> cars(n);
	for (int i = 0; i < n; ++i) {
		cars[i].read();
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			Car&a = cars[i], &b = cars[j];
			//calc answer for a and b
			int x = 0, y = 0;
			int atx = 0, aty = 0;
			int wx = 0, wy = 0;
			while (x < a.segments.size() && y < b.segments.size()) {
				Segment&sa = a.segments[x], &sb = b.segments[y];
				int rema = sa.dur - atx, remb = sb.dur - aty;
				int rem = min(rema, remb);
				if (rem == 0) {
					if (rema == 0)
						atx = 0, x++;
					if (remb == 0)
						aty = 0, y++;
					continue;
				}
				int nwx = wx + rem * sa.speed, nwy = wy + rem * sb.speed;
				if (wx != wy && nwx != nwy && (wx < wy) != (nwx < nwy)) {
					++ans;
				}
				wx = nwx, wy = nwy;
				atx += rem, aty += rem;
				//check nwx
				if (nwx == nwy && nwx < s) {
					int nspa = sa.speed;
					if (atx == sa.dur)
						nspa = a.segments[x + 1].speed;
					int nspb = sb.speed;
					if (aty == sb.dur)
						nspb = b.segments[y + 1].speed;
					if ((sa.speed < sb.speed) == (nspa < nspb))
						++ans;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}