#include <iostream>
#include <vector>

using namespace std;

void bemax(int &toChange, const int &toCompare)
{
    if(toChange < toCompare) toChange = toCompare;
}

int _max(const int &x, const int &y)
{
    return (x > y ? x : y);
}

int lengthOfLCS(int s, int t, vector<int> &arr, vector<vector<int> > &LCS)
{
    if(s < 0 || t >= (int)LCS.size()) return 0;
    if(LCS[s][t] != -1) return LCS[s][t];

    int ans;
    if(arr[s] == arr[t]) ans = 1 + lengthOfLCS(s - 1, t + 1, arr, LCS);
    else ans = _max(lengthOfLCS(s - 1, t, arr, LCS), lengthOfLCS(s, t + 1, arr, LCS));

    return LCS[s][t] = ans;
}

int main()
{
    int N; cin >> N;

    vector<int> arr;
    for(int i = 0; i < N; ++i)
    {
        int tmp; cin >> tmp;
        if(arr.empty() || arr.back() != tmp) arr.push_back(tmp);
    }

    int trueLen = arr.size();
    vector<vector<int> > LCS(trueLen, vector<int>(trueLen, -1));

    int down = 0;
    for(int i = 0; i < trueLen - 2; ++i)
    {
        bemax(down, lengthOfLCS(i, i + 2, arr, LCS));
    }
    cout << trueLen - down - 1;

    return 0;
}