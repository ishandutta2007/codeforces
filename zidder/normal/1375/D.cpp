#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int mex(vector<int>& c){
    int m=0;
    while(c[m])m++;
    return m;
}

void solve(int test_ind){
	int n;
    cin >> n;
    vector<int> v(n), c(n+1);
    for(int i=0;i<n;++i){
        cin >> v[i];
        c[v[i]]++;
    }
    vector<int> ans;
    while(true){
        int m = mex(c);
        if (m==n)
            break;
        ans.push_back(m);
        c[v[m]]--;
        c[m]++;
        v[m] = m;
    }
    for (int i=0;i<n;++i){
        for(int j=i+1;j<n;j++){
            if (v[j] == i){
                int m = mex(c);
                ans.push_back(j);
                c[v[j]]--;
                v[j] = m;
                c[m]++;
                break;
            }
        }
        if (v[i] == i)
            continue;
        ans.push_back(i);
        c[v[i]]--;
        c[i]++;
        v[i] = i;
    }

    cout << ans.size() << endl;
    for(int i=0;i<ans.size();++i)
        cout << 1+ans[i] << " ";
    cout << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}