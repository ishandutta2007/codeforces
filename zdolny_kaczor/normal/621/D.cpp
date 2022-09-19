# include <iostream>
# include <cstdio>
# include <cmath>
using namespace std;
long double in[3];
char sym[] = "xyz";
char res[166];
struct loglog
{
	bool sign;
	long double val;
	void make(long double x, long double y, long double z, bool type)
	{
		sign = (x > 1);
		if (type)
			val = log (abs(log (x))) + log(y) + log (z);
		else
			val = log (abs(log (x))) + log(y) * z;
	}
};
bool operator > (loglog a, loglog b)
{
	if (a.sign != b.sign)
		return a.sign > b.sign;
	else if (a.sign)
		return a.val > b.val;
	else
		return a.val < b.val;
}
bool first;
loglog maxi;
void with(int i, int j, int k)
{
	loglog a;
	a.make(in[i], in[j], in[k], true);
	if (a > maxi)
	{
		maxi = a;
		sprintf(res, "(%c^%c)^%c", sym[i], sym[j], sym[k]);
	}
}
void without(int i, int j, int k)
{
	
	loglog b;
	b.make(in[i], in[j], in[k], false);
	
	if (b > maxi)
	{
		maxi = b;
		sprintf(res, "%c^%c^%c", sym[i], sym[j], sym[k]);
	}
}
int main()
{
	for (int i = 0; i < 3; ++i)
		std::cin >> in[i];
	without(0, 1, 2);
	without(0, 2, 1);
	with(0, 1, 2);
	without(1, 0, 2);
	without(1, 2, 0);
	with(1, 0, 2);
	without(2, 0, 1);
	without(2, 1, 0);
	with(2, 0, 1);
	printf("%s\n", res);
}