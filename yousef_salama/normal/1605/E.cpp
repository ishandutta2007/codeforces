#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    vector <long long> a(n + 1, 0);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);

    vector <long long> b(n + 1, 0);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &b[i]);
    b[1] = 0;

    vector <long long> v = a;
    vector <long long> e(n + 1, 0);
    long long f0 = 0, slope = 0;
    vector <long long> evs;

    for(int i = 1; i <= n; i++){
        long long d = b[i] - v[i];
        for(int j = i; j <= n; j += i)
            v[j] += d;

        f0 += llabs(d);

        int target = (i == 1);
        if(e[i] != target){
            long long de = target - e[i];
            for(int j = i; j <= n; j += i)
                e[j] += de;

            if((de == -1 && d <= 0) || (de == 1 && d >= 0)){
                slope += 1;
            }else{
                slope += -1;
                evs.push_back(llabs(d));
            }
        }
    }
    sort(evs.begin(), evs.end());

    int q;
    scanf("%d", &q);

    vector < pair <int, int> > queries;
    for(int i = 0; i < q; i++){
        int x;
        scanf("%d", &x);
        queries.push_back(make_pair(x, i));
    }
    sort(queries.begin(), queries.end());

    vector <long long> res(q, -1);
    int x = 0, j = 0;
    for(int i = 0; i < q; i++){
        while(x < queries[i].first){
            while(j < (int)evs.size() && evs[j] <= x){
                slope += 2;
                j++;
            }

            f0 += slope;
            x++;
        }

        res[queries[i].second] = f0;
    }

    for(int i = 0; i < q; i++)
        printf("%lld\n", res[i]);

    return 0;
}