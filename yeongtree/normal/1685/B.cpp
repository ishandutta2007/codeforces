#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#define pii pair<int, int>
#define piii pair<int, pii>
#define pll pair<long long, long long>
#define plll pair<long long, pll>
#define tiii tuple<int, int, int>
#define tiiii tuple<int, int, int, int>
#define ff first
#define ss second
#define ee ss.ff
#define rr ss.ss
#define DEBUG
const int INF = (int)1e9 + 7;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int a, b, c, d; cin >> a >> b >> c >> d;
        string s; cin >> s;

        int x = 0, y = 0;
        for(auto t : s) (t == 'A' ? x : y)++;
        if(x != a + c + d || y != b + c + d) { cout << "NO\n"; continue; }

        vector<int> C, D;
        int e = 0; x = 0; y = 0;
        int len = 1; char pr = s[0];
        for(int i = 1; i < (int)s.size(); ++i)
        {
            if(s[i] == pr)
            {
                if(len)
                {
                    if(len & 1) e += len / 2;
                    else if(s[i] == 'B') C.push_back(len / 2), e += len / 2, x += len / 2;
                    else D.push_back(len / 2), e += len / 2, y += len / 2;
                }
                len = 1;
            }
            else ++len, pr = s[i];
        }
        if(len)
        {
            if(len & 1) e += len / 2;
            else if(pr == 'B') C.push_back(len / 2), e += len / 2, x += len / 2;
            else D.push_back(len / 2), e += len / 2, y += len / 2;
        }

        if(e < c + d) { cout << "NO\n"; continue; }
        sort(C.begin(), C.end());
        sort(D.begin(), D.end());
        while(e > c + d && (C.size() || D.size()))
        {
            if(D.empty() || x > c) x -= C.back(), C.pop_back();
            else y -= D.back(), D.pop_back();
            --e;
        }

        if(x > c || y > d) { cout << "NO\n"; continue; }
        cout << "YES\n";
    }
}