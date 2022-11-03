#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

string ans[N];

int main() {
    int n, l, k;
    cin >> n >> l >> k;

    string s;
    cin >> s;

    sort(s.begin(), s.end());

    int len = n * l;    
    int last = len-1;

    for(int i = k+1; i <= n; i++) {
        string wp = "";
        for(int j = 0; j < l; j++) {
            wp += s[last--];
        }
        ans[i] = wp;
    }

    int front = 0;
    int tadi = 1;
    for(int j = 0; j < l; j++){
        int dari = tadi;
        if(j > 0){
            for(int i = k-1; i >= tadi; i--) {
                if (ans[i][j-1] != ans[k][j-1]) {
                    dari = i + 1;
                    break;
                }
            }
        }
        tadi = dari;
        for(int i = dari; i <= k; i++){
            ans[i] += s[front++];
        }
    }
    
    for(int i = 1; i <= k; i++) {
        while(ans[i].length() < l) {
            ans[i] += s[front++];
        }
    }

    sort(ans + 1, ans + n + 1);
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
}