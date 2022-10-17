#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        int A[n];
        for(int &i : A)
        {
            cin >> i;
            for(int j = 2; j * j <= i; ++j) while(i % (j * j) == 0) i /= j * j;
        }
        sort(A, A + n);
        int pt = 0;
        int s = 0;
        while(pt < n && A[pt] == 1) ++s, ++pt;
        vector<int> V;
        int len = 0, pr = A[pt];
        for(int i = pt; i < n; ++i)
        {
            if(A[i] != pr)
            {
                V.push_back(len);
                pr = A[i];
                len = 1;
            }
            else ++len;
        }
        if(len) V.push_back(len);

//        for(auto i : V) cout << i << ' '; cout << endl;
        int ans0 = (V.size() ? max(s, *max_element(V.begin(), V.end())) : s);
        for(auto &i : V) if(i % 2 == 0) s += i, i = 0;
        int ans1 = (V.size() ? max(s, *max_element(V.begin(), V.end())) : s);


        int Q; cin >> Q;
        while(Q--)
        {
            long long p; cin >> p;
            cout << (p ? ans1 : ans0) << '\n';
        }
    }
}