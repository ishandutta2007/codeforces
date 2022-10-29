#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
char str[N] , s[N];

bool f[N];
vector<string> v;

int main() {
    scanf("%d%s" , &n , str);
    //n = 200000;
    //for (int i = 0 ; i < n ; ++ i) str[i] = rand() % 10 + '0';
    srand(time(0));
    while (1) {
        strcpy(s , str);
        v.clear();
        for (int k = 0 ; k < 3 ; ++ k) {
            int sum = 0;
            n = strlen(s);
            string cur;
            for (int i = 0 , x = 0; i < n ; ++ i) {
                x = x * 10 + (s[i] - '0');
                cur += s[i];
                if (rand() % 233 > 0 || i + 1 == n) {
                    sum += x;
                    x = 0;
                    if (i + 1 < n) cur += '+';
                }
            }
            v.emplace_back(cur);
            //cout << sum << endl;
            sprintf(s , "%d" , sum);
        }
        if (strlen(s) == 1) {
            for (auto it : v) {
                puts(it.c_str());
            }
            break;
        }
    }
}