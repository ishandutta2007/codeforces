#include <bits/stdc++.h>
using namespace std;

const int MAXN = 205;

int n, k, a[MAXN];
int main(){
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int r = -1 << 30;
	for(int i = 0; i < n; i++)
	for(int j = i; j < n; j++){
		multiset <int> p, q;

		int s = 0;
		for(int k = 0; k < n; k++){
			if(k >= i && k <= j){
				p.insert(a[k]);
				s += a[k];
			}else q.insert(a[k]);
		}

		int rk = k;
		while(rk > 0 && !p.empty() && !q.empty()){
			int a = *p.begin();
			int b = *(--q.end());

			if(a < b){
				s += b - a;

				p.erase(p.begin());
				p.insert(b);

				q.erase(--q.end());
				q.insert(a);
			}else break;

			rk--;
		}
		r = max(r, s);
	}
	printf("%d\n", r);

}