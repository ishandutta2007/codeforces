// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fbo find_by_order
#define ook order_of_key
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define MOD 1000000007 
#define MID (l+r)/2
#define ALL(x) x.begin(),x.end()
#define debug(x) cout<<#x<<" = "<<(x)<<endl
#define mx 300003
#define pc(x) putchar_unlocked(x);
#define sz(x) (long long)(x.size())
#define lt(x) (long long)(x.length())
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds;

long long n[mx];
string ss[mx];

void gagal(){
	cout << "OVERFLOW!!!\n";
	exit(0);
}

int main(){
	// ios_base::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
	int t;
	cin >> t;
	vector<int> ve;
	for(int i = 0; i < t; i++){
		cin >> ss[i];
		if(ss[i] == "add"){
			ve.pb(i);
		}
		else if(ss[i] == "for"){
			ve.pb(i);
			cin >> n[i];
		}
		else{
			if(ss[ve.back()] == "for"){
				ve.pop_back();
				while(sz(ve) > 1){
					if(ss[ve[sz(ve) - 1]] == "end" && ss[ve[sz(ve) - 2]] == "for"){
						ve.pop_back();
						ve.pop_back();
					}
					else break;
				}
			}
			else{
				ve.pb(i);
			}
		}
	}
	stack<long long> st;
	long long tambah = 1, sum = 0;
	for(int i : ve){
		// debug(i);
		if(ss[i] == "add"){
			sum += tambah;
			if(sum > (1LL << 32) - 1)
				gagal();
		}
		else if(ss[i] == "for"){
			tambah *= n[i];
			if(tambah > (1LL << 32) - 1)
				gagal();
			st.push(n[i]);
		}
		else{
			tambah /= st.top();
			st.pop();
		}
	}
	cout << sum << endl;
}