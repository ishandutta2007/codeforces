#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    auto query = [&](int u){
        printf("? %d\n", u + 1);
        fflush(stdout);

        vector <int> v(n);
        for(int i = 0; i < n; i++)scanf("%d", &v[i]);
        return v;
    };

    vector <int> v = query(0);

    int cnt[] = {0, 0};
    for(int i = 1; i < n; i++)
        cnt[v[i] & 1]++;

    set < pair <int, int> > edges;
    for(int i = 1; i < n; i++)
        if(v[i] == 1)edges.insert(make_pair(0, i));
    
    for(int i = 1; i < n; i++)if((v[i] & 1) == (cnt[1] < cnt[0])){
        vector <int> vi = query(i);
        for(int j = 0; j < n; j++)
            if(vi[j] == 1)edges.insert(make_pair(min(i, j), max(i, j)));
    }

    printf("!\n");
    for(auto p : edges)
        printf("%d %d\n", p.first + 1, p.second + 1);

    return 0;
}