#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

ll p(int n, int x)
{
	ll prod = 1;
	int i = 0;
	while(i < x)
	{
		prod *= n - i;
		i++;
	}
	if(x == 0)
	{
		return 1;
	}
	return prod;
}

int main()
{
	string enter;
	char x; //stores string.at()
	cin >> enter; //ask for input
	int n = enter.length(); //length
	//cout << n;
	ll possible = 1; //final answer
	bool first = false; //determine whether have char at 1st char of string.
	vector <char> ch; //vector to store used chars
	int sum = 0; //no. of used chars
	int i; //for loop
	
	for(i = 0; i < n; i++)
	{
		x = enter.at(i); //ok till here
		if(!isalpha(x))
		{
			//cout << "Non-Alpha!" << endl;
			if(x == '?')
			{
				if(i == 0)
				{
					possible *= 9;
				}
				else
				{
					possible *= 10;
				}
			} //looks fine
		}
		else
		{
			if(i == 0)
			{
				first = true; //fine
			}
			if(ch.empty())
			{
				ch.push_back(x);
				sum++;
			}
			else
			{
				if(find(ch.begin(), ch.end(), x) == ch.end())
				{
					//cout << "Char " << sum + 1 << " found" << endl;
					ch.push_back(x);
					sum++; 
				}
			}
		}
	}
	
	if(!first)
	{
		possible *= p(10, sum);
	}
	else
	{
		possible = (possible * (p(10, sum)/10*9));
	}	
	cout << possible;
	return 0;
}