# include <cstdio>
# include <vector>
using namespace std;
vector <int> odd, even;

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; i += 2)
		odd.push_back(i);
	for (int i = 2; i < n; i += 2)
		even.push_back(i);
	for (int i = odd.size() - 1; i >= 0; --i)
		printf("%d ", n - odd[i]);
	for (int i = 0; i < odd.size(); ++i)
		printf("%d ", n - odd[i]);
	for (int i = even.size() - 1; i >= 0; --i)
		printf("%d ", n - even[i]);
	printf("%d ", n - 0);
	for (int i = 0; i < even.size(); ++i)
		printf("%d ", n - even[i]);
	printf("%d ", n - 0);
}