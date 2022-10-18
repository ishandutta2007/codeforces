#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    string s;
    cin >> s;

    vector <int> res(n);

    int L = 0, R = n - 1;
    for(int i = n - 2; i >= 0; i--){
        if(s[i] == s[i + 1]){
            res[i + 1] = L;
            L++;
        }else{
            res[i + 1] = R;
            R--;
        }
    }
    res[0] = L;

    for(int i = 0; i < n; i++){
        printf("%d", a[res[i]]);
        
        if(((n - 1 - res[i]) % 2 != 0) ^ (s[n - 1] != 'L')){
            printf(" R\n");
        }else{
            printf(" L\n");
        }
    }

    return 0;
}