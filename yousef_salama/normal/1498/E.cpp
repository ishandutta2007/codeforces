#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    vector <int> k(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &k[i]);

    vector < pair <int, pair <int, int> > > v;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)if(i != j && k[i] <= k[j]){
        v.push_back(make_pair(k[j] - k[i], make_pair(i, j)));
    }
    sort(v.rbegin(), v.rend());

    for(auto z : v){
        printf("? %d %d\n", z.second.second + 1, z.second.first + 1);
        fflush(stdout);

        char s[4];
        scanf("%s", s);
        if(s[0] == 'Y'){
            printf("! %d %d\n", z.second.first + 1, z.second.second + 1);
            return 0;
        }
    }

    printf("! 0 0\n");

    return 0;
}