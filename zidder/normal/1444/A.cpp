#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	long long p, q, ip;
    cin >> p >> q;
    ip = p;
    if (p%q){
        cout << p << endl;
    }
    else {
        set<long long> mp;
        for (int i=2;i*i<=q;i++){
            int c = 0;
            while (q%i==0){
                q/=i;
                c++;
            }
            if (c){
                long long d = 1;
                while(p%i==0){
                    p /= i;
                    if (c>1)
                        c--;
                    else
                        d *= i;
                }
                mp.insert(d);
            }
        }
        if (q>1){
            long long d = 1;
            while(p%q==0){
                p /= q;
                d *= q;
            }
            mp.insert(d);
        }
        cout << ip / (*mp.begin()) << endl;
    }
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}