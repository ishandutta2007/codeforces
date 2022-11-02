#include <iostream>

using namespace std;

string s[12] = {
    "aabbcc",
    "aaccbb",
    "bbaacc",
    "bbccaa",
    "ccaabb",
    "ccbbaa",
    "abcabc",
    "acbacb",
    "bacbac",
    "bcabca",
    "cabcab",
    "cbacba",
};

int main(){
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    cout << "YES" << endl;
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < s[i].size()-1; j++){
            if(s1[0] == s[i][j] && s1[1] == s[i][j+1]) break;
            if(s2[0] == s[i][j] && s2[1] == s[i][j+1]) break;
            if(j == s[i].size()-2){
                string ans;
                if(i < 6){
                    for(int k = 0; k < n; k++) ans += s[i][0];
                    for(int k = 0; k < n; k++) ans += s[i][2];
                    for(int k = 0; k < n; k++) ans += s[i][4];
                }else{
                    string s3;
                    for(int k = 0; k < 3; k++) s3 += s[i][k];
                    for(int k = 0; k < n; k++) ans += s3;
                }
                cout << ans << endl;
                return 0;
            }
        }
    }
}