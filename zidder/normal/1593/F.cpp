//https://codeforces.com/problemset/problem/1593/F

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

short dp[41][40][40][41];
void solve(int test_ind){
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    string s; cin >> s;
    for (int i=0;i<41;++i){
        for (int j=0;j<40;++j){
            for (int k=0;k<40;++k){
                for (int l=0;l<41;++l){
                    dp[i][j][k][l] = -1;
                }
            }
        }
    }

    dp[0][0][0][0] = 0;

    for (int i=0;i<n;++i){
        int d = s[i] - '0';
        for (int ra=0;ra<a;++ra){
            for (int rb=0;rb<b;++rb){
                for (int rc=0;rc<=i;++rc){
                    if (-1 == dp[i][ra][rb][rc]) continue;
                    dp[i+1][(ra * 10 + d) % a][rb][rc+1] = ra * 2 + 1;
                    dp[i+1][ra][(rb*10+d)%b][rc] = rb * 2;
                }
            }
        }
    }

    for (int d=0;d<=n;++d){
        int rc=-1;
        if (dp[n][0][0][(n+d)/2] != -1){
            rc = (n+d)/2;
        }
        if (dp[n][0][0][(n-d)/2] != -1){
            rc = (n-d)/2;
        }
        if (rc>0 && rc < n){
            string s = "";
            int ra=0, rb=0;
            for (int i=n;i>0;--i){
                int prv = dp[i][ra][rb][rc] / 2;
                if (dp[i][ra][rb][rc]%2){
                    s = "R" + s;
                    rc--;
                    ra = prv;
                } else {
                    rb = prv;
                    s = "B" + s;
                }
            }
            cout << s << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}