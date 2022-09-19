# include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	printf("%d\n", max(max(0, c - b - a + 1), max(b - a - c + 1, a - b - c + 1)));
}