#include<bits/stdc++.h>
#define For(i, j, k) for(int i = (j); i <= (k); i++)

using namespace std;
inline int getsum(int x) {
	if(x & 1) {
		return  - (x / 2 + 1);
	} else {
		return x / 2;
	}
}
int main()
{
	int _;
	cin >> _;
	while(_--) {
		int l, r;
		scanf("%d %d", &l, &r);
		cout << getsum(r) - getsum(l-1) << endl;
	}

	return 0;
}