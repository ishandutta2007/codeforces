#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<char, int> pci;
#define sz(x) ((int)x.size())
#define f first
#define s second
#define mp make_pair

int n;
string s;


int main() {
    cin >> s;
    n = s.length();

    vector<pci> v;
    v.push_back(mp(s[0], 1));
    for(int i = 1; i < n; i++) {
        if (v.back().first == s[i]) {
            v[sz(v)-1].second += 1;
        } else {
            v.push_back(mp(s[i], 1));
        }
    }

    if (sz(v) % 2 == 0) {
        cout << 0 << endl;
        return 0;
    }

    int mid = sz(v)/2;
    int l = mid-1;
    int r = mid+1;
    
    while(l >= 0) {
        if (v[l].first != v[r].first || v[l].second + v[r].second < 3) {
            cout << 0 << endl;
            return 0;
        }
        l -= 1, r += 1;
    }

    if (v[mid].second < 2) {
        cout << 0 << endl;
        return 0;
    }

    cout << v[mid].second + 1 << endl;

    return 0;
}