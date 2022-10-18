#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const int MOD = 1000000007;

long long modpow(long long a, long long p){
	if(p == 0)return 1;
	if(p % 2 == 1)return (a * modpow(a, p - 1) % MOD);
	
	long long r = modpow(a, p / 2);
	return (r * r % MOD);
}
long long modinv(long long a){
	return modpow(a, MOD - 2);
}

long long res[MAXN];
vector <long long> mul(vector <long long> A, vector <long long> B){
	vector <long long> C((int)A.size() + (int)B.size() - 1, 0);
	
	for(int i = 0; i < (int)A.size(); i++)
	for(int j = 0; j < (int)B.size(); j++)
		C[i + j] = (C[i + j] + A[i] * B[j]) % MOD;
		
	return C;
}

int n, ui, vi, g[MAXN][MAXN], m[MAXN][MAXN];
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n - 1; i++){
		scanf("%d %d", &ui, &vi);
		ui--, vi--;
		
		g[ui][vi]++;
		g[vi][ui]++;
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n - 1; j++)
		for(int k = 0; k < n - 1; k++){
			if(j == k){
				m[j][k] = 0;
				for(int l = 0; l < n; l++){
					if(l == j)continue;
					
					if(g[j][l])m[j][k] = (m[j][k] + i) % MOD;
					else m[j][k] = (m[j][k] + 1) % MOD;
				}
			}else{
				if(g[j][k])m[j][k] = (MOD - i) % MOD;
				else m[j][k] = (MOD - 1) % MOD;
			}
		}
		
		/*for(int j = 0; j < n - 1; j++){
			for(int k = 0; k < n - 1; k++)
				cout << m[j][k] << ' ';
			cout << endl;
		}*/
		
		long long d = 1;
		for(int j = 0; j < n - 1; j++){
			bool found = false;
			for(int k = j; k < n - 1; k++){
				if(m[k][j] != 0){
					found = true;
					
					if(k != j){
						d = (MOD - d) % MOD;
						for(int l = 0; l < n - 1; l++)
							swap(m[k][l], m[j][l]);
					}
					break;
				}
			}
			if(!found){
				d = 0;
				break;
			}
			
			d = (d * m[j][j]) % MOD;
			
			for(int k = j + 1; k < n - 1; k++){
				if(m[k][j] != 0){
					long long r = m[k][j] * modinv(m[j][j]) % MOD;
					for(int l = j; l < n - 1; l++)
						m[k][l] = (m[k][l] + (MOD - r) * m[j][l]) % MOD;
				}
			}
		}
		
		//cout << "---->" << d << endl;
		
		vector <long long> v;
		v.push_back(1);
		
		long long y = 1;
		
		for(int j = 0; j < n; j++){
			if(i == j)continue;
			
			vector <long long> w;
			w.push_back((MOD - j) % MOD);
			w.push_back(1);
			
			v = mul(v, w);
			y = y * (i - j + MOD) % MOD; 
		}
		
		/*cout << "**** ";
		for(int j = 0; j < (int)v.size(); j++)
			cout << v[j] << ' ';
		cout << endl;
		*/
		y = d * modinv(y) % MOD;
	
		
		for(int i = 0; i < n; i++)
			res[i] = (res[i] + y * v[i]) % MOD;
	
		//cout << "==================" << endl;
	}
	
	for(int i = 0; i < n; i++){
		if(i > 0)printf(" ");
		printf("%lld", res[i]);
	}
	printf("\n");
	
	return 0;
}