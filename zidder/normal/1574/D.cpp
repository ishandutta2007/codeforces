// https://codeforces.com/problemset/problem/1574/D

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

map<int, int> nodes[2000001];
int nind = 1;
void ban(vector<int> &ban, int node){
    for (int i=0;i<ban.size();++i){
        if (nodes[node].find(ban[i]) == nodes[node].end()){
            nodes[node][ban[i]] = nind++;
        }
        node = nodes[node][ban[i]];
    }
}

vector<vector<int> > c;

const int INF = 1000000001;

pair<int, vector<int> > find(int ind, int sm, int prevsum=0, int node=0){
    // got prevsum from ind to end before
    if (ind == c.size()) return make_pair(-INF, vector<int>());
    if (prevsum >= sm) return make_pair(-INF, vector<int>());
    sm -= c[ind].back();
    int cursum = -INF;
    vector<int> res;
    for (int i=c[ind].size()-1;i>=0;--i){
        if (c[ind][i] + sm <= prevsum) break;
        if (nodes[node].find(i) == nodes[node].end()){
            if (cursum < c[ind][i] + sm){
                res.clear();
                for (int j=c.size()-1;j>ind;--j) res.push_back(c[j].size() - 1);
                res.push_back(i);
                cursum = c[ind][i] + sm;
            }
            break;
        }
        auto ans = find(ind + 1, sm, cursum - c[ind][i], nodes[node][i]);
        if (ans.first + c[ind][i] > cursum) {
            cursum = ans.first + c[ind][i];
            res = ans.second;
            res.push_back(i);
        }
    }
    return make_pair(cursum, res);
}

void solve(int test_ind){
	int n;
    cin >> n;
    int sm = 0;
    for (int i=0;i<n;++i) {
        int l;
        cin >> l;
        c.emplace_back(l);
        for (int j=0;j<l;++j){
            scanf("%d", &c[i][j]);
        }
        sm += c[i].back();
    }
    int m;
    cin >> m;
    for (int i=0;i<m;++i){
        vector<int> b(n);
        for (int j=0;j<n;++j){
            scanf("%d", &b[j]);
            b[j]--;
        }
        ban(b, 0);
    }
    vector<int> v = find(0, sm).second;
    reverse(v.begin(), v.end());
    for (int i: v){
        cout << i + 1 << " ";
    }
    cout << endl;
}

int main(){
	int t=1;
	// cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}