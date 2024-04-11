// https://codeforces.com/problemset/problem/1455/E

#include <bits/stdc++.h>

using namespace std;

bool lssx[4], lssy[4];

long long solve_square(vector<pair<int, int> > &points, vector<pair<int, int> > &square){
    pair<pair<int, int>, pair<int, long long> > dff;
    pair<int, int> init{-2000000000, 2000000000};
    pair<int, int> a = init, b = init, ax = init, bx = init; // low, high
    // constraints
    for (int i=0;i<4;++i){
        int dx = 1, dy = 1;
        if (lssx[i]){
            // point_x < square vertex_x
            dx = -1;
            if (square[i].first){
                // a + x
                ax.first = max(ax.first, points[i].first);
            } else {
                // a
                a.first = max(a.first, points[i].first);
            }
        } else {
            dx = 1;
            if (square[i].first){
                // a + x
                ax.second = min(ax.second, points[i].first);
            } else {
                // a
                a.second = min(a.second, points[i].first);
            }
        }

        if (lssy[i]){
            // point_y < square vertex_y
            dy = -1;
            if (square[i].second){
                // b + x
                bx.first = max(bx.first, points[i].second);
            } else {
                // b
                b.first = max(b.first, points[i].second);
            }
        } else {
            dy = 1;
            if (square[i].second){
                // b + x
                bx.second = min(bx.second, points[i].second);
            } else {
                // b
                b.second = min(b.second, points[i].second);
            }
        }

        dff.second.second += dx * points[i].first;
        dff.second.second += dy * points[i].second;
        dff.first.first -= dx; // a
        dff.first.second -= dy; // b
        dff.second.first -= dx * square[i].first; // a + x
        dff.second.first -= dy * square[i].second; // b + x
    }

    // l <= a <= h
    // l <= a + x <= h
    // l <= b <= h
    // l <= b + x <= h

    // at least two are equal
    long long ans = 1000000000000LL;
    long long aa;
    long long xx;
    long long bb;
    auto check = [&](){
        if (aa < a.first || aa > a.second) return;
        if (bb < b.first || bb > b.second) return;
        if (aa + xx < ax.first || aa + xx > ax.second) return;
        if (bb + xx < bx.first || bb + xx > bx.second) return;
        // cout << aa << " " << bb << " " << xx << " " << ans << endl;
        ans = min(ans, dff.second.second + dff.first.first * aa + dff.first.second * bb + dff.second.first * xx);
        // cout << ans << endl;
    };
    // a = l/h and a+x = l/h
    auto cax = [&](){
        if (dff.first.second < 0) {
            bb = min(b.second + 0ll, bx.second - xx);
            check();
        } else {
            bb = max(b.first+0ll, bx.first - xx);
            check();
        }
    };
    aa = a.first;
    xx = ax.first - aa;
    cax();
    xx = ax.second - aa;
    cax();
    aa = a.second;
    xx = ax.first - aa;
    cax();
    xx = ax.second - aa;
    cax();
    // a = l/h and b = l/h
    auto cab = [&](){
        if (dff.second.first < 0){
            xx = min(ax.second - aa, bx.second - bb);
            check();
        } else {
            xx = max(ax.first - aa, bx.first - bb);
            check();
        }
    };
    aa = a.first;
    bb = b.first;
    cab();
    aa = a.second;
    cab();
    bb = b.second;
    cab();
    aa = a.first;
    cab();
    // a = l/h and b+x = l/h
    // TODO
    // a+x = l/h and b = l/h
    // TODO
    // a+x = l/h and b+x = l/h
    // TODO
    // b = l/h and b+x = l/h
    auto cbx = [&](){
        if (dff.first.first < 0){
            aa = min(a.second + 0ll, ax.second - xx);
            check();
        } else {
            aa = max(a.first + 0ll, ax.first - xx);
            check();
        }
    };
    bb = b.first;
    xx = bx.first - bb;
    cbx();
    xx = bx.second - bb;
    cbx();
    bb = b.second;
    xx = bx.first - bb;
    cbx();
    xx = bx.second - bb;
    cbx();

    return ans;
}

void solve(){
    vector<pair<int, int> > points(4);
    for (int i=0;i<4;++i) cin >> points[i].first >> points[i].second;
    sort(points.begin(), points.end());
    vector<pair<int, int> > square{
        {0, 0}, // (a, b)
        {0, 1}, // (a, b + x)
        {1, 0}, // (a + x, b)
        {1, 1}  // (a + x, b + x)
    };

    long long ans = 1000000000000LL;

    sort(square.begin(), square.end());
    while (std::next_permutation(square.begin(), square.end())){
        for (int msk1=0;msk1<16;++msk1){
            for (int i=0;i<4;++i) lssx[i] = msk1 & (1<<i);
            if (lssx[0] + lssx[1] + lssx[2] + lssx[3] > 1) continue;
            for (int msk2=0;msk2<16;++msk2){
                for (int i=0;i<4;++i) lssy[i] = msk2 & (1<<i);
                if (lssy[0] + lssy[1] + lssy[2] + lssy[3] > 1) continue;
                ans = min(ans, solve_square(points, square));
            }
        }
        // break;
    }
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while (t-->0) solve();
    return 0;
}