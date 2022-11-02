#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int T;

int check(string s){
    int s1 = 0, s2 = 0, l1 = 5, l2 = 5;
    for(int i = 0;i < 10;i++){
        if(i & 1){
            if(s[i] == '1')
                s1++;
            l1--;
        }else{
            if(s[i] == '1')
                s2++;
            l2--;
        }
        if(s1 + l1 < s2 or s1 > s2 + l2){
            return i + 1;
        }
    }
    return 10;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        int ans = 10;
        string t = s;
        for(int i = 0;i < 10;i++){
            if(t[i] == '?'){
                if(i & 1)
                    t[i] = '1';
                else
                    t[i] = '0';
            }
        }
        ans = min(ans, check(t)); 
        t = s;
        for(int i = 0;i < 10;i++){
            if(t[i] == '?'){
                if(i & 1)
                    t[i] = '0';
                else
                    t[i] = '1';
            }
        }
        ans = min(ans, check(t));
        cout << ans << endl;
    }
    return 0;
}