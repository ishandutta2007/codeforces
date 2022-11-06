#include <bits/stdc++.h>

using namespace std;

const int maxn = 100005;

typedef long long ll;

int a[maxn],m,n;

int pow(int a,int b)
{
	int tmp = 1;
	for(;b;b >>= 1,a = a * 1ll * a % m)
		if (b & 1) tmp = tmp * 1ll * a % m;
	return tmp;
}

int main()
{
	scanf("%d%d", &m, &n);
	ll s = 0,s1 = 0,qs = 0;
	
	for(int i = 0;i < n;i ++)
	{ 
		scanf("%d", &a[i]);
		s += a[i],s1 = (s1 + a[i] * 1ll * a[i]) % m;
		qs += i * 1ll * i;
	}
	s %= m,s1 %= m,qs %= m;
	sort(a,a + n);
	
	for(int i = 0;i < n;i ++)
	{
		int d = a[i] - a[0];
		int x = ((s - n * (n - 1ll) / 2 % m * d % m) % m * pow(n,m - 2) % m + m) % m;
		if ((((x * 1ll * x) % m * n % m + n * (n - 1ll) % m * d % m * x % m + d * 1ll * d % m * qs % m) % m + m) % m == s1)
		{	
			static int b[maxn];
			for(int j = 0;j < n;j ++) b[j] = (x + d * 1ll * j) % m;
			sort(b,b + n);
			bool ok = 1;
			for(int j = 0;j < n;j ++)
				if (b[j] != a[j]) {ok = 0;break;}
			if (ok) 
			{
				printf("%d %d\n", x,  d);
				return 0;
			}
		}
	}
	
	printf("-1\n");
	return 0;
}