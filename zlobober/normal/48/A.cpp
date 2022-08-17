#include <iostream>
using namespace std;

char beats[256][256];

int main()
{
	char buf[10][10];
	for (int i = 0; i < 3; i++)
		cin >> buf[i];
	beats['s']['p'] = beats['p']['r'] = beats['r']['s'] = 1;
	char player[] = {'F', 'M', 'S'};
	for (int i = 0; i < 3; i++)
	{
		if (beats[buf[i][0]][buf[(i + 1) % 3][0]] && beats[buf[i][0]][buf[(i + 2) % 3][0]])
		{
			cout << player[i];
			return 0;
		}
	}
	cout << '?';
	return 0;
}