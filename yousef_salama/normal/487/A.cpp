#include <bits/stdc++.h>
using namespace std;

int hp[2], atk[2], def[2], h, a, d;
int main(){
	for(int i = 0; i < 2; i++)
		scanf("%d %d %d", &hp[i], &atk[i], &def[i]);
	scanf("%d %d %d", &h, &a, &d);

	int r = 1 << 30;
	for(int y = 0; y <= 1000; y++)
	for(int z = 0; z <= 1000; z++){
		int d0 = max(0, (atk[0] + y) - def[1]);
		int d1 = max(0, atk[1] - (def[0] + z));
		int c = y * a + z * d;

		if(d0 == 0)continue;
		if(d1 == 0){
			r = min(r, c);
			continue;
		}

		int t = (hp[1] + d0 - 1) / d0;
		int t2 = (hp[0] + d1 - 1) / d1;

		if(t2 > t){
			r = min(r, c);
			continue;
		}

		int x = (d1 + 1) - (hp[0] % d1) + d1 * (t - t2);
		r = min(r, x * h + c);
	}
	printf("%d\n", r);

	return 0;
}