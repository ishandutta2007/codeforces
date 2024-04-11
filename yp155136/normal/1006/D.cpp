#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    string a,b;
    cin >>a >> b;
    string ta = a,tb = b;
    reverse(ta.begin(),ta.end());
    reverse(tb.begin(),tb.end());
    int ans=0;
    for (int i=0;n/2>i;i++)
    {
        if (b[i] == tb[i])
        {
            if (a[i] != ta[i])  ++ans;
            continue;
        }
        map<char,int> mp;
        mp[ b[i] ]++;
        mp[ tb[i] ]++;
        if (mp[ a[i] ] == 0) ans++;
        else mp[ a[i] ]--;
        if (mp[ ta[i] ] == 0) ans++;
        else mp[ ta[i] ]--;
    }
    if (n%2 ==1 && a[n/2] != b[n/2]) ++ans;
    cout << ans << endl;
}