#include <iostream>
#include <climits>

#define INF INT_MAX;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, k;
    cin>>n>>k;
    int planks[150001];

    for (int i =0; i< n; i++){
        cin >> planks[i];
    }

    int cumulative_planks[150001];
    cumulative_planks[0] = 0;
    for (int i = 1; i<=n;i++){
        cumulative_planks[i] = cumulative_planks[i - 1] + planks[i - 1];
    }
    int min = INF;
    int index = -1;

    for(int i = 0; i < n - k + 1; i++)
    {
        if(cumulative_planks[k + i] - cumulative_planks[i] < min)
        {
            min = cumulative_planks[k + i] - cumulative_planks[i];
            index = i + 1;
        }
    }
    cout << index << endl;
   return 0;
}