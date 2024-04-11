#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long double ld;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

int fact[8];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, m;
	cin >> n >> m;
	int p1 = 0; int p2 = 0;
	ll cnt1 = 1; ll cnt2 = 1;
	while(cnt1 <= n - 1)
	{
		cnt1 *= 7;
		p1++;
	}
	while(cnt2 <= m - 1)
	{
		cnt2 *= 7;
		p2++;
	}
	if(n == 1) p1 = 1;
	if(m == 1) p2 = 1;
	ll cnt = 0;
	//cout << p1 << ' ' << p2 << '\n';
	/*
	for(int i = 0; i < (1<<7); i++)
	{
		for(int j = 0; j < (1<<7); j++)
		{
			for(int k = 0; k < (1<<7); k++)
			{
				if(((j&i) == j) && ((k&i) == k) && ((j&k) == 0) && __builtin_popcount(j) == p1 && __builtin_popcount(k) == p2)
				{
					ll c1, c2;
					c1 = 0; c2 = 0;
					for(int l = 0; l < 7; l++)
					{
						if(j&(1<<l)) c1 += (1<<l);
					}
					for(int l = 0; l < 7; l++)
					{
						if(k&(1<<l)) c2 += (1<<l);
					}
					if(c1 < n && c2 < m) 
					{
						cout << c1 << ' ' << c2 << '\n';
						cnt++;
					}
				}
			}
		}
	}
	*/
	fact[0] =1;
	for(int i = 1; i <= 7; i++)
	{
		fact[i] = i*fact[i-1];
	}
	for(int i = 0; i < (1<<7); i++)
	{
		if(__builtin_popcount(i) == p1)
		{
			for(int j = 0; j < (1<<7); j++)
			{
				if(__builtin_popcount(j) == p2)
				{
					if((j&i) == 0)
					{
						vi x;
						vi y;
						for(int a = 0; a < 7; a++)
						{
							if((i&(1<<a))) x.pb(a);
						}
						for(int b = 0; b < 7; b++)
						{
							if((j&(1<<b))) y.pb(b);
						}
						ll cnt1 = 0; ll cnt2 = 0;
						for(int a = 0; a < fact[p1]; a++)
						{
							ll tmp = 0; ll tmp2 = 1;
							for(int l = 0; l < p1; l++)
							{
								tmp += (tmp2*x[l]);
								tmp2 *= 7;
							}
							if(tmp < n) cnt1++;
							if(a < fact[p1] - 1) next_permutation(x.begin(), x.end());
						}
						for(int b = 0; b < fact[p2]; b++)
						{
							ll tmp = 0; ll tmp2 = 1;
							for(int l = 0; l < p2; l++)
							{
								tmp += (tmp2*y[l]);
								tmp2 *= 7;
							}
							if(tmp < m) cnt2++;
							if(b < fact[p2] - 1) next_permutation(y.begin(), y.end());
						}
						cnt += (cnt1*cnt2);
					}
				}
			}
		}
	}
	cout << cnt;
	return 0;
}