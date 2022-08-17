#include <iostream>
#include <algorithm>
#include <cassert>
#include <string>
#include <vector>
using namespace std;

vector<int> A, B;

int main()
{
    string S;
    cin >> S;
    A.resize(10);
    for (int i = 0; i < S.size(); i++)
        A[S[i] - '0']++;
    B = A;
    #define mp make_pair
    vector<int> C;
    C = A;
    pair<int, pair<int, int> > ans(-1, mp(-1, -1));
    for (int z = 0; z <= C[0]; z++)
        for (int r = 1; r < 10; r++)
        {
            A = B = C;
            A[0] -= z;
            B[0] -= z;
            if (!A[r] || !B[10 - r])
                continue;
            A[r]--, B[10 - r]--;
            int qans = z + 1;
            for (int i = 0; i < 10; i++)
                qans += min(A[i], B[9 - i]);
            ans = max(ans, mp(qans, mp(r, z)));
        }
    if (ans.first == -1)
    {
        string SS;
        for (int i = 9; i >= 0; i--)
            while (C[i])
                SS.push_back('0' + i), C[i]--;
        cout << SS << endl << SS;
    }
    else
    {
        A = B = C;
        int z = ans.second.second;
        int r = ans.second.first;
        assert(0 <= z && z <= A[0]);
        assert(r != 0 && A[r] && B[10 - r]);

        string SA, SB;

        for (int i = 0; i < z; i++)
            SA.push_back(0), SB.push_back(0), A[0]--, B[0]--;

        SA.push_back(0 + r);
        SB.push_back(0 + 10 - r);
        A[r]--;
        B[10 - r]--;
        int pt = SA.size();

        for (int q = 0; q < 10; q++)
        {
            while (A[q] && B[9 - q])
                A[q]--, B[9 - q]--, SA.push_back(q), SB.push_back(9 - q);
        }
        for (int q = 0; q < 10; q++)
        {
            while (A[q])
                SA.push_back(q), A[q]--;
            while (B[q])
                SB.push_back(q), B[q]--;
        }
        assert(SA.size() == S.size());
        assert(SB.size() == S.size());
        for (int i = 0; i < S.size(); i++)
            SA[i] += '0', SB[i] += '0';
        reverse(SA.begin(), SA.end());
        reverse(SB.begin(), SB.end());
        cout << SA << endl << SB;
    }
}