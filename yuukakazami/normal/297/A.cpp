#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

int calc(string a) {
	return count(a.begin(), a.end(), '1');
}

int main() {
	string a, b;
	cin >> a >> b;
	int A = calc(a), B = calc(b);
	if (A % 2 == 1)
		++A;
	if (A >= B)
		puts("YES");
	else
		puts("NO");
}