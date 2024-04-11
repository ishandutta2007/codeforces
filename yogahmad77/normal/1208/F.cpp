#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define ALL(x) x.begin(),x.end()
#define debug(x) cout<<#x<<" = "<<(x)<<endl
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())
#define MOD 1000000007 
#define mx 100003



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n), F(1 << 21, 0), satu(1 << 21, -1), dua(1 << 21, -1);

	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = n - 1; i >= 0; i--){
		int inv = (1 << 21) - a[i] - 1;
		// debug(inv);
		F[inv] += 1;
		if(dua[inv] == -1)
			dua[inv] = i;
		else if(satu[inv] == -1)
			satu[inv] = i;
	}
	// debug(n);
	for(int i = 0; i < 21; i++){
		// debug(i);
		for(int j = 0; j < 1 << 21; j++){
			if(j & (1 << i)){
				F[j] += F[j ^ (1 << i)];
				int x = j ^ (1 << i);
				if(dua[j] < dua[x]){
					satu[j] = dua[j];
					dua[j] = dua[x];
				}
				else if(satu[j] < dua[x]){
					satu[j] = dua[x];
				}

				if(satu[j] < satu[x]){
					satu[j] = satu[x];
				}
			}
		}
	}
	// debug(F[(1 << 21) - 1]);
	// debug(satu[(1 << 21) - 1]);
	// debug(dua[(1 << 21) - 1]);
	// debug(n);
	int ans = 0;
	for(int i = 0; i < n - 2; i++){
		int jaw = a[i], sem = 0;
		for(int j = 20; j >= 0; j--){
			if(a[i] & (1 << j))
				continue;
			int aa = sem | (1 << j);
			if(jaw == 8 && j == 2){
				// debug(aa);
			}
			int inv = (1 << 21) - aa - 1;
			// debug(inv);
			if(F[inv] > 1 && satu[inv] > i){
				sem += 1 << j;
				jaw += 1 << j;
			}
		}
		ans = max(ans, jaw);
	}
	cout << ans << endl;
}