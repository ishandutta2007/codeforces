#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <utility>
#include <vector>
#include <cstdlib>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
/*A
int main()
{
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	int diff_a, diff_b, diff_c;
	int positive = 0; 
	int negative = 0;
	diff_a = a-d;
	diff_b = b-e;
	diff_c = c-f;
	if(diff_a > 0)
	{
		positive += diff_a/2;
	}
	else
	{
		negative -= diff_a;
	}
	if(diff_b > 0)
	{
		positive += diff_b/2;
	}
	else
	{
		negative -= diff_b;
	}
	if(diff_c > 0)
	{
		positive += diff_c/2;
	}
	else
	{
		negative -= diff_c;
	}
	if(positive >= negative)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}*/
int board[510][510];
int main()
{
	ios_base::sync_with_stdio(false);
	for(int i = 0; i < 510; i++)
	{
		for(int j = 0; j < 510; j++)
		{
			board[i][j] = -1;
		}
	}
	int x, y, start, end;
	cin >> x >> y >> start >> end;
	string s;
	cin >> s;
	int total = x*y;
	int curr_x = start, curr_y = end;
	cout << 1 << " ";
	total--;
	board[curr_x][curr_y] = 0;
	for(int i = 0; i < s.length() - 1; i++)
	{
		if(s.at(i) == 'L')
		{
			if(curr_y > 1)
			{
				curr_y--;
			}
		}
		else if(s.at(i) == 'R')
		{
			if(curr_y < y)
			{
				curr_y++;
			}
		}
		else if(s.at(i) == 'U')
		{
			if(curr_x > 1)
			{
				curr_x--;
			}
		}
		else
		{
			if(curr_x < x)
			{
				curr_x++;
			}
		}
		if(board[curr_x][curr_y] == -1)
		{
			board[curr_x][curr_y] = i;
			cout << 1 << " ";
			total--;
		}
		else
		{
			cout << 0 << " ";
		}
	}
	cout << total;
	return 0;
}