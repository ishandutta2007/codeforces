#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
    int n;
    cin >> n;
    vector<long long> v(n);
    for(int i=0;i<n;++i){
        scanf("%lld", &v[i]);
    }
    vector<int> p(20);
    for(int i=0;i<n;++i){
        for(int j=0;j<20;j++){
            if((1<<j) & v[i])
                p[j]++;
        }
    }
    long long ans=0;
    int nz=1;
    while(nz){
        nz=0;
        for(int i=0;i<20;i++){
            if(p[i])
                nz++;
        }
        long long q=0;
        int mi=0;
        for(int i=0;i<20;++i){
            if (p[i]){
                mi = mi?min(mi, p[i]):p[i];
            }
        }
        for(int i=0;i<20;++i){
            if (p[i]){
                p[i] -= mi;
                q |= (1 << i);
            }
        }
        ans += (q * q) * mi;
    }
    cout << ans << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}