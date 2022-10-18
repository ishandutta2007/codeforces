#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

struct question{
	int t, a, ind;
	bool operator <(const question& q) const{
		return t < q.t;
	}
};

int n, T;
question v[MAXN];

bool can(int k){
	int j = 0, sum = 0;
	for(int i = 0; i < n && j < k; i++)if(v[i].a >= k){
		sum += v[i].t;
		j++;
	}
	
	if(j == k && sum <= T)return true;
	else return false;
}

int main(){
	scanf("%d %d", &n, &T);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &v[i].a, &v[i].t);
		v[i].ind = i;
	}
	sort(v, v + n);
	
	int L = 0, R = n;
	while(L < R){
		int mid = (L + R + 1) / 2;
		if(can(mid))L = mid;
		else R = mid - 1;
	}
	
	printf("%d\n%d\n", L, L);
	for(int i = 0, j = 0; i < n && j < L; i++)if(v[i].a >= L){
		if(j > 0)printf(" ");
		printf("%d", v[i].ind + 1);
		j++;
	}
	printf("\n");
	
	return 0;
}