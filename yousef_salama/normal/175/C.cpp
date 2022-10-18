#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
using namespace std;
long long n, t, p[105];
pair <int, int> fi[105];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> fi[i].second >> fi[i].first;
    cin >> t;
    p[0] = 0;
    for(int i = 1; i <= t; i++)
        cin >> p[i];
    sort(fi, fi + n);
    long long des = 0, score = 0;
    for(int i = 0; i < n; i++){
        long long k, rem = fi[i].second;
        for(int j = 0; j <= t; j++)
            if(des >= p[j])k = j;
        while(k < t && rem > 0){
            if(rem < p[k + 1] - des)break;
            score += (p[k + 1] - des) * (k + 1) * (fi[i].first);
            rem -= p[k + 1] - des;
            des = p[k + 1];
            k++;
        }
        score += rem * fi[i].first * (k + 1);
        des += rem;
    }
    cout << score << endl;
    return 0;
}