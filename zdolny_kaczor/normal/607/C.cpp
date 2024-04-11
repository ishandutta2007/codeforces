# include <cstdio>
# include <cstdlib>
# include <set>
using namespace std;
const int MN = 1e6 + 44;
char a[MN], b[MN];
typedef pair <long long, int> hash_t;
const int B = 4267;
const int MOD = 1e9 + 33;
long long pow[MN];
hash_t empty = make_pair(0LL, 0);
hash_t lex(hash_t a, char b)
{
// 	printf("lex %c\n", b);
	return make_pair((a.first + b * pow[a.second]) % MOD, a.second + 1);
}
hash_t rex(hash_t a, char b)
{
// 	printf("rex %c\n", b);
	return make_pair((a.first * B + b) % MOD, a.second + 1);
}
void err()
{
	printf("NO\n");
	exit(0);
}
char opp[128];
int main()
{
	int n;
	scanf("%d%s%s", &n, a, b);
	n--;
	pow[0] = 1;
	for (int i = 1; i < n; ++i)
		pow[i] = pow[i - 1] * B % MOD;
	opp['N'] = 'S';
	opp['S'] = 'N';
	opp['E'] = 'W';
	opp['W'] = 'E';
	hash_t A = empty, B = empty;
	for (int i = n - 1; i >= 0; --i)
	{
		A = lex(A, a[i]);
		B = rex(B, opp[b[i]]);
		if (A == B)
			err();
	}
	printf("YES\n");
}