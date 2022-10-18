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
using namespace std;
long long p[100005], pref[3][100005], suff[3][100005];
bool flag[3];
string s[3];
vector <int> pi, z;
int main(){
    cin >> s[0] >> s[1] >> s[2];
    for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
        if(i != j && !flag[j]){
            string B = s[i] + "@" + s[j];
            int P = B.size();

            z.clear();
            z.push_back(0);
            for(int ind = 1, L = 0, R = 0; ind < P; ind++){
                z.push_back(0);
                if(ind <= R)
                    z[ind] = min(R - ind + 1, z[ind - L]);
                while(ind + z[ind] < P && B[ind + z[ind]] == B[z[ind]])
                    z[ind]++;
                if(ind + z[ind] - 1 > R)
                    L = ind, R = ind + z[ind] - 1;
            }
            for(int k = s[i].size() + 1; k < B.size(); k++)
                if(z[k] == s[i].size())flag[i] = true;
        }

    p[0] = 1;
    for(int i = 1; i <= 100004; i++)
        p[i] = p[i - 1] * 3157;
    for(int j = 0; j < 3; j++){
        pref[j][0] = (s[j][0] - 'a') + 1;
        for(int i = 1; i < s[j].size(); i++)
            pref[j][i] = pref[j][i - 1] + ((s[j][i] - 'a') + 1) * p[i];
        suff[j][s[j].size() - 1] = (s[j][s[j].size() - 1] - 'a') + 1;
        for(int i = (int)(s[j].size()) - 2; i >= 0; i--)
            suff[j][i] = suff[j][i + 1] * 3157 + ((s[j][i] - 'a') + 1);
    }
    int sum = 0, ans = 0;
    for(int i = 0; i < 3; i++)
        if(!flag[i]){
            pi.push_back(i);
            sum += s[i].size();
            ans += s[i].size();
        }
    do{
        int a = 0;
        for(int i = 1; i < pi.size(); i++){
            int m = 0;
            for(int j = 1; j <= min(s[pi[i]].size(), s[pi[i - 1]].size()); j++){
                if(suff[pi[i - 1]][s[pi[i - 1]].size() - j] == pref[pi[i]][j - 1])m = max(m, j);
            }
            a += m;
        }
        ans = min(ans, sum - a);
    }while(next_permutation(pi.begin(), pi.end()));
    printf("%d\n", ans);
    return 0;
}