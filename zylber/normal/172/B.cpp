#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int r[100010];

int main()
{
    int M, A, B, R;
    cin >> A >> B >> M >> R;

    int k=1;
    while(r[R]==0)
    {
        r[R]=k;
        k++;
        R=(A*R+B)%M;
    }

    cout << k-r[R] << endl;
}