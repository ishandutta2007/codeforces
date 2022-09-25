#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <algorithm>

#define INF (1000000000)
#define li long long

using namespace std;

li p[100001];

struct pt {
	li x, y, id;
};

inline bool cmp_x (const pt & a, const pt & b) {
	return a.x < b.x || a.x == b.x && a.y < b.y;
}

inline bool cmp_y (const pt & a, const pt & b) {
	return a.y < b.y;
}

pt a[100100];

li mindist = 100000000000000000LL;
li ansa, ansb;

inline void upd_ans (const pt & a, const pt & b) {
	double dist = ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
	if (dist < mindist)
		mindist = dist,  ansa = a.id,  ansb = b.id;
}

void rec (li l, li r) {
	if (r - l <= 3) {
		for (li i=l; i<=r; ++i)
			for (li j=i+1; j<=r; ++j)
				upd_ans (a[i], a[j]);
		sort (a+l, a+r+1, &cmp_y);
		return;
	}

	li m = (l + r) >> 1;
	li midx = a[m].x;
	rec (l, m),  rec (m+1, r);
	inplace_merge (a+l, a+m+1, a+r+1, &cmp_y);

	static pt t[100100];
	li tsz = 0;
	for (li i=l; i<=r; ++i)
		if (abs (a[i].x - midx) < mindist) {
			for (li j=tsz-1; j>=0 && a[i].y - t[j].y < mindist; --j)
				upd_ans (a[i], t[j]);
			t[tsz++] = a[i];
		}
}

int main(){
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	li n;
	cin >> n;
	li i, ii, g, h, xx, yy, x1, x2, y1, y2, q, w, tq, tw;
	li res = INF, k;

	for (i=0; i<n; i++){
	    cin >> a[i].x >> a[i].y;
	    if (a[i].x < 0 && a[i].y < 0){
	        p[i] = 4;
	        a[i].x = - a[i].x;
	        a[i].y = - a[i].y;
	    } else
	    if (a[i].x >= 0 && a[i].y < 0){
	        p[i] = 3;
	        a[i].y = - a[i].y;
	    } else
	    if (a[i].x < 0 && a[i].y >= 0){
	        p[i] = 2;
	        a[i].x = - a[i].x;
	    } else p[i] = 1;
	    a[i].id = i;
	    //cerr << x[i] << ' ' << y[i] << endl;
	}

    sort (a, a+n, &cmp_x);

    rec (0, n-1);

    cout << ansa + 1 << ' ' << p[ansa] << ' ' << ansb + 1 << ' ' << 5 - p[ansb] << endl;

}