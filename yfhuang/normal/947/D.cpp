#include <bits/stdc++.h>
using namespace std;

string S, T;

int Q, n, m;
const int maxn = 1e5 + 5;
int pres[maxn], pret[maxn];
int psa[maxn], pta[maxn];
int as[maxn], at[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> S;
    cin >> T;
    n = S.length();
    m = T.length();
    pres[0] = 0;
    as[0] = 0;
    for(int i = 1;i <= n;i++){
        pres[i] = pres[i - 1] + (S[i - 1] == 'B') + (S[i - 1] == 'C');
        psa[i] = psa[i - 1] + (S[i - 1] == 'A');
        if(S[i - 1] == 'A'){
            as[i] = as[i - 1] + 1;
        }else{
            as[i] = 0;
        }
    }
    pret[0] = 0;
    at[0] = 0;
    for(int i = 1;i <= m;i++){
        pret[i] = pret[i - 1] + (T[i - 1] == 'B') + (T[i - 1] == 'C');
        pta[i] = pta[i - 1] + (T[i - 1] == 'A');
        if(T[i - 1] == 'A'){
            at[i] = at[i - 1] + 1;
        }else{
            at[i] = 0;
        }
    }
    cin >> Q;
    string ans;
    for(int i = 1;i <= Q;i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int num1 = pres[b] - pres[a - 1];
        int num2 = pret[d] - pret[c - 1];
        int len1 = min(as[b], b - a + 1);
        int len2 = min(at[d], d - c + 1);
        if(num1 > num2){
            ans.push_back('0');
            continue;
        }else if(num1 == num2){
            if(len1 > len2){
                int delta = (len1 - len2) % 3;
                len1 = len2 + delta;
            }
            if(len1 != len2){
                ans.push_back('0');
                continue;
            }else{
                ans.push_back('1');
                continue;
            }
        }else{
            if(len1 < len2){
                ans.push_back('0');
                continue;
            }else if(len1 == len2){
                if(num1 == 0 and num2 > 0){
                    ans.push_back('0');
                    continue;
                }
            }else{
                num1 += 2;
            } 
            if((num1 > num2) or (num2 - num1) & 1){
                ans.push_back('0');
            }else{
                ans.push_back('1');
            }
        }
    }
    cout << ans << endl;
    return 0;
}