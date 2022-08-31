#include <bits/stdc++.h>

typedef long long ll;
const int N = 100054;

struct vec3 {
	ll x, y, z;
	vec3 (ll x0 = 0, ll y0 = 0, ll z0 = 0) : x(x0), y(y0), z(z0) {}
	vec3 * read() {return scanf("%lld%lld%lld", &x, &y, &z), this;}
	inline ll man() const {return llabs(x) + llabs(y) + llabs(z);}
} p[N];

int n;
vec3 cur;

inline void up(ll &x, const ll y) {x < y ? x = y : 0;}
inline void down(ll &x, const ll y) {x > y ? x = y : 0;}
inline ll min(const ll x, const ll y) {return x < y ? x : y;}

inline bool check(ll r) {
	ll _XYZ, _XYz, _XyZ, _Xyz, _xYZ, _xYz, _xyZ, _xyz;
	ll XYZ, XYz, XyZ, Xyz, xYZ, xYz, xyZ, xyz, c0;
	_XYZ = _XYz = _XyZ = _Xyz = _xYZ = _xYz = _xyZ = _xyz = LLONG_MAX;
	for (int i = 0; i < n; ++i)
		down(_XYZ, + p[i].x + p[i].y + p[i].z + r),
		down(_XYz, + p[i].x + p[i].y - p[i].z + r),
		down(_XyZ, + p[i].x - p[i].y + p[i].z + r),
		down(_Xyz, + p[i].x - p[i].y - p[i].z + r),
		down(_xYZ, - p[i].x + p[i].y + p[i].z + r),
		down(_xYz, - p[i].x + p[i].y - p[i].z + r),
		down(_xyZ, - p[i].x - p[i].y + p[i].z + r),
		down(_xyz, - p[i].x - p[i].y - p[i].z + r);
	XYZ = _XYZ >> 1, XYz = _XYz >> 1, XyZ = _XyZ >> 1, Xyz = _Xyz >> 1,
	xYZ = _xYZ >> 1, xYz = _xYz >> 1, xyZ = _xyZ >> 1, xyz = _xyz >> 1;
	if (XYZ + xyz >= 0 && XYz + xyZ >= 0 && XyZ + xYz >= 0 && Xyz + xYZ >= 0 && XYZ + Xyz + xYz + xyZ >= 0 && XYz + XyZ + xYZ + xyz >= 0) {
		c0 = (min(XYZ, xYZ + XyZ + XYz) - min(xyz, Xyz + xYz + xyZ)) >> 1;
		if (c0 >= xYZ + XyZ - xyZ) cur = vec3(c0 - xYZ, c0 - XyZ, xYZ + XyZ);
		else if (c0 >= xYZ - xYz - xyZ) cur = vec3(c0 - xYZ, xYZ - xyZ, c0 + xyZ);
		else cur = vec3(-xYz - xyZ, c0 + xYz, c0 + xyZ);
		return true;
	}
	XYZ = (_XYZ - 1) >> 1, XYz = (_XYz - 1) >> 1, XyZ = (_XyZ - 1) >> 1, Xyz = (_Xyz - 1) >> 1,
	xYZ = (_xYZ - 1) >> 1, xYz = (_xYz - 1) >> 1, xyZ = (_xyZ - 1) >> 1, xyz = (_xyz - 1) >> 1;
	if (XYZ + xyz + 1 >= 0 && XYz + xyZ + 1 >= 0 && XyZ + xYz + 1 >= 0 && Xyz + xYZ + 1 >= 0 && XYZ + Xyz + xYz + xyZ + 2 >= 0 && XYz + XyZ + xYZ + xyz + 2 >= 0) {
		c0 = (min(XYZ, xYZ + XyZ + XYz + 1) - min(xyz + 1, Xyz + xYz + xyZ + 2)) >> 1;
		if (c0 >= xYZ + XyZ - xyZ) cur = vec3(c0 - xYZ, c0 - XyZ, xYZ + XyZ + 1);
		else if (c0 >= xYZ - xYz - xyZ - 1) cur = vec3(c0 - xYZ, xYZ - xyZ, c0 + xyZ + 1);
		else cur = vec3(-xYz - xyZ - 1, c0 + xYz + 1, c0 + xyZ + 1);
		return true;
	}
	return false;
}

void work() {
	ll L = 0, R = 0, c0; vec3 ans(0, 0, 0);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) up(R, p[i].read()->man());
	for (; L < R; check(c0 = (L + R) / 2) ? ans = cur, R = c0 : L = c0 + 1);
	printf("%lld %lld %lld\n", ans.x, ans.y, ans.z);
}

int main() {
	int T;
	for (scanf("%d", &T); T; --T) work();
	return 0;
}