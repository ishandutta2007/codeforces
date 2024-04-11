#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, k, a[N], b[N], aa[N], bb[N];
char s[N];
void win(){
	printf("tokitsukaze");
	exit(0);
}
void lose(){
	printf("quailty");
	exit(0);
}
void draw(){
	printf("once again");
	exit(0);
}
int main()
{
	scanf("%d%d", &n, &k);
	scanf("%s", s + 1);
	for(int i = 1, j = 0; i <= n; i++){
		a[i] = a[i - 1];
		if(s[i] == '1' && i > j)
			a[i]++, j = i + k - 1;
	}
    for(int i = n, j = n + 1; i >= 1; i--){
		aa[i] = aa[i + 1];
		if(s[i] == '1' && i < j)
			aa[i]++, j = i - k + 1;
	}
    for(int i = 1, j = 0; i <= n; i++){
		b[i] = b[i - 1];
		if(s[i] == '0' && i > j)
			b[i]++, j = 
			i + k - 1;
	}
	for(int i = n, j = n + 1; i >= 1; i--){
		bb[i] = bb[i + 1];
		if(s[i] == '0' && i < j)
			bb[i]++, j = i - k + 1;
	}
	if(a[n] <= 1 || b[n] <= 1)
		win();
	for(int i = 1; i + k - 1 <= n; i++){
		int l = i, r = i + k - 1;
		if(a[l - 1] + aa[r + 1] > 1)
			draw();
		if(b[l - 1] + bb[r + 1] > 1)
			draw();
	}
	lose();
	return 0;
}