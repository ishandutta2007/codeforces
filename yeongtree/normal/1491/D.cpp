#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define piii pair<int, pii>
#define plll pair<long long, pll>
#define ff first
#define ss second
#define tiii tuple<int, int, int>
#define tiiii tuple<int, int, int, int>
#define tlll tuple<long long, long long, long long>
#define tllll tuple<long long, long long, long long, long long>
#define DEBUG

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int x, y; cin >> x >> y;
        vector<int> A, B;
        for(int i = 29; i >= 0; --i) if(x >> i & 1) A.push_back(i);
        for(int i = 29; i >= 0; --i) if(y >> i & 1) B.push_back(i);
        if(A.size() < B.size()) cout << "NO\n";
        else
        {
            bool flag = true, flag2 = true;
            int k = (int)A.size() - (int)B.size();
            for(int i = 0, j = 0; i < (int)B.size(); ++i, ++j)
            {
                if(B[i] < A[j]) flag = false;
                if(B[i] > A[j] && flag2)
                {
                    j += k;
                    flag2 = false;
                }
            }
            if(!flag || (k && flag2)) cout << "NO\n";
            else cout << "YES\n";
        }
    }
}