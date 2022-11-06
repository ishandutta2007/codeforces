#include "bits/stdc++.h"
#pragma warning(disable:4996)
using namespace std;



int main() {
    string fst; cin >> fst;
    string tst; cin >> tst;

    vector<pair<int, int>>anss;
    for (int i = 0; i < tst.size();++i) {
        pair<int, int>nowans(-1, 0);
        for (int j = 0; j < fst.size(); ++j) {
            
            if (tst[i] != fst[j]) {
                continue;
            }
            if (nowans.first == -1) {
                nowans = make_pair(j, 0);
            }
            {
                pair<int, int>ans(j, 0);
                int num = 0;
                while (1) {
                    if (j -num <0) {
                        ans = make_pair(j, 1-num);
                        break;
                    }
                    if (i + num >= tst.size()) {
                        ans = make_pair(j, 1-num);
                        break;
                    }
                    else {

                        if (tst[i + num] == fst[j - num]) {
                        }
                        else {
                            ans = make_pair(j, 1-num);
                            break;
                        }
                    }
                    

                    num++;
                }
                if (abs(nowans.second) < abs(ans.second)) {
                    nowans = ans;
                }
            }

            

            {
                pair<int, int>ans(j, 0);
                int num = 0;
                while (1) {
                    if (j + num == fst.size()) {
                        ans = make_pair(j, num-1);
                        break;
                    }
                    if (i + num >= tst.size()) {
                        ans = make_pair(j, num - 1);
                        break;
                    }
                    else {

                        if (tst[i + num] == fst[j + num]) {
                        }
                        else {
                            ans = make_pair(j, num - 1);
                            break;
                                
                        }
                    }
                    num++;
                    
                }
                if (abs(nowans.second) < abs(ans.second)) {
                    nowans = ans;
                }
            }
        }
        if (nowans.first == -1) {
            cout << -1 << endl;
            return 0;
        }
        i += abs(nowans.second);
        anss.push_back(nowans);
    }
    cout << anss.size() << endl;
    for (int i = 0; i < anss.size(); ++i) {
        cout << anss[i].first+1 << " " << anss[i].first + anss[i].second+1 << endl;

    }
    return 0;
}