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

int n, x, cnt[3];
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		cnt[x]++;
	}
	if(cnt[2]){
		cnt[2]--;
		printf("2 ");
	}

	if(cnt[1] & 1){      
		while(cnt[1]--)
			printf("1 ");
		while(cnt[2]--)
			printf("2 ");
	}else{
		if(cnt[1] == 0){
			while(cnt[2]--)
				printf("2 ");
		}else{
			cnt[1]--;
			while(cnt[1]--)
				printf("1 ");
			while(cnt[2]--)
				printf("2 ");
			printf("1 ");
		}
	}
	return 0;
}