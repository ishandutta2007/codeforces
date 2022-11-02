#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int maxn = 5e5 + 5;

long long pre[maxn];
long long psum[maxn];
int a[maxn];
int cnt[maxn];
int n;

#define TOO_SMALL -1
#define OK 0
#define TOO_BIG 1

int check(int value){
	//cout << value << endl;
	memset(cnt, 0, sizeof(cnt));
	long long S = 0;
	for(int i = 1;i <= n;i++){
		cnt[a[i]]++;
		S += a[i];
	}
	S += value;
	cnt[value]++;
	pre[0] = cnt[0];
	psum[0] = 0;
	for(int i = 1;i <= n;i++){
		pre[i] = pre[i - 1] + cnt[i];
		psum[i] = psum[i - 1] + 1LL * i * cnt[i];
	}
	
	long long left = 0, right = 0;
	bool used = false;
	long long less = 0;
	int j = 1;
	for(int i = 1;i <= n + 1;i++){
		int val;
		if(!used){
			if(i == n + 1 || a[j] < value){
				val = value;
				used = true;
			}else{
				val = a[j++];
			}
		}else{
			val = a[j++];
		}
		left += val;
		--cnt[val];
		right -= min(val, i-1);
		less += cnt[i - 1];
		right += (n + 1 - i - less);
		//cout << left << " " << right + 1LL * i * (i - 1) << endl;
		if(left > right + 1LL * i * (i - 1)){
			if(!used){
			   	return TOO_SMALL;
			}
			else{
			   	return TOO_BIG;
			}
		}
	}	
	return OK;
}

bool cmp(int a, int b){
	return a > b;
}

int main(){
	while(cin >> n){
		long long sum = 0;
		for(int i = 1;i <= n;i++){
			scanf("%d", &a[i]);
			sum += a[i];
		}
		int parity = sum & 1;
		sort(a + 1, a + 1 + n, cmp);
		int lb = -1;
		int l = 0, r = (n - parity) / 2;
		while(l <= r){
			int mid = (l + r) / 2;
			int status = check(2*mid + parity);
			if(status == TOO_SMALL){
				l = mid + 1;
			}else{
				r = mid - 1;
				if(status == OK){
					lb = mid;
				}
			}
		}
		int rb = -1;
		l = lb, r = (n - parity) / 2;
		while(l <= r){
			int mid = (l + r) / 2;
			int status = check(2*mid + parity);
			if(status == TOO_BIG){
				r = mid - 1;	
			}else{
				l = mid + 1;
				if(status == OK){
					rb = mid;
				}
			}
		}
		if(lb == -1 || rb == -1) printf("-1\n");
		else{
			for(int i = lb;i <= rb;i++)
				printf("%d ", 2 * i + parity);
			puts("");
		}
	}	
	return 0;
}