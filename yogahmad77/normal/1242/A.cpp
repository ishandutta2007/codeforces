#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define ALL(x) x.begin(),x.end()
 
template <typename T>
void cetak(T t){cout << t << ')' << endl;}
template <typename T, typename... V>
void cetak(T t, V... v) {cout << t; if (sizeof...(v)) cerr << ", "; cetak(v...);}
 
#define debug(x...) cout<< '(' << #x << ") = ("; cetak(x) 
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())

const int MOD = 1e9 + 7;
const int mx = 1e5 + 10;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long n, m;
	cin >> n;
	m = n;
	set<long long> faktor;
	for(long long i = 2; i * i <= n; i++){
		if(n % i == 0){
			faktor.insert(i);
			faktor.insert(n / i);
		}
	}
	long long apa;
	int cnt = 0;
	for(auto i : faktor){
		if(n % i != 0) continue;
		cnt += 1;
		while(n % i == 0){
			n /= i;
		}
		apa = i;
	}
	if(n > 1){
		cout << n << endl;
		return 0;
	}
	if(cnt == 1){
		cout << apa << endl;
	}
	else cout << 1 << endl;
}