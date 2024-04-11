#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

int sizes[100005];
int vests[100005];
int equip[100005];

int main()
{
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;

    for(int i=0; i<N; i++)
    cin >> sizes[i];

    for(int i=0; i<M; i++)
    cin >> vests[i];

    int k=0, cant=0;
    for(int i=0; i<M && k<N; i++)
    {

        while(sizes[k]+Y<vests[i] && k<N)
        k++;

        if(k<N && sizes[k]-X<=vests[i])
        {
            equip[k]=i+1;
            k++;
            cant++;
        }
    }

    cout << cant << endl;
    for(int i=0; i<N; i++)
    if(equip[i]>0)
    {
        cout << i+1 << " " << equip[i] << endl;
    }
}