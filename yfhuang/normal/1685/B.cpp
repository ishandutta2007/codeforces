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

int a, b, c, d;

string s;

vector<int> AB, BA;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        cin >> a >> b >> c >> d;
        cin >> s;
        int n = s.length();
        int A = 0, B = 0;
        AB.clear();
        BA.clear();
        for(int i = 0;i < n;i++){
            if(s[i] == 'A'){
                A++; 
            }else
                B++;
        }
        if(A != a + c + d or B != b + c + d){
            cout << "NO" << endl;
        }else{
            int fre = 0;
            for(int i = 0, j = 0;i < n;i = j + 1, j = i){
                while(j + 1 < n and s[j + 1] != s[j]){
                    j++;
                } 
                int len = j - i + 1;
                if(len & 1){
                    fre += len / 2;
                }else{
                    if(s[i] == 'A'){
                        AB.push_back(len / 2);
                    }else{
                        BA.push_back(len / 2);
                    }
                }
            }
            bool flag = true;
            sort(AB.begin(), AB.end());
            sort(BA.begin(), BA.end());
            int nAB = AB.size();
            int nBA = BA.size();
            for(int i = 0;i < AB.size();i++){
                if(c >= AB[i]){
                    c -= AB[i];
                    nAB--;
                }else{
                    fre += AB[i] - 1;
                }
            } 
            for(int i = 0;i < BA.size();i++){
                if(d >= BA[i]){
                    d -= BA[i];
                    nBA--;
                }else{
                    fre += BA[i] - 1;
                }
            }
            if((a < nAB + nBA) or (b < nAB + nBA) or (c + d > fre)){
                cout << "NO" << endl;
            }else{
                cout << "YES" << endl;
            }
        } 
    }
    return 0;
}