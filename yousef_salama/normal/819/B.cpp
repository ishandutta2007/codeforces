#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;

int n, p[MAXN];
int main(){
	scanf("%d", &n);

	multiset <int> R;

	long long r = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &p[i]);
		p[i]--;

		r += abs(p[i] - i);
		if(p[i] > i)R.insert(p[i] - i);
	}

	long long res = r;
	int id = 0;

	for(int i = n - 1, j = 1; i > 0; i--, j++){
		r += n;
		r -= 2 * R.size();

		while(!R.empty()){
			int t = *R.begin();
			if(t <= j){
				R.erase(R.begin());
			}else break;
		}

		r -= (n - 1) - p[i] + 1;
		r += p[i];

		if(p[i] > 0)R.insert(p[i] + j);

		if(r < res){
			res = r;
			id = j;
		}
	}
	printf("%I64d %d\n", res, id);
	return 0;
}