#include <bits/stdc++.h>
using namespace std;

const int p = 1e9 + 7, p1 = 998244353, p2 = 1004535809, Maxn = 1000005;
int n, q;
long long P[Maxn], inv_P[Maxn], P1[Maxn], P2[Maxn], suf[Maxn], cnt[100005][27];
pair <long long, long long> Hash_w[Maxn], Hash_s[Maxn], Hash_t[Maxn], Hash_tmp[Maxn];
string s0, t, w, tmp;
void init(string &s, pair <long long, long long> Hash[])
{
	Hash[0] = make_pair(s[0] - 'a' + 1, s[0] - 'a' + 1);
	for (int i = 1; i < (int) s.size(); i++)
	{
		Hash[i].first = (Hash[i - 1].first * 29 + s[i] - 'a' + 1) % p1;
		Hash[i].second = (Hash[i - 1].second * 31 + s[i] - 'a' + 1) % p2;
	}
}
pair <long long, long long> get_hash(int lt, int rt, pair <long long, long long> Hash[])
{
	if (lt > rt) return make_pair(0, 0);
	if (!lt) return Hash[rt];
	return make_pair((Hash[rt].first - Hash[lt - 1].first * P1[rt - lt + 1] % p1 + p1) % p1, (Hash[rt].second - Hash[lt - 1].second * P2[rt - lt + 1] % p2 + p2) % p2);
}
bool Path(int lt1, int rt1, pair <long long, long long> Hash1[], int lt2, int rt2, pair <long long, long long> Hash2[])
{
	return get_hash(lt1, rt1, Hash1) == get_hash(lt2, rt2, Hash2);
}
string tt;
long long work(string &s, int k)
{
	init(s, Hash_tmp);
	tt = "";
	long long result = 0;
	int i, c = 0;
	for (i = 0; i < k && tt.size() <= 4 * s.size(); i++)
	{
		init(tt, Hash_t);
		c = 0;
		for (int j = 0; j < (int) s.size(); j++)
			if (tt.size() - j >= 0 && (int) s.size() - j - 2 < (int) tt.size())
				c += (Path(0, j - 1, Hash_tmp, tt.size() - j, tt.size() - 1, Hash_t) && s[j] == t[i] && Path(j + 1, s.size() - 1, Hash_tmp, 0, (int) s.size() - j - 2, Hash_t));
		(result += c * inv_P[i + 1]) %= p;
		tt = tt + t[i] + tt;
	}
	init(tt, Hash_t);
	for (int h = 0; h < 26; h++)
	{
		c = 0;
		for (int j = 0; j < (int) s.size(); j++)
			if (tt.size() - j >= 0 && (int) s.size() - j - 2 < (int) tt.size())
				c += (Path(0, j - 1, Hash_tmp, tt.size() - j, tt.size() - 1, Hash_t) && s[j] - 'a' == h && Path(j + 1, s.size() - 1, Hash_tmp, 0, (int) s.size() - j - 2, Hash_t));
		(result += (p + cnt[i][h] - cnt[k][h]) * c) %= p;
	}
	return result * P[k] % p;
}
int main()
{
	inv_P[0] = 1, inv_P[1] = (p + 1) / 2;
	P[0] = 1;
	for (int i = 1; i <= 1000000; i++) P[i] = P[i - 1] * 2 % p;
	for (int i = 2; i <= 1000000; i++)
		inv_P[i] = inv_P[i - 1] * (p + 1) / 2 % p;
	P1[0] = P2[0] = 1;
	for (int i = 1; i <= 1000000; i++)
		P1[i] = (P1[i - 1] * 29) % p1, P2[i] = (P2[i - 1] * 31) % p2;
	scanf("%d%d", &n, &q);
	cin >> s0 >> t;
	for (int i = t.size() - 1; i >= 0; i--)
	{
		memcpy(cnt[i], cnt[i + 1], sizeof(long long[26]));
		(cnt[i][t[i] - 'a'] += inv_P[i + 1]) %= p;
	}
	init(s0, Hash_s);
	for (int i = 1; i <= q; i++)
	{
		int k;
		long long ans = 0;
		scanf("%d", &k);
		cin >> w;
		init(w, Hash_w);
		for (int j = 0; j <= (int) s0.size(); j++)
		{
			if (j >= (int) w.size()) break;
			tmp = "";
			if (!Path(0, j - 1, Hash_w, s0.size() - j, s0.size() - 1, Hash_s)) goto END;
			for (int k = j; k < (int) w.size(); k += s0.size() + 1)
			{
				if (!Path(k + 1, min(w.size() - 1, k + s0.size()), Hash_w, 0, min(w.size() - 1, k + s0.size()) - (k + 1), Hash_s)) goto END;
				tmp += w[k];
			}
			(ans += work(tmp, k)) %= p;
			END:;
		}
		for (int i = 0; i <= (int) (s0.size() - w.size()); i++)
			if (Path(0, w.size() - 1, Hash_w, i, i + w.size() - 1, Hash_s)) (ans += P[k]) %= p;
		printf("%lld\n", ans);
	}
	return 0;
}