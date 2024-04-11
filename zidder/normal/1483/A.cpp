    #include <iostream>
    #include <string>
    #include <vector>
    #include <algorithm>
    #include <map>
    #include <set>
     
    using namespace std;
     
    void solve(int test_ind){
    	int n, m;
        cin >> n >> m;
        vector<int> cnt(n+1);
        vector<vector<int> > v;
        vector<int> ans(m);
        bool no = false;
        for (int i=0;i<m;++i){
            int k;
            cin >> k;
            int x;
            if (k == 1){
                cin >> x;
                ans[i] = x;
                cnt[x]++;
                if (cnt[x] > (m + 1) / 2)
                {
                    no = true;
                }
                continue;
            }
            vector<int> vv;
            for (int j=0;j<k;j++){
                scanf("%d", &x);
                vv.push_back(x);
            }
            v.push_back(vv);
        }
                    if (no){cout << "NO" << endl;
                    return;}
        for (int i=m-1;i>=0;--i){
            if (ans[i] != 0)
                continue;
            for (int j = 0;j<v.back().size();j++){
                if (cnt[v.back()[j]] == (m+1)/2)
                    continue;
                cnt[v.back()[j]]++;
                ans[i] = v.back()[j];
                break;
            }
            v.pop_back();
        }
        cout << "YES" << endl;
        for (int x: ans)
            cout << x << " ";
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