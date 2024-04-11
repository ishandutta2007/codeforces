#include <cstdio>
#include <tuple>
#include <cassert>
#include <algorithm>
using namespace std;

const int N = 200500;
int X[N];

typedef long long llong;

vector<int> best_sing;
vector<pair<int, int>> best_seg;
llong best_nu = 1, best_de = -1;

llong S[N];

pair<llong, llong> calc(const vector<int>& sing, const vector<pair<int, int>>& seg, llong med_nu, llong med_de) {
    llong sum = 0;
    int len = 0;
    for (int i : sing) {
        sum += X[i];
        len++;
    }
    for (pair<int, int> s : seg) {
        sum += S[s.second] - S[s.first];
        len += s.second - s.first;
    }
    llong sum_nu = sum, sum_de = len;
    llong res_nu = sum_nu * med_de - sum_de * med_nu, res_de = sum_de * med_de;
    return make_pair(res_nu, res_de);
}

void relax(vector<int> sing, vector<pair<int, int>> seg, llong med_nu, llong med_de) {
    llong res_nu, res_de;
    tie(res_nu, res_de) = calc(sing, seg, med_nu, med_de);
    if ((best_de == -1) || (res_nu * best_de > best_nu * res_de)) {
        best_sing = sing;
        best_seg = seg;
        best_nu = res_nu;
        best_de = res_de;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &X[i]);
    }
    sort(X, X + n);
    for (int i = 0; i < n; i++) {
        S[i + 1] = S[i] + X[i];
    }

    // odd
    {
        for (int c = 0; c < n; c++) {
            int l = 0, r = min(c, n - c - 1) + 1;
            while (r - l > 1) {
                int q = (l + r) / 2;
                assert(c - q >= 0 && c - q < c && n - q >= c + 1 && n - q <= n - 1);
                llong val_nu, val_de;
                tie(val_nu, val_de) = calc({c}, {make_pair(c - q, c), make_pair(n - q, n)}, X[c], 1);
                llong val_p_nu, val_p_de;
                tie(val_p_nu, val_p_de) = calc({c}, {make_pair(c - q + 1, c), make_pair(n - q + 1, n)}, X[c], 1); 
                if (val_nu * val_p_de > val_de * val_p_nu)
                    l = q;
                else
                    r = q;
            }
            relax({c}, {make_pair(c - l, c), make_pair(n - l, n)}, X[c], 1);
        }
    }
    // even
    {
        for (int c = 0; c < n - 1; c++) {
            int l = 0, r = min(c, n - c - 2) + 1;
            while (r - l > 1) {
                int q = (l + r) / 2;
                assert(c - q >= 0 && c - q < c && n - q >= c + 2 && n - q <= n - 1);
                llong val_nu, val_de;
                tie(val_nu, val_de) = calc({c}, {make_pair(c - q, c), make_pair(n - q, n)}, X[c] + X[c + 1], 2);
                llong val_p_nu, val_p_de;
                tie(val_p_nu, val_p_de) = calc({c}, {make_pair(c - q + 1, c), make_pair(n - q + 1, n)}, X[c] + X[c + 1], 2);  
                if (val_nu * val_p_de > val_de * val_p_nu)
                    l = q;
                else
                    r = q;
            }
            relax({c, c + 1}, {make_pair(c - l, c), make_pair(n - l, n)}, X[c] + X[c + 1], 2);
        }
    }
    assert(best_de != -1);

    vector<int> ans;
    for (int i : best_sing)
        ans.push_back(i);
    for (pair<int, int> s : best_seg)
        for (int i = s.first; i < s.second; i++)
            ans.push_back(i);
    sort(ans.begin(), ans.end());
    assert(unique(ans.begin(), ans.end()) - ans.begin() == ans.size());
    printf("%d\n", (int)ans.size());
    llong sum_nu = 0, sum_de = ans.size();
    for (int i = 0; i < ans.size(); i++) {
        printf("%d%c", X[ans[i]], " \n"[i + 1 == ans.size()]);
        sum_nu += X[ans[i]];
    }
    llong med_nu = (ans.size() % 2 == 1) ? X[ans[ans.size() / 2]] : (X[ans[ans.size() / 2]] + X[ans[(int)ans.size() / 2 - 1]]);
    llong med_de = (ans.size() % 2 == 1) ? 1 : 2;
    llong res_nu = sum_nu * med_de - med_nu * sum_de, res_de = med_de * sum_de;
    assert(res_nu * best_de == best_nu * res_de);
    //printf("%.10lf\n", res_nu * 1.0 / res_de);
}