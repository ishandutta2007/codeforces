#include <stdio.h>
#include <algorithm>
int ss, mm, hh, dd, dat, mon;
int n;
inline bool is_leap_year(int x) {
	return (x % 4 == 0 && x % 100 != 0) || x % 400 == 0;
}
int days_in_month[2][15] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
inline bool check_day(int m, int d, int day) {
		if (m != mon && mon != -1) return false;
	if (dd == -1) {
		return d == dat || dat == -1;
	} else if (dat == -1) {
		return day == dd || dd == -1;
	} else {
		return d == dat || day == dd;
	}
}

long long get_next(long long t0) {
	++t0;
	int now_year = 1970;
	// thursday 1970.1.1
	int day = 3;
	day = (day + t0 / 86400) % 7;
	long long _t0 = t0;
	while (1) {
		int tmp = is_leap_year(now_year) ? 86400 * 366 : 86400 * 365;
		if (t0 >= tmp) {
			t0 -= tmp;
			++now_year;
		} else {
			break;
		}
	}
	bool leap = is_leap_year(now_year);
	int now_month = 1;
	while (1) {
		int tmp = 86400 * days_in_month[leap][now_month];
		if (t0 >= tmp) {
			t0 -= tmp;
			++now_month;
		} else {
			break;
		}
	}
	int now_day = 1 + t0 / 86400;
	t0 %= 86400;
	
	// printf("%d/%d/%d  %d\n", now_year, now_month, now_day, day);
	
	if (check_day(now_month, now_day, day)) {
		int now_h = t0 / 3600;
		int now_m = t0 % 3600 / 60;
		int now_s = t0 % 60;
		L_h:
		while (hh != -1 && now_h != hh && now_h < 24) {
			++now_h, now_m = now_s = 0;
			if (now_h >= 24) break;
		}
		if (now_h < 24) {
			while (mm != -1 && now_m != mm && now_m < 60) {
				++now_m, now_s = 0;
				if (now_m >= 60) break;
			}
			if (now_m >= 60) {
				++now_h, now_m = now_s = 0;
				goto L_h;
			} else {
				while (ss != -1 && now_s != ss && now_s < 60) {
					++now_s;
					if (now_s >= 60) break;
				}
				if (now_s >= 60) {
					now_s = 0, ++now_m;
					goto L_h;
				} else {
					return _t0 - _t0 % 86400 + now_h * 3600 + now_m * 60 + now_s;
				}
			}
		}
	}
	
	while (1) {
		if (++now_day > days_in_month[leap][now_month]) {
			now_day = 1;
			if (++now_month > 12) {
				++now_year;
				now_month = 1;
				leap = is_leap_year(now_year);
			}
		}
		_t0 += 86400;
		day = (day + 1) % 7;
		if (check_day(now_month, now_day, day)) break;
	}
	return _t0 - _t0 % 86400 + std::max(0, hh) * 3600 + std::max(0, mm) * 60 + std::max(0, ss);
}
int main() {
	scanf("%d%d%d%d%d%d", &ss, &mm, &hh, &dd, &dat, &mon);
	if (dd != -1) --dd;
	scanf("%d", &n);
	while (n--) {
		long long t;
		scanf("%I64d", &t);
		printf("%I64d\n", get_next(t));
	}
}