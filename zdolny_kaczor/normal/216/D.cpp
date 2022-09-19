# include <cstdio>
# include <algorithm>
# include <vector>
using namespace std;
const int MN = 1e3 + 44;
void read(vector <int> & a)
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int x;
		scanf("%d", &x);
		a.push_back(x);
	}
	sort(a.begin(), a.end());
}
void write(vector <int> & a)
{
	printf("{");
	for (auto x : a)
		printf("%d ", x);
	printf("}\n");
}
void count(vector <int> &data1, vector <int> &data2, vector <int> &ans1, vector <int> &ans2)
{
// 	printf("count:\n");
// 	write(data1);
// 	write(data2);
	int isteps = 0, ksteps = 0;
	for (int i = 0, k = 0; i < data1.size() || k < data2.size(); )
	{
// 		printf("%d %d\n", i, k);
		if (i == data1.size() || (k != data2.size() && data1[i] > data2[k]))
		{
			if (k)
				ans2.push_back(isteps);
			ksteps++;
			isteps = 0;
			k++;
		}
		else
		{
			if (i)
				ans1.push_back(ksteps);
			isteps++;
			ksteps = 0;
			i++;
		}
	}
// 	printf("returns : \n");
// 	write(ans1);
// 	write(ans2);
}
int res = 0;
void include(vector <int> & a, vector <int> & b)
{
	for (int i = 0; i < a.size(); ++i)
		if (a[i] != b[i])
			res++;
}
vector <int> segments[MN];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		read(segments[i]);
	vector <int> last, first;
	count(segments[0], segments[n - 1], first, last);
	for (int i = 0; i < n - 1; ++i)
	{
		vector <int> currl, currr;
		count(segments[i], segments[i + 1], currl, currr);
		include (currl, first);
		first = currr;
	}
	include (first, last);
	printf("%d\n", res);
}