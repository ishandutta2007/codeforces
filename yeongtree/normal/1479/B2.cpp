#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int A[n]; for(auto &i : A) cin >> i;
    unordered_set<int> S;

    int p = 0, a = 0;
    for(auto i : A)
    {
        if(p == i) ;
        else if(S.count(i))
        {
            S.clear();
            S.insert(p);
            p = i;
        }
        else
        {
            S.insert(p);
            p = i;
            ++a;
        }
    }

    cout << a;
}