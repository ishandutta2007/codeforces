/*
Konrad Paluszek
data 26.10.16
rozwizuje ukad kongruencji
x === a (mod b)
x === c (mod d)

Dziaa te dla b, d nie wzgldnie pierwszych

Rwnanie x === a (mod b) trzyma jako par longlongw (a, b).
Jeli rwnanie nie ma rozwiza, to zwraca (0LL, 0LL)
Jeli dostanie jako parametr rwnanie sprzeczne (t.j. (0LL, 0LL)) to rwnie takie zwrci

*/

#include<bits/stdc++.h>

using namespace std;
#define LL long long
#define LD long double
#define f first
#define s second
#define eq pair <LL, LL>


LL mul(LL a,LL b, LL m)
	 {
	 LL q=(LL)((LD)a*(LD)b/(LD)m);
	 LL r=a*b-q*m; // ma si przekrca
	 return (r%m+m)%m;
	 }



const long double LIMIT = 1e12 + 44;

LL nwdr(LL a, LL b, LL &x, LL &y) {
	if (b == 0) {
		x = y = 1;
		return a;
	}
	LL xx, yy;
	LL ret = nwdr(b, a % b, xx, yy);
	x = yy;
	y = xx- yy * (a / b);
	return ret;
}
void err()
{
	printf("NO\n");
	exit(0);
}

#define NONE make_pair(0LL, 0LL)

//para (a, b) reprezentuje rwnanie x === a (mod b)
//para (0, 0) reprezentuje rwnanie sprzeczne
eq add(eq p, eq q) {
	if (p == NONE || q == NONE)
		return NONE;
	LL k, l;
	fprintf(stderr, "join x === %lld (%lld) with x === %lld (%lld)\n", p.f, p.s, q.f, q.s);
	LL g = nwdr(p.s, q.s, k, l);
	if (p.s / g * q.s > LIMIT) {
		err();
	}
	if ((p.f - q.f) % g)
		return NONE;
	LL mod = p.s / g * q.s;
	LL ans = p.f + mul(mul(p.s, ((q.f - p.f) / g), mod),  k, mod); //jakby by overflow, to zastpi przez mnoenie
	if (ans < 0)
		ans += mod;
	fprintf(stderr, "return x === %lld (%lld) \n", ans, mod);
	return make_pair(ans, mod);
}

const int MN = 1e4 + 44;
long long arr[MN];
int main()
{
// 	while (false)
// 	{
// 		long long a, b;
// 		scanf("%lld%lld", &a, &b);
// 		long long x, y;
// 		long long r = euc(a, b, x, y);
// 		printf("%lld * %lld + %lld * %lld = %lld\n", a, x, b, y, r);
// 	}
	long long n, m;
	int k;
	scanf("%lld%lld%d", &n, &m, &k);
	for (int i = 1; i <= k; ++i)
		scanf("%lld", arr + i);
// 	for (int i = 1; i < 1000000; ++i)
// 	{
// 		long long p = 1e9 + 9;
// 		if ((i * inv(i, p)) % p != 1)
// 			printf("error\n");
// 	}
	eq equ = make_pair(0ll, 1ll);
	for (int i = 1; i <= k; ++i)
	{
		equ = add(equ, make_pair(-i, arr[i]));
		fprintf(stderr, "accumulate x === %lld (mod %lld) reaching x === %lld (mod %lld)\n", (LL)-i, arr[i], equ.first, equ.second);
	}
	if (equ.second > n || equ.first > m - k) {
		fprintf(stderr, "error1\n");
		err();
	}
	fprintf(stderr, "we're still alive with x == %lld (%lld)\n", equ.first, equ.second);
	if (equ == NONE) {
		err();
	}
	for (int i = 1; i <= k; ++i)
		if (__gcd(equ.first + i, equ.second) != arr[i])
		{
			fprintf(stderr, "err in %d\n", i);
			err();
		}
	printf("YES\n");
}