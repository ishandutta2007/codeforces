#include <bits/stdc++.h>
using std::cin;
using std::cout;

char s[54];

int main() {
	std::ios::sync_with_stdio(false);
	do cout << "next 0 1\nnext 1" << std::endl, cin.getline(s, sizeof s), cin.getline(s, sizeof s); while (*s != 50);
	do cout << "next 0 1 2 3 4 5 6 7 8 9" << std::endl, cin.getline(s, sizeof s); while (*s != 49);
	cout << "done" << std::endl;
	return 0;
}