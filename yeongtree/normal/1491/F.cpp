#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;

        bool flag = true;
        int pt = -1;

        vector<int> A;

        for(int i = 1; i < n; ++i)
        {
            cout << "? 1 " << (flag ? i : pt) << endl;
            cout << i + 1 << endl;
            for(int j = 0; j < (flag ? i : pt); ++j) cout << j + 1 << ' '; cout << endl;
            cout.flush();

            int x; cin >> x;
            if(x != 0)
            {
                A.push_back(i);
                if(flag)
                {
                    flag = false;
                    pt = i;
                }
            }
        }

        int s = 0, e = pt;
        while(s + 1 < e)
        {
            int mid = s + e >> 1;

            cout << "? 1 " << mid - s << endl;
            cout << A[0] + 1 << endl;
            for(int i = s; i < mid; ++i) cout << i + 1 << endl;
            cout.flush();

            int x; cin >> x;
            if(x != 0) e = mid;
            else s = mid;
        }

        bool chc[n]{};
        for(auto i : A) chc[i] = true;
        chc[s] = true;

        int cnt = 0;
        for(int i = 0; i < n; ++i) if(!chc[i]) ++cnt;

        cout << "! " << cnt << ' ';
        for(int i = 0; i < n; ++i) if(!chc[i]) cout << i + 1 << ' '; cout << endl;
        cout.flush();
    }
}