#include <iostream>
using namespace std;


int main()
{
	int a, a2, b, b2;
	cin >> a >> a2 >> b >> b2;
	swap(b, b2);
	bool f = (a <= b + 1) && (2 * a >= b - 2);
	swap(a, a2);
	swap(b, b2);
    f = f | ((a <= b + 1) && (2 * a >= b - 2));
	if (f)
		cout << "YES";
	else
		cout << "NO";
	
	return 0;
}