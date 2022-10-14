#include <bits/stdc++.h>

int N;
char C[210000];
int V[210000];
std::vector<int> ev;

int main() {
    bool flag = true;
    scanf("%d", &N);
    for (int i = 0; i < 2 * N; ++i) {
        scanf(" %c", &C[i]);
        if (C[i] == '+') {
            ev.push_back(i);
        } else {
            scanf("%d", &V[i]);
            if (!ev.empty()) {
                V[ev.back()] = V[i];
                ev.pop_back();
            } else {
                flag = false;
            }
        }
    }
    if (!flag) {
        puts ("NO");
        return 0;
    }
    std::set<int> ve;
    for (int i = 0; i < 2 * N; ++i) {
        if (C[i] == '+') {
            ve.insert(V[i]);
        } else {
            if (ve.empty() || *ve.begin() != V[i]) {
                flag = false;
                break;
            } else {
                ve.erase(V[i]);
            }
        }
    }
    if (!flag) {
        puts ("NO");
        return 0;
    }
    puts("YES");
    for (int i = 0; i < 2 * N; ++i) {
        if (C[i] == '+') {
            printf("%d%c", V[i], ' ');
        }
    }
}