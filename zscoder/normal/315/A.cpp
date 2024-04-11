#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <map>
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
#include <cstddef>
#include <fstream>
#include <utility>
#include <ctime>
#include <cstdlib>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <bool> vb;

#define forloopp(i, a, b) \
for(int i = int(a); i <= int(b); i++)
#define forloopm(i, a, b) \
for(int i = int(a); i >= int(b); i--)
#define INF INT_MAX

//Tip for reading input : scanf("%s%d", &s, &d);
/*
class BigInt
{
private:
	unsigned short* number_;	//ptr to an array on the heap
	unsigned length_;			// size of array

	void checkformat( const BigInt& BI );				//placed in try block
	void err_handle(const unsigned short& err_id );		//placed in catch block

public:
	
	BigInt();
	BigInt( const BigInt& BI );
	BigInt( const int& n );
	BigInt( const long& n );
	BigInt( const long long& n );
	~BigInt();
	
	BigInt& operator = (const BigInt& BI);
	BigInt& operator = (const int& n);
	BigInt& operator = (const long& n);
	BigInt& operator = (const long long& n);
	// BigInt& operator + (const BigInt& BI); //To Do

	unsigned short* getnumaddress() const;		//for debuging
	ostream& tostream(ostream& os);				// ostream helper function

	unsigned length() const;					//return number of elements				
	unsigned short at( const unsigned& position ) const;	//element access at 'position'

};

ostream& operator << ( ostream& os, BigInt& BI );

BigInt::BigInt():
length_(0),
number_(NULL)
{
}

BigInt::BigInt(const BigInt& BI)
{
	length_ = BI.length();
	number_ = new unsigned short[ length_ ];
	*this = BI;

	try { checkformat(*this); }
	catch(unsigned short err) { err_handle(err); }
}

BigInt::BigInt(const int& n)
{
	long long ncpy = n;
	std::string num = std::to_string(ncpy);
	length_ = num.length();
	number_ = new unsigned short [length_];

	for(unsigned i=0; i<length_; i++) number_[i] = (num[i] - '0');

	try { checkformat(*this); }
	catch(unsigned short err) { err_handle(err); }
}

BigInt::BigInt(const long& n)
{
	long long ncpy = n;
	std::string num = std::to_string(ncpy);
	length_ = num.length();
	number_ = new unsigned short [length_];

	for(unsigned i=0; i<length_; i++) number_[i] = (num[i] - '0');

	try { checkformat(*this); }
	catch(unsigned short err) { err_handle(err); }
}

BigInt::BigInt(const long long& n)
{
	long long ncpy = n;
	std::string num = std::to_string(ncpy);
	length_ = num.length();
	number_ = new unsigned short [length_];

	for(unsigned i=0; i<length_; i++) number_[i] = (num[i] - '0');

	try { checkformat(*this); }
	catch(unsigned short err) { err_handle(err); }
}

BigInt::~BigInt()
{
	if( number_ ) delete [] number_;
}

//Exception Handling
void BigInt::checkformat( const BigInt& BI )
{
	for(unsigned i=0; i<length_; i++)
	{
		if( number_[i]<0 || number_[i]>9 ) throw unsigned short(1);
	}
}

void BigInt::err_handle( const unsigned short& err_id )
{
	switch( err_id )
	{
	case 1:
		std::cerr << "Improperly formatted data, error " << err_id << std::endl;
		break;
	default:
		break;
	}
}

//Operator Overloads

BigInt& BigInt::operator = ( const BigInt& BI )
{
	if( this!=&BI )
	{
		delete [] number_;
		length_ = BI.length();
		new unsigned short [length_];

		for(unsigned i=0; i<length_; i++) number_[i] = BI.at(i);
	}
	return *this;
}

BigInt& BigInt::operator = (const int& n)
{
	BigInt temp(n);
	*this = temp;
	return *this;
}

BigInt& BigInt::operator = (const long& n)
{
	BigInt temp(n);
	*this = temp;
	return *this;
}

BigInt& BigInt::operator = (const long long& n)
{
	BigInt temp(n);
	*this = temp;
	return *this;
}

ostream& BigInt::tostream(ostream& os)
{
	for( unsigned i=0; i<length_; i++) os << number_[i];
	return os;
}

ostream& operator << ( ostream& os, BigInt& BI)
{
	return BI.tostream(os);
}


//other member functions
unsigned BigInt::length() const
{
	return length_;
}

unsigned short BigInt::at( const unsigned& position) const
{
	return position>length_ ? NULL : number_[position];
}

unsigned short* BigInt::getnumaddress() const
{
	return number_;
}*/

//A
int main()
{
	//clock_t start = clock();
	//Program starts here.
	int n;
	cin >> n;
	int a[n], b[n];
	for(int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i];
	}
	int count = 0;
	bool done = false;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(i != j)
			{
				if(a[i] == b[j])
				{
					done = true;
					break;
				}
			}
		}
		if(!done)
		{
			count++;
		}
		done = false;
	}
	cout << count;
	//clock_t end = clock();
	//printf("Run Time : %.5f\n", ((double)(end - start))/CLOCKS_PER_SEC);
	return 0;
}

//B
/*
int main()
{
	//clock_t start = clock();
	//Program starts here.
	//clock_t end = clock();
	//printf("Run Time : %.5f\n", ((double)(end - start))/CLOCKS_PER_SEC);
	return 0;
}
*/

//C
/*
int main()
{
	//clock_t start = clock();
	//Program starts here.
	//clock_t end = clock();
	//printf("Run Time : %.5f\n", ((double)(end - start))/CLOCKS_PER_SEC);
	return 0;
}
*/

//D
/*
int main()
{
	//clock_t start = clock();
	//Program starts here.
	//clock_t end = clock();
	//printf("Run Time : %.5f\n", ((double)(end - start))/CLOCKS_PER_SEC);
	return 0;
}
*/

//E
/*
int main()
{
	//clock_t start = clock();
	//Program starts here.
	//clock_t end = clock();
	//printf("Run Time : %.5f\n", ((double)(end - start))/CLOCKS_PER_SEC);
	return 0;
}
*/