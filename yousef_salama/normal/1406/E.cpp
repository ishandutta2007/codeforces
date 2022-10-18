#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int SQRT = 350;

int n;
bool notprime[MAXN], s[MAXN];
vector <int> primes;

int query(int a){
	int cnt = 0;
	for(int i = a; i <= n; i += a)
		cnt += s[i];
	return cnt;
}
int update(int a){
	int cnt = 0;
	for(int i = a; i <= n; i += a){
		cnt += s[i];
		s[i] = false;
	}
	return cnt;
}

int main(){
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++)s[i] = true;
	
	for(int i = 2; i <= n; i++){
		if(notprime[i])continue;
		
		primes.push_back(i);
		for(int j = 2 * i; j <= n; j += i)
			notprime[j] = true;
	}
	
	int j = 0, x = 1;
	
	while(j < (int)primes.size() && primes[j] < SQRT){
		printf("B %d\n", primes[j]);
		fflush(stdout);
		
		update(primes[j]);
		
		int r;
		scanf("%d", &r);
		
		printf("A %d\n", primes[j]);
		fflush(stdout);
		
		scanf("%d", &r);
		
		if(r != 0){
			x = primes[j];
			break;
		}
		
		j++;
	}
	
	if(x > 1){
		while(j < (int)primes.size()){
			while(1LL * x * primes[j] <= n){
				printf("A %d\n", x * primes[j]);
				fflush(stdout);
				
				int r;
				scanf("%d", &r);
				
				if(r != 0){
					x *= primes[j];
				}else{
					break;
				}
			}
			
			j++;
		}
		
		printf("C %d\n", x);
		return 0;
	}
	
	while(j < (int)primes.size()){
		int d = ((int)primes.size() - j + 1) / 2;
		
		for(int k = j; k < j + d; k++){
			printf("B %d\n", primes[k]);
			fflush(stdout);
			
			update(primes[k]);
			
			int r;
			scanf("%d", &r);
		}
		
		printf("A 1\n");
		fflush(stdout);
		
		int r, c = query(1);
		scanf("%d", &r);
		
		if(r == c){
			j += d;
			continue;
		}
		
		for(int k = j; k < j + d; k++){
			printf("A %d\n", primes[k]);
			fflush(stdout);
			
			int r;
			scanf("%d", &r);
			
			if(r != 0){
				printf("C %d\n", primes[k]);
				break;
			}
		}
		break;
	}
	printf("C 1\n");
	
	return 0;
}