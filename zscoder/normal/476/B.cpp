#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;
/*A
int main()
{
int n, m;
cin >> n >> m;
int i = 0;
int max = -1;
while(2*i <= n)
{
if((n - i) % m == 0)
{
max = n - i;
}
i++;
}
cout << max << endl;
return 0;
}*/
int n_choose_r(int n, int r)
{
	if(r == 0)
	{
		return 1;
	}
	if(r == 1)
	{
		return n;
	}
	if(n == r)
	{
		return 1;
	}
	if(n == 1)
	{
		return 1;
	}
	else
	{
		return (n_choose_r(n - 1, r - 1) + n_choose_r(n - 1, r));
	}
}

int main()
{
	string a, b;
	cin >> a >> b;
	int position = 0;
	int real_position = 0;
	int question = 0;
	double prob = 1;
	
	for(int i = 0; i < a.length(); i++)
	{
		if(a.at(i) == '+')
		{
			position++;
		}
		else
		{
			position--;
		}
	}
	
	for(int i = 0; i < b.length(); i++)
	{
		if(b.at(i) == '+')
		{
			real_position++;
		}
		else if(b.at(i) == '-')
		{
			real_position--;
		}
		else
		{
			question++;
		}
	}
	
	int difference = real_position - position;
	if(question == 0)
	{
		if(difference == 0)
		{
			prob = 1;
		}
		else
		{
			prob = 0;
		}
		cout << prob << endl;
		return 0;
	}
	int remainder = abs(difference);
	if(question % 2 != remainder % 2)
	{
		prob = 0;
	}
	else if(remainder > question)
	{
		prob = 0;
	}
	else
	{
		int x = (question + difference)/2;
		//int y = (question - difference)/2;
		prob = ((double)(n_choose_r(question, x))/(double)(pow(2, (double)question)));
	}
	cout << setprecision(11) << prob << endl;
	return 0;
}