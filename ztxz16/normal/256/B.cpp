#include <stdio.h>
#include <stdlib.h>
#define ll long long

ll n, x, y, c, l, r, mid;
ll full, st, en;

ll check(ll time);

int main()
{
	scanf("%I64d %I64d %I64d %I64d", &n, &x, &y, &c);
	l = 0;
	r = (n << 1);
	while (l < r)
	{
		mid = ((l + r) >> 1);
		if (check(mid) == 1)
			r = mid;
		else
			l = mid + 1;
	}
	
	printf("%I64d\n", l);
	return 0;
}

ll check(ll time)
{
	ll s = 1;
	if (x + time > n)
		s += (n - x);
	else
		s += time;
	if (x - time < 1)
		s += (x - 1);
	else
		s += time;
	if (y + time > n)
		s += (n - y);
	else
		s += time;
	if (y - time < 1)
		s += (y - 1);
	else
		s += time;
		
	if (x - time < 1)
	{
		full = time - x + 1;
		if (y + full <= n)
			s += (full * (x - 1));
		else
			s += ((n - y) * (x - 1));
		if (y - full >= 1)
			s += (full * (x - 1));
		else
			s += ((y - 1) * (x - 1));
		st = x - 2;
	}
	
	else
		st = time - 1;
	if (y + time <= n)
		en = 1;
	else
		en = time - (n - y);
	if (en < x - 1 && y < n)
		s += ((st + en) * (st - en + 1) / 2);
	
	if (y - time >= 1)
		en = 1;
	else
		en = time - (y - 1);
	if (en < x - 1 && y > 1)
		s += ((st + en) * (st - en + 1) / 2);
		
	if (x + time > n)
	{
		full = time - (n - x);
		if (y + full <= n)
			s += (full * (n - x));
		else
			s += ((n - y) * (n - x));
		if (y - full >= 1)
			s += (full * (n - x));
		else
			s += ((y - 1) * (n - x));
		st = (n - x - 1);
	}
	
	else
		st = time - 1;
	if (y + time <= n)
		en = 1;
	else
		en = time - (n - y);
	if (en < n - x && y < n)
		s += ((st + en) * (st - en + 1) / 2);
	
	if (y - time >= 1)
		en = 1;
	else
		en = time - (y - 1);
	if (en < n - x && y > 1)
		s += ((st + en) * (st - en + 1) / 2);
	
	if (s >= c)
		return 1;
	else
		return 0;
}