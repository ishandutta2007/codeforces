#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int> > res(n, vector<int>(n, 0));
    vector<string> names(n);
    map<string, int> teams;
    for (int i = 0; i < n; ++i) {
        string team;
        cin >> team;
        teams[team] = i;
        names[i] = team;
    }
    for (int i = 0; i < (n * (n - 1)) / 2; ++i) {
        string buf, team1, team2;
        cin >> buf;
        int i;
        for (i = 0; i < buf.size(); ++i) {
            if (buf[i] == '-') 
                break;
            else
                team1.push_back(buf[i]);
        }
        for (int j = i + 1; j < buf.size(); ++j)
            team2.push_back(buf[j]);
        cin >> buf;
        string res1, res2;
        for (i = 0; i < buf.size(); ++i) {
            if (buf[i] == ':') 
                break;
            else
                res1.push_back(buf[i]);
        }
        for (int j = i + 1; j < buf.size(); ++j)
            res2.push_back(buf[j]);
        int t1 = teams[team1], t2 = teams[team2];
        res[t1][t2] = atoi(res1.c_str());
        res[t2][t1] = atoi(res2.c_str());
    }
    vector<vector<int> > results(n);
    for (int i = 0; i < n; ++i) {
        int sum = 0, diff = 0, sum1 = 0;
        for (int j = 0; j < n; ++j) if (j != i) {
            sum1 += res[i][j];
            diff += (res[i][j] - res[j][i]);
            if (res[i][j] > res[j][i])
                sum += 3;
            if (res[i][j] == res[j][i])
                sum += 1;
        }
        results[i].push_back(sum);
        results[i].push_back(diff);
        results[i].push_back(sum1);
        results[i].push_back(i);
    }
    sort(results.begin(), results.end());
    vector<string> out;
    for (int i = 1; i <= n / 2; ++i)
        out.push_back(names[results[n - i][3]]);
    sort(out.begin(), out.end());
    for (int i = 0; i < out.size(); ++i)
        cout << out[i] << endl;
    return 0;
}