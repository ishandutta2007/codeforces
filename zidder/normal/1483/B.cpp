#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int lb(set<int>& st, int x){
    auto it = st.lower_bound(x);
    if (it != st.end())
        return *it;
    if (st.empty())
        return -1;
    return *st.begin();
}

void solve(int test_ind){
	int n;
    cin >> n;
    vector<int> v(n);
    set<int> inds, all_songs;
    for (int i=0;i<n;++i){
        scanf("%d", &v[i]);
    }
    for (int i=0;i<n;++i){
        all_songs.insert(i);
        if (__gcd(v[i], v[(i+1)%n])==1)
            inds.insert(i);
    }
    vector<int> ans;
    int curind = 0;
    while (!inds.empty()){
        //for (int x: inds)
        //    cout << x << " ";
        //cout << endl;
        int badind = lb(inds, curind);
        int nxtbadind = lb(all_songs, badind + 1);
        inds.erase(badind);
        //cout << curind << " " << badind << " " << nxtbadind << endl;
        all_songs.erase(nxtbadind);
        ans.push_back(nxtbadind);
        int nnxtbadind = lb(all_songs, badind + 1);
        if (nnxtbadind == -1)
            break;
        if (inds.find(nxtbadind) != inds.end())
            inds.erase(nxtbadind);
        if (__gcd(v[badind], v[nnxtbadind]) == 1){
            //cout << "bad " << v[badind] << " " << v[nnxtbadind] << endl;
            inds.insert(badind);
        }
        curind = nnxtbadind;
    }
    cout << ans.size();
    for (int x: ans)
        cout << " " << x + 1;
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