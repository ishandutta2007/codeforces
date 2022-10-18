#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5005;
const int MOD = 1000000007;

int n, m, s[MAXN], d[MAXN], cm[MAXN], L[MAXN][MAXN], R[MAXN][MAXN], fi, hi;
vector <int> c[MAXN];
 
int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", &s[i]);
		s[i]--;
		
		d[s[i]]++;
	}
	
	memset(L, -1, sizeof L);
	memset(R, -1, sizeof R);
	
	for(int i = 0; i < n; i++){
		cm[s[i]]++;
		L[s[i]][cm[s[i]]] = i; 
	}
	
	memset(cm, 0, sizeof cm);
	for(int i = n - 1; i >= 0; i--){
		cm[s[i]]++;
		R[s[i]][cm[s[i]]] = i;
	}
	
	for(int i = 0; i < m; i++){
		scanf("%d %d", &fi, &hi);
		c[fi - 1].push_back(hi);
	}
	
	long long resr = 0, cntr = 1;
	for(int i = 0; i < n; i++){
		long long cur = 0;
		for(int h : c[i]){
			if(R[i][h] != -1){
				cur++;
			}
		}
		if(cur > 0){
			resr++;
			cntr = cntr * cur % MOD;
		}
	}
	
	for(int fi = 0; fi < n; fi++)
	for(int hi : c[fi])if(L[fi][hi] != -1){
		long long res = 1, cnt = 1;
		for(int i = 0; i < n; i++){
			if(i != fi){
				long long cur = 0, cl = 0, cr = 0, clr = 0;
				for(int h : c[i]){
					bool left = L[i][h] != -1 && L[i][h] < L[fi][hi];
					bool right = R[i][h] != -1 && R[i][h] > L[fi][hi];
					
					if(left && right)clr++;
					else if(left)cl++;
					else if(right)cr++;
				}
				
				cur = cl * cr + clr * (cl + cr) + clr * (clr - 1);
				if(cur > 0){
					res += 2;
					cur = cur % MOD;
					cnt = (cnt * cur) % MOD;
				}else{
					if(cl + cr + clr > 0){
						res += 1;
						cnt = (cnt * (cl + cr + 2 * clr)) % MOD;
					}
				}
			}else{
				long long cr = 0;
				for(int h : c[i]){
					if(h == hi)continue;
					
					if(R[i][h] != -1 && R[i][h] > L[fi][hi])cr++;
				}
				
				if(cr > 0){
					res += 1;
					cnt = (cnt * cr) % MOD;
				}
			}
		}
		
		if(res == resr){
			cntr = (cntr + cnt) % MOD;
		}else if(res > resr){
			resr = res;
			cntr = cnt;
		}
	}
	
	printf("%lld %lld\n", resr, cntr);
	
	return 0;
}