#include <bits/stdc++.h>

int N;
int res[2100][2100];
bool is_res[2100];
int line[2100];
int f[2100];
std::vector <std::pair<int, int>> vec;

void query(int x) {
    if (is_res[x]) return;
    is_res[x] = 1;
    printf("? %d\n", x);
    fflush(stdout);
    for (int i = 1; i <= N; ++i) scanf("%d", &res[x][i]);
    return;
}

void build_tree(int n2) {
    if (res[1][n2] == 1) {
        f[n2] = 1;
        return;
    }
    query(n2);
    for (int i = 1; i <= N; ++i) {
        if (res[1][n2] == res[1][i] + res[n2][i])
            line[res[1][i]] = i;
    }
    for (int i = 1; i <= res[1][n2]; ++i)
        f[line[i]] = line[i - 1];
    for (int i = 1; i <= N; ++i) {
        if (res[1][n2] + 2 == res[1][i] + res[n2][i])
            f[i] = line[res[1][i] - 1];
    }
}

int main() {
    scanf("%d", &N);
    query(1);
    for (int i = 2; i <= N; ++i) vec.push_back(std::make_pair(-res[1][i], i));
    std::sort(vec.begin(), vec.end());
    for (auto &it: vec) if (f[it.second] == 0) {
        build_tree(it.second);
    }
    printf("!\n");
    for (int i = 2; i <= N; ++i) printf("%d %d\n", i, f[i]);
    fflush(stdout);   
}