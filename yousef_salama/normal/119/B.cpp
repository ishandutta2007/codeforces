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
#include <cstring>
#include <sstream>
#include <string.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int q, card[n / k], curCard = 0;
    cin >> q;
    map <int, int> mp;
    int cards[k][n / k];
    for(int i = 0; i < q; i++){
        for(int j = 0; j < n / k; j++)
            cin >> card[j];
        if(!mp.count(card[0] - 1)){
            for(int j = 0; j < n / k; j++){
                mp[card[j] - 1] = curCard;
                cards[curCard][j] = card[j] - 1;
            }
            curCard++;
        }
    }
    vector <int> temp;
    for(int i = 0; i < n; i++)
        if(!mp.count(i))
            temp.push_back(a[i]);
    double bad = 1000000.0, good = -1000000.0;
    for(int i = 0; i < curCard; i++){
        double cur = 0.0;
        for(int j = 0; j < n / k; j++)
            cur += a[cards[i][j]];
        cur /= (n / k);
        bad = min(cur, bad);
        good = max(cur, good);
    }
    sort(temp.begin(), temp.end());
    double best = 0.0, worst = 0.0;
    if(temp.size() >= (n / k + n % k)){
        for(int i = 0; i < n / k; i++)
            worst += temp[i];
        int cnt = 0;
        for(int i = temp.size() - 1; cnt < n / k; i--, cnt++)
            best += temp[i];
        best /= (n / k);
        worst /= (n / k);
        bad = min(worst, bad);
        good = max(best, good);
    }
    printf("%.10f %.10f\n", bad, good);
    return 0;
}