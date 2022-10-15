#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

pair<int, int> farthest(int v, vector<vector<int> > &g, int u=-1){
    vector<int> d(g.size(), -1);
    d[v] = 0;
    vector<int> q(1, v);
    for(int i=0;i<q.size();++i){
        for(int w: g[q[i]]){
            if (d[w]==-1){
                d[w]=d[q[i]]+1;
                q.push_back(w);
            }
        }
    }
    if (u==-1)
        return make_pair(q.back(), d[q.back()]);
    else
        return make_pair(u, d[u]);
}

int diam(vector<vector<int> > &g){
    return farthest(farthest(0, g).first, g).second;
}

void solve(int test_ind){
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    a--;b--;
    vector<vector<int> > g(n);
    for(int i=1;i<n;++i){
        int u, v;
        scanf("%d%d", &u, &v);
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int d = diam(g);
    if (da * 2 >= d){
        cout << "Alice" << endl;
        return;
    }
    if (da * 2 >= db){
        cout << "Alice" << endl;
        return;
    }
    if (farthest(a, g, b).second <= da){
        cout << "Alice" << endl;
        return;
    }
    cout << "Bob" << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}