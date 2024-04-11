#include <iostream>

using namespace std;

int main()
{
    int n,m; cin>>n>>m;
    int r = 0 , k = n , arr[n]={};

    for(int i = 0; i < m; ++i)
    {
        int a; cin>>a; --a;
        if(arr[a] == r) --k;
        ++arr[a];

        if(k == 0){
            cout << 1; k = n; ++r;
            for(int j = 0; j < n; ++j)
                if(arr[j] > r) --k;
        }
        else cout << 0;
    }

    return 0;
}