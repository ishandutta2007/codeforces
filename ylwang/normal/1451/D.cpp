#include<bits/stdc++.h>
#define For(i, j, k) for(int i = (j); i <= (k); i++)
using namespace std;
int read() {
	int x = 0; char c = ' ';
	for(; !isdigit(c); c = getchar()) ;
	for(; isdigit(c); c = getchar()) x = x * 10 - '0' + c;
	return x;
}
#define ll long long
signed main() {
	int T = read();
	while(T--) {
		ll d = read(), k = read(), x = 0, y = 0;
        while(1) {
            if(x <= y && (x + k) * (x + k) + y * y <= d * d) x += k;
            else if(x > y && (y + k) * (y + k) + x * x <= d * d) y += k;
            else break;
        }
        printf(x == y ? "Utkarsh\n" : "Ashish\n");
	}
	return 0;
}
/*
1 3 4
*/