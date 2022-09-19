# include <cstdio>
# include <cassert>
# include <vector>
# include <algorithm>
# include <cstring>
using namespace std;
const int MOD = 1e9+7;
const long long BASE = 9767;
const int MN = 5014;
int n;
char text [MN];
long long prehash[MN];//[k] = sum [i = 0] to [k-1] text[k]*base^k
# define pow pows
long long pow[MN];
bool equal(int i, int k, int len)
{
	return ((prehash[i+len]-prehash[i]) * pow[k] - (prehash[k+len]-prehash[k]) * pow[i])%MOD == 0;
}
void show(pair <int, int> a)
{
	for (int i = a.first; i < a.first + a.second; ++i)
		putchar(text[i]);
	printf("\n");
}
bool cmp(pair <int, int> a, pair <int, int> b) //pierwszy index, dugo
{
	int p1 = a.first, p2 = b.first;
	int l1 = a.second, l2 = b.second;
	int low = 0, hig = min (l1, l2);
	while (low < hig)
	{
		int med = (low + hig + 1) / 2;
		if (equal(p1, p2, med))
			low = med;
		else
			hig = med - 1;
	}
	if (low == l2)
		return false;
	else if (low == l1)
		return true;
	else
		return text[p1 + low] < text[p2 + low];
}
vector <pair <int, int> > elements;
void ins(int i1, int i2)
{
	for (;i1 >= 0 && i2 < n && text[i1] == text[i2]; i1 -= 2, i2 += 2)
		elements.push_back(make_pair(i1, i2 - i1 + 1));
}
pair <int, int> suf[MN];
int Rank[MN];
bool cmp2(pair <int, int> a, pair <int, int> b)
{
	int p1 = a.first, p2 = b.first;
	int l1 = a.second, l2 = b.second;
	if (equal(p1, p2, min(l1, l2)))
		return l1 < l2;
	else
		return Rank[p1] < Rank[p2];
}
int main()
{
	int k;
	scanf("%s%d", text, &k);
	n = strlen(text);
	pow[0] = 1;
	for (int i=1; i<MN; ++i)
		pow[i] = BASE * pow[i-1] % MOD;
	for (int i = 0; i < n; ++i)
		prehash[i+1] = (prehash[i] + pow[i] * text[i]) % MOD;
	for (int cen = 0; cen < n; ++cen)
		for (int l = 0; l < 4; ++l)
			ins(cen, cen + l);
	for (int i = 0; i < n; ++i)
		suf[i] = make_pair(i, n - i);
	sort(suf, suf + n, cmp);
	for (int i = 0; i < n; ++i)
		Rank[suf[i].first] = i;
	nth_element(elements.begin(), elements.begin() + k - 1, elements.end(), cmp2);
	show(elements[k - 1]);
}