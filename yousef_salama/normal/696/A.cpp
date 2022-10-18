#include <bits/stdc++.h>
using namespace std;

int q, ti;
long long ui, vi, wi;

int depth(long long u){
	int d = 0;
	while(u != 1){
		u /= 2;
		d++;
	}
	return d;
}

map <long long, long long> C;
int main(){
	scanf("%d", &q);

	while(q--){
		scanf("%d", &ti);

		if(ti == 1){
			scanf("%I64d %I64d %I64d", &ui, &vi, &wi);

			int du = depth(ui);
			int dv = depth(vi);

			while(du > dv){
				C[ui] += wi;
				ui /= 2;
				du--;
			}
			while(dv > du){
				C[vi] += wi;
				vi /= 2;
				dv--;
			}

			while(ui != vi){
				C[ui] += wi;
				C[vi] += wi;

				ui /= 2;
				du--;

				vi /= 2;
				dv--;
			}
		}else{
			scanf("%I64d %I64d", &ui, &vi);

			int du = depth(ui);
			int dv = depth(vi);

			long long r = 0;
			while(du > dv){
				r += C[ui];
				ui /= 2;
				du--;
			}
			while(dv > du){
				r += C[vi];
				vi /= 2;
				dv--;
			}

			while(ui != vi){
				r += C[ui];
				r += C[vi];

				ui /= 2;
				du--;

				vi /= 2;
				dv--;
			}
			printf("%I64d\n", r);
		}
	}
	return 0;
}