#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

#define FL fflush(stdout);

void solve(int test_ind){
    int n;
    cin >> n;
    int a, b;
    int k = n * n;
    vector<vector<int> > v(n, vector<int>(n));
    while (k-->0){
        cin >> a;
        int b, ii, jj=-1;
        for (b=1;b<=2;++b){
            if (a==b)
                continue;
            bool done=false;
            for (int i=0;i<n;++i){
                for (int j=0;j<n;++j){
                    if ((i+j)%2==b%2 && v[i][j]==0){
                        v[i][j] = b;
                        ii=i;
                        jj=j;
                        done = true;
                        break;
                    }
                }
                if (done)
                    break;
            }
            if (done) break;
        }
        if (jj==-1)
        {
            bool done=false;
            b=3;
            for (int i=0;i<n;++i){ for (int j=0;j<n;++j){
                    if (v[i][j]==0){
                        done=true;
                        ii=i;
                        jj=j;
                        v[i][j]=b;
                        break;
                    }
            }
            if (done)break;
        }
        }
        cout << b << " " << ii+1 << " " << jj+1 << std::endl;
        FL
    }
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}