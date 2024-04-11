# include <iostream>
# include <string>
using namespace std;
const int MN = 1e6 + 44;
string input[MN];
int jump[MN];
int n, r, c;
void add(int a1[], int a2[], int res[])
{
	for (int i = 0; i <= n; ++i)
		res[i] = a1[a2[i]];
}
int len[MN];
int jump1[MN];
int jumpacc[MN];
int main()
{
	cin >> n >> r >> c;
	for (int i = 0; i < n; ++i)
		cin >> input[i];
	for (int i = 0; i < n; ++i)
		len[i] = input[i].size();
	int head = 0, sumlen = 0;
	for (int i = 0; i < n; sumlen -= len[i] + 1, ++i)
	{
		while (head < n)
			if (sumlen + len[head] <= c)
			{
				sumlen += len[head] + 1;
				head ++;
			}
			else
				break;
		jump1[i] = head;
	}
	jump1[n] = n;
// 	for (int i = 0; i <= n; i++)
// 		cout << i << '.' << jump1[i] << '\n';
	for (int i = 0; i <= n; i++)
		jumpacc[i] = i;
	for (int bit = 1; bit <= r; bit <<= 1)
	{
		if (bit & r)
			add(jump1, jumpacc, jumpacc);
		add(jump1, jump1, jump1);
	}
// 	cout << "after jumps\n";
// 	for (int i = 0; i <= n; i++)
// 		cout << i << '.' << jumpacc[i] << '\n';
	int M = 0, wh = 0;
	for (int i = 0; i < n; ++i)
		if (jumpacc[i] - i > M)
		{
			M = jumpacc[i] - i;
			wh = i;
		}
	int rcou = 0, rlen = 0;
	for (int i = wh; i < n && rcou < r; ++i)
	{
		if (rlen + len[i] > c)
		{
			rlen = 0;
			rcou ++;
			cout << '\n';
			if (rcou >= r)
				return 0;
		}
		else if (i > wh)
			cout << ' ';
		if (len[i] > c)
			return 0;
		rlen += len[i] + 1;
		cout << input[i];
	}
}