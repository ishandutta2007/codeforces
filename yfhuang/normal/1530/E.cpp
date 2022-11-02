#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int cnt[30];
string s;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        memset(cnt, 0, sizeof(cnt));
        cin >> s;
        int n = s.length();
        int Max = 0;
        int nonzero = 0;
        int Min = 1e9;
        for(int i = 0;i < n;i++){
            cnt[s[i] - 'a']++;
        }
        for(int i = 0;i < 26;i++){
            Max = max(Max, cnt[i]);
            nonzero += (cnt[i] != 0);
            if(cnt[i] > 0){
                Min = min(cnt[i], Min);
            }
        }
        if(Min == 1){
            for(int i = 0;i < 26;i++){
                if(cnt[i] == 1){
                    string s = "";
                    s.push_back(i + 'a');
                    cnt[i]--;
                    for(int j = 0;j < 26;j++){
                        for(int k = 1;k <= cnt[j];k++){
                            s.push_back(j + 'a');
                        }
                    }
                    cout << s << endl;
                    break;
                }
            }
            continue;
        }
        if(Max == 1){
            sort(s.begin(), s.end());
            cout << s << endl;
        }else{
            int Minid;
            for(int i = 0;i < 26;i++){
                if(cnt[i] != 0){
                    Minid = i;
                    break;
                }
            }
            if(nonzero == 1){
                cout << s << endl;
            }else{
                if(cnt[Minid] == 1){
                    sort(s.begin(), s.end());
                    cout << s << endl;
                }else{
                    int other = n - cnt[Minid];
                    string ss = "";
                    if(cnt[Minid] - 2 <= other){
                        int m = cnt[Minid] - 2;
                        ss.push_back(Minid + 'a');
                        ss.push_back(Minid + 'a');
                        for(int i = Minid + 1;i < 26;i++){
                            for(int j = 1;j <= cnt[i];j++){
                                ss.push_back(i + 'a');
                                if(m > 0){
                                    ss.push_back(Minid + 'a');
                                    m--;
                                }
                            }
                        }
                        cout << ss << endl;
                    }else{
                        if(nonzero == 2){
                            ss.push_back(Minid + 'a');
                            int m = cnt[Minid] - 1;
                            for(int i = Minid + 1;i < 26;i++){
                                for(int j = 1;j <= cnt[i];j++){
                                    ss.push_back(i + 'a');
                                }
                            }
                            for(int i = 1;i <= m;i++){
                                ss.push_back(Minid + 'a');
                            }
                            cout << ss << endl;
                        }else{
                            int i2, i3;
                            for(int i = Minid + 1;i < 26;i++){
                                if(cnt[i] > 0){
                                    i2 = i;
                                    break;
                                }
                            }
                            for(int i = i2 + 1;i < 26;i++){
                                if(cnt[i] > 0){
                                    i3 = i;
                                    break;
                                }
                            }
                            ss.push_back(Minid + 'a');
                            ss.push_back(i2 + 'a');
                            for(int i = 1;i < cnt[Minid];i++){
                                ss.push_back(Minid + 'a');
                            }
                            ss.push_back(i3 + 'a');
                            for(int i = Minid + 1;i < 26;i++){
                                for(int j = 1;j <= cnt[i] - (i == i2 or i == i3);j++){
                                    ss.push_back(i + 'a');
                                }
                            }
                            cout << ss << endl;
                        }
                    }
                }
            }
        }
    }
    return 0;
}