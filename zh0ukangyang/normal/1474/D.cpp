#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e6 + 7;
int n, m, a[N], dl[N], dr[N], Canl[N], Canr[N];
void Main() {
	scanf("%d", &n);
	L(i, 1, n) scanf("%d", &a[i]);
	L(i, 0, n + 1) dl[i] = dr[i] = Canl[i] = Canr[i] = 0;
	int now;
	Canl[0] = Canr[n + 1] = 1;
	
	now = 0;
	L(i, 1, n) {
		if(a[i] < now) Canl[i] = 0;
		else Canl[i] = 1; 
		Canl[i] &= Canl[i - 1];
		now = a[i] - now, dl[i] = now;
	}
	
	now = 0;
	R(i, n, 1) {
		if(a[i] < now) Canr[i] = 0;
		else Canr[i] = 1;
		Canr[i] &= Canr[i + 1];
		now = a[i] - now, dr[i] = now;
	}
	
	if(Canl[n] && !dl[n]) return puts("YES"), void();
	
//	cout << Canl[1] << " " << Canr[n + 1] << endl;
//	cout << a[2 + 1] - dl[2] << " " << a[2] - dr[2 + 2] << endl; 
	L(i, 1, n - 1) {
		if(Canl[i - 1] && Canr[i + 2] && a[i + 1] >= dl[i - 1] && a[i] >= dr[i + 2] && a[i + 1] - dl[i - 1] == a[i] - dr[i + 2]) {
			puts("YES");
			return;
		} 
	}
	puts("NO");
}
int main() {
	int T; scanf("%d", &T);
	while(T--) Main();
	return 0;
}