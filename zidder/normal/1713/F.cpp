#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

using namespace std;


/*
      3, 2      1, 2  0, 2   2, 2  
     /    \    /      |    /  |
    3, 1   1, 1       0, 1   2, 1
   /   \    |   \    /      /
  |     |   1, 0 0, 0      /
  |     |                 /
  3, 0  2, 0-------------

*/

const int N = 19;
char cntpar[(1<<N)+3][N+3], cntchild[(1<<N)+3][N+3];

void solve(int test_ind){
	int n;
    cin >> n;
    vector<int> b(n);
    for (int &i: b) scanf("%d", &i);
    vector<vector<int> > ans((1<<N), vector<int>(N+1, -1));


    vector<int> B(1<<N);
    for (int i=0;i<n;++i) B[(1<<N)-1-i] = b[i];
    // B[2^N-1-n] to B[2^N-1] is given
    // A[n] to A[2^N-1] = 0


    for (int i=0;i<(1<<N);++i) for (int j=0;j<N;++j){
        cntchild[i][j] = 2;
        cntpar[i][j] = 2;
    }

    // if i has bit j, than ans[i][j] = ans[i/j][j-1] ^ ans[i][j-1];
    // otherwise,           ans[i][j] = ans[i][j-1]

    vector<pair<int, int> > q;
    q.reserve((1<<N) * N);
    auto upd = [&](int v, int c){
        // if (ans[v][c] == -1) throw "error";
        if (c < N) {
            if ((v & (1<<c)) == 0) {
                if (ans[v][c+1] == -1) {
                    ans[v][c+1] = ans[v][c];
                    q.emplace_back(v, c+1);
                }
                cntchild[v^(1<<c)][c+1]--;
                if (cntchild[v^(1<<c)][c+1] == 0 && ans[v^(1<<c)][c+1] == -1) {
                    ans[v^(1<<c)][c+1] = ans[v][c] ^ ans[v^(1<<c)][c];
                    // if (ans[v^(1<<c)][c+1] == -1) {cerr<<ans[v][c] << " " << ans[v^(1<<c)][c] << endl;cerr << 50 << endl;throw "asdfsadfdsa";}
                    q.emplace_back(v^(1<<c), c+1);
                }
            } else {
                cntchild[v][c+1]--;
                if (cntchild[v][c+1] == 0 && ans[v][c+1] == -1) {
                    ans[v][c+1] = ans[v][c] ^ ans[v^(1<<c)][c];
                    // if (ans[v][c+1] == -1) {cerr<<ans[v][c] << " " << ans[v|(1<<c)][c] << endl;cerr << 57 << endl;throw "asdfsadfdsa";}
                    q.emplace_back(v, c+1);
                }
            }
            cntpar[v^(1<<c)][c]--;
            if (cntpar[v^(1<<c)][c] == 0 && ans[v^(1<<c)][c] == -1) {
                ans[v^(1<<c)][c] = ans[v][c] ^ ans[v|(1<<c)][c+1];
                // if (ans[v^(1<<c)][c] == -1) {cerr<<ans[v][c] << " " << ans[v|(1<<c)][c+1] << endl;cerr << 64 << endl;throw "asdfsadfdsa";}
                q.emplace_back(v^(1<<c), c);
            }
        }
        if (c) {
            if (v&(1<<(c-1))) {
                cntpar[v][c-1]--;
                // cerr << v << " " << c-1 << " cntpar-- " << cntpar[v][c-1] << endl;
                if (cntpar[v][c-1] == 0 && ans[v][c-1] == -1) {
                    // if (ans[v^(1<<(c-1))][c-1] == -1) {
                    //     cerr << "Heeeeyooo" << endl;
                    //     throw "err";
                    // }
                    ans[v][c-1] = ans[v][c] ^ ans[v^(1<<(c-1))][c-1];
                    q.emplace_back(v, c-1);
                }
                cntpar[v^(1<<(c-1))][c-1]--;
                if (cntpar[v^(1<<(c-1))][c-1] == 0 && ans[v^(1<<(c-1))][c-1] == -1) {
                    // if (ans[v][c-1] == -1) {
                    //     cerr << "Heeeeyeee" << endl;
                    //     throw "err";
                    // }
                    ans[v^(1<<(c-1))][c-1] = ans[v][c] ^ ans[v][c-1];
                    q.emplace_back(v^(1<<(c-1)), c-1);
                }
            } else {
                if (ans[v][c-1] == -1) {
                    ans[v][c-1] = ans[v][c];
                    q.emplace_back(v, c-1);
                }
            }
        }
    };
    for (int i=n;i<(1<<N);++i) {
        ans[i][0] = 0;
        upd(i, 0);
    }
    for (int i=0;i<n;++i) {
        ans[(1<<N)-1-i][N] = b[i];
        upd((1<<N)-1-i, N);
    }
    while (!q.empty()){
        auto p = q.back();
        q.pop_back();
        upd(p.first, p.second);
    }

    // for (int i=0;i<(1<<N);++i){
    //     for (int j=0;j<=N;++j){
    //         if (ans[i][j] == -1) {
    //             ans[i][j] = 0;
    //             upd(i, j);
    //             while (!q.empty()){
    //                 auto p = q.back();
    //                 q.pop_back();
    //                 upd(p.first, p.second);
    //             }
    //         }
    //     }
    // }
    vector<int> a(n);
    for (int i=0;i<n;++i) a[n-1-i] = ans[i][0];
    for (int i: a) printf("%d ", i);
    cout << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}