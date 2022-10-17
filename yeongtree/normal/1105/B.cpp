#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n,k; cin >> n >> k;
    string s; cin >> s;

    char a = 0;
    int scc = 0;
    int level[26]={};
    for(int i = 0; i < n; ++i)
    {
        if(a != s[i]) {a = s[i]; scc =1;}
        else ++scc;
        if(scc == k) {++level[a-97]; a = 0;}
    }

    int ans = 0;
    for(int i = 0; i < 26; ++i)
        if(ans < level[i]) ans = level[i];

    cout << ans;
    return 0;
}