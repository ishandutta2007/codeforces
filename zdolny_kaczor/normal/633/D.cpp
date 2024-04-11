# include <cstdio>
# include <map>
# include <vector>
using namespace std;
const int MN = 1e3 + 4;
const int bound = 1e9 + 44;
map <int, int> amo;
int arr[MN];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", arr + i);
		amo[arr[i]] ++;
	}
	int res = amo[0];
	for (int i = 0; i < n; ++i)
		for (int k = 0; k < n; ++k)
			if (i - k)
			{
				long long a = arr[i], b = arr[k];
				if (a == 0 && b == 0)
					continue;
				vector <long long> seq;
				while (a < bound && a > -bound)
				{
					seq.push_back(a);
					long long c = a + b;
					a = b;
					b = c;
				}
				int len = 0;
				bool in = true;
				for (int x:seq)
				{
					if (amo[x])
					{
						len++;
						amo[x]--;
					}
					else
						break;
				}
				for (int i = 0; i < len; ++i)
					amo[seq[i]]++;
				if (len > res)
					res = len;
			}
	printf("%d\n", res);
}