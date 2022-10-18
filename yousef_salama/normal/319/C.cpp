#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string.h>
#include <assert.h>
#include <numeric>
using namespace std;

struct lm7_el_bsr{
    vector < pair <long long, long long> > lines;
    vector < pair <long long, long long> > L;
    vector <double> endpoints;
    
    bool bad(pair <long long, long long> l1, pair <long long, long long> l2, pair <long long, long long> l3){
        return 1.0 * (l3.second - l1.second) / (l1.first - l3.first) < (l2.second - l1.second) / (l1.first - l2.first);
    }
    void add(long long M, long long B){
        endpoints.pop_back();
    
        L.push_back(make_pair(M, B));
        if(L.size() > 1)endpoints.push_back(1.0 * (L[L.size() - 1].second - L[L.size() - 2].second)
            / (L[L.size() - 2].first - L[L.size() - 1].first));
            
        while((L.size() >= 3) && bad(L[L.size() - 3], L[L.size() - 2], L[L.size() - 1])){
            L.erase(L.end() - 2);
            
            endpoints.pop_back();
            endpoints.pop_back();
            
            if(L.size() > 1)
                endpoints.push_back(1.0 * (L[L.size() - 1].second - L[L.size() - 2].second) 
                    / (L[L.size() - 2].first - L[L.size() - 1].first));
        }
        
        endpoints.push_back(1LL << 60);
    }
    double query(double x){
        int line = lower_bound(endpoints.begin(), endpoints.end(), x) - endpoints.begin();
        return L[line].first * x + L[line].second;
    }
} H;

int n, a[100005], b[100005];
long long dp[100005];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);

    H.endpoints.push_back(1LL << 60);

    dp[0] = b[0];
    
    H.add(b[0], 0);
    for (int i = 1; i < n; i++) {
        dp[i] = H.query(a[i]);
        H.add(b[i], dp[i]);
    }
    
    printf("%I64d\n", dp[n - 1]);
    
    return 0;
}