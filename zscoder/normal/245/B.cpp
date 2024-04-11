#include <cstdio>
#include <stack>
#include <complex>
#include <climits>
#include <bitset>
#include <deque>
#include <set>
#include <list>
#include <valarray>
#include <functional>
#include <new>
#include <iterator>
#include <stdexcept>
#include <iostream>
#include <string>

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

using namespace std;

int main()
{
	string address;
	getline(cin, address);
	int len = address.length();
	
	int counter = 0;
	
	bool protocol = true;
	
	if(address.at(0) == 'h')
	{
		counter = 4;
	}
	else
	{
		protocol = false;
		counter = 3;
	}
	
	int final_counter;
	final_counter = address.find("ru");
	
	//cout << final_counter << endl;
	
	if(protocol)
	{
		cout << "http://";
	}
	else
	{
		cout << "ftp://";
	}
	
	if(counter == final_counter)
	{
		cout << "ru";
		counter++;
		counter++;
		final_counter = address.find("ru", counter);
	}
	
	for(int i = counter; i < final_counter; i++)
	{
	//cout << i << endl;
		cout << address.at(i);
	}
	
	cout << ".ru";
	
	if(final_counter + 1 < len - 1)
	{
		cout << "/";
		for(int i = final_counter + 2; i < len; i++)
		{
			cout << address.at(i);
		}
	}
	
	return 0;
}