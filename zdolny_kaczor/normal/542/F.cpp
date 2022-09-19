# include <cstdio>
# include <vector>
# include <algorithm>
using namespace std;
const int MT=107;
vector <int> layers[MT];
int main()
{
    int n, T;
    scanf("%d%d", &n, &T);
    for (int i=0; i<n; ++i)
    {
        int q, t;
        scanf("%d%d", &t, &q);
        layers[T-t].push_back(q);
    }
    for (int l=MT-1; l; --l)
    {
        sort(layers[l].begin(), layers[l].end());
        for (int k=layers[l].size()-1; k>=1; k-=2)
            layers[l-1].push_back(layers[l][k]+layers[l][k-1]);
        if (layers[l].size()%2)
            layers[l-1].push_back(layers[l][0]);
    }
        sort(layers[0].begin(), layers[0].end());
    printf("%d\n", layers[0].back());
}