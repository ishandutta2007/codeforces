#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    vector <long long> p(n);
    for(int i = 0; i < n; i++)
        scanf("%lld", &p[i]);

    vector <long long> x(m + 2);
    
    x[0] = -1LL << 50;
    for(int i = 1; i <= m; i++){
        scanf("%lld", &x[i]);
        x[i] *= 2;
    }
    x[m + 1] = 1LL << 50;
    m += 2;

    sort(x.begin(), x.end());

    vector < pair <long long, long long> > evs;
    for(int i = 0, j = 0; i < n; i++){
        while(x[j + 1] <= i * 200)j++;

        long long d = min(200 * i - x[j], x[j + 1] - 200 * i);
        
        if(d > 0){
            evs.push_back(make_pair(200 * i - d + 1, p[i]));
            evs.push_back(make_pair(200 * i + d, -p[i]));
        }
    }
    sort(evs.begin(), evs.end());

    long long res = 0, cur = 0;
    for(int i = 0; i < (int)evs.size(); ){
        int j = i;
        while(j < (int)evs.size() && evs[i].first == evs[j].first){
            cur += evs[j].second;
            j++;
        }

        res = max(res, cur);
        i = j;
    }
    printf("%lld\n", res);

    return 0;
}