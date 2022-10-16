#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> ans;
class Player {
  public:
    int id;
    vector<int> dupes;
    int cnt[101];
    bool inq[101];
    int top, current;

    void Input(int id) {
        this->id = id;
        for (int i = 1; i <= 100; i++) cnt[i] = 0;
        for (int i = 1; i <= 100; i++) inq[i] = 0;
        for (int i = 1, d; i <= n; i++) {
            cin >> d;
            cnt[d]++;
            if (cnt[d] == 2) {
                dupes.push_back(d);
                inq[d] = 1;
            }
        }
    }

    int GetDupe() {
        while ((!dupes.empty()) && (cnt[dupes.back()] < 2)) {
            inq[dupes.back()] = 0;
            dupes.pop_back();
        }
        if (dupes.empty())
            return 0;
        else
            return dupes.back();
    }

    void PrepareForFinalize() {
        top = id % n + 1;
        current = top;
    }

    int DoFinal() {
        int given = current;
        Give(current);
        current--;
        if (current == 0) current = n;
        if (current == id) {
            top = top % n + 1;
            current = top;
        }
        return given;
    }

    void Give(int item) {
        assert(cnt[item]);
        ans.back()[id - 1] = item;
        cnt[item]--;
    }

    void Recieve(int item) {
        cnt[item]++;
        if ((cnt[item] == 2) && (!inq[item])) {
            inq[item] = 1;
            dupes.push_back(item);
        }
    }

    bool IsPermutation() {
        for (int i = 1; i <= n; i++)
            if (cnt[i] != 1) return 0;
        return 1;
    }
} p[101];

void MakePermutation() {
    while (true) {
        int head = 1;
        while ((head <= n) && (!p[head].GetDupe())) head++;
        if (head == n + 1) return;
        ans.emplace_back();
        ans.back().resize(n);
        int item = p[head].GetDupe();
        p[head].Give(item);
        int current = head % n + 1;
        while (current != head) {
            p[current].Recieve(item);
            item = p[current].GetDupe();
            p[current].Give(item);
            current = current % n + 1;
        }
        p[head].Recieve(item);
    }
}

void MakeAnswer() {
    for (int i = 1; i <= n; i++) assert(p[i].IsPermutation());

    for (int i = 1; i <= n; i++) p[i].PrepareForFinalize();
    for (int i = 1; i <= n * (n - 1) / 2; i++) {
        ans.emplace_back();
        ans.back().resize(n);
        int given = 0, temp;
        for (int j = 1; j <= n; j++) {
            // cerr << i << ' ' << j << '\n';
            temp = p[j].DoFinal();
            if (j > 1) p[j].Recieve(given);
            given = temp;
        }
        p[1].Recieve(given);
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) p[i].Input(i);
    MakePermutation();
    // cerr << "Permutation done!\n";
    MakeAnswer();
    // cerr << "Finalize done!\n";
    cout << ans.size() << '\n';
    for (auto&& x : ans) {
        for (auto&& y : x) cout << y << ' ';
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}