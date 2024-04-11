#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
#define mx 100003
#define pc(x) putchar_unlocked(x);
#define sz(x) (long long)(x.size())
#define lt(x) (long long)(x.length())
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds;

long long tanya(int x, int y){
	cout << "? " << x << ' ' << y << endl;
	int ret;
	cin >> ret;
	return ret;
}

long long a[6] = {4 , 8, 15, 16, 23, 42};

int main(){
	// ios_base::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
	long long sa = tanya(1, 2);
	long long du = tanya(2, 3);
	long long ti = tanya(4, 5);
	long long em = tanya(5, 6);
	do{
		if(a[0] * a[1] == sa && a[1] * a[2] == du){
			if(a[3] * a[4] == ti && a[4] * a[5] == em){
				cout << "! " << a[0] << ' ' << a[1] << ' ' << a[2] << ' ' << a[3] << ' ' << a[4] << ' ' << a[5] << endl;
				return 0;
			}
		}
	}while(next_permutation(a, a + 6));
}