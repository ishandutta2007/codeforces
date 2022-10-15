#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;


long long dot(long long v1x, long long v1y, long long v2x, long long v2y){
    return v1x * v2x + v2y * v1y;
}

long long cross(long long v1x, long long v1y, long long v2x, long long v2y){
    return v1x * v2y - v2x * v1y;
}


vector<int> ans;
vector<pair<int, int> > A;

long long ln(int i, int j){
    long long dx = A[i].first - A[j].first;
    long long dy = A[i].second - A[j].second;
    return dx * dx + dy * dy;
}

void solve(int test_ind){
    int n;
    cin >> n;
    A = vector<pair<int, int> > (n);
    for(int i=0;i<n;++i){
        cin >> A[i].first >> A[i].second;
    }

    ans.push_back(0);
    set<int> s;
    s.insert(0);
    for (int i=1;i<n;++i){
        int mx;
        long long mxl=0;
        for (int j=0;j<n;j++){
            long long l = ln(ans.back(), j);
            if (s.count(j) == 0 && l > mxl){
                mxl = l;
                mx = j;
            }
        }
        ans.push_back(mx);
        s.insert(mx);
    }
    for (int i: ans)
        cout << 1+i << " ";
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