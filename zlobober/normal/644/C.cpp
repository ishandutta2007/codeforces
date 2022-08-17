#include <cstdio>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

map<string, vector<string>> M;
map<vector<string>, vector<string>> rev_M;

const int LEN = 1050;

char buf[LEN];



int main() {
    int n;
    scanf("%d ", &n);
    set<string> cache;
    for (int i = 0; i < n; i++) {
        scanf("%s", buf);
        string s(buf);
        if (!cache.insert(s).second)
            continue;
        int pt = 7;
        while (buf[pt] != 0 && buf[pt] != '/')
            pt++;
        string a(buf, buf + pt);
        string b(buf + pt);
        M[a].push_back(b);
    }

    for (auto& it : M) {
        sort(it.second.begin(), it.second.end());
        rev_M[it.second].push_back(it.first);
    }
    
    vector<vector<string>> res;
    for (auto& it : rev_M) {
        if (it.second.size() > 1)
            res.push_back(it.second);
    }

    printf("%d\n", (int)res.size());
    for (auto& it : res) {
        for (auto& name : it) {
            printf("%s ", name.data());
        }
        printf("\n");
    }
}