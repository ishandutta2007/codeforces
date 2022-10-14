#include <bits/stdc++.h>

int N, boundl, boundr;
int A[110000];
std::vector <int> need, add;
std::vector <std::pair <int, int>> ans;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d", &A[i]);
    boundl = 0; boundr = N - 1;
    for (int i = 0; i < N; ++i) {
        if (A[i] >= 1) {
            if (A[i] == 1) {
                if (!need.empty()) {
                    ans.push_back(std::make_pair(need.back(), i));
                    need.pop_back();
                } else {
                    if (!add.empty()) {
                        ans.push_back(std::make_pair(add.back(), i));
                        add.pop_back();
                    }
                    if (boundl > boundr) {
                        printf("-1\n");
                        return 0;
                    }
                    ans.push_back(std::make_pair(boundl++, i));
                }
            } else if (A[i] == 2) {
                if (!add.empty()) {
                    ans.push_back(std::make_pair(add.back(), i));
                    add.pop_back();
                }
                if (boundl > boundr) {
                    printf("-1\n");
                    return 0;
                }
                ans.push_back(std::make_pair(boundr, i));
                need.push_back(boundr--);
            } else if (A[i] == 3) {
                if (!add.empty()) {
                    ans.push_back(std::make_pair(add.back(), i));
                    add.pop_back();
                }
                if (boundl > boundr) {
                    printf("-1\n");
                    return 0;
                }
                ans.push_back(std::make_pair(boundl, i));
                add.push_back(boundl++);
            }
        }
    }
    if (!need.empty() || !add.empty()) {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", (int) ans.size());
    for (auto &x: ans) {
        printf("%d %d\n", x.first + 1, x.second + 1);
    }
}