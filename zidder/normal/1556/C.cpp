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
    vector<long long> c(n);
    for (int i=0;i<n;++i){
        cin >> c[i];
    }
    long long ans = 0;
    for (int i=0;i<n;i+=2){
        long long top=c[i], bottom=1;
        for (int j=i + 1;j<n;j+=2){
            top -= c[j];
            bottom -= c[j];
            if (bottom <= 0){
                if (top < 0)
                    ans -= bottom - top - 1;
                else
                    ans -= bottom - 1;
                bottom = 0;
            }
            if (top < 0)
                break;
            if (j+1<n)
                {top += c[j+1];bottom+=c[j+1];}
        }
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