# include <cstdio>
# include <set>
# define pos first
# define hei second
using namespace std;
const int MN=100100;
pair <int, int> tries[MN];
int main()
{
    int n;
    scanf("%d", &n);
    if (n<=2)
    {
        printf("%d\n", n);
        return 0;
    }
    for (int i=0; i<n; ++i)
        scanf("%d%d", &tries[i].pos, &tries[i].hei);
    int res=2;
    for (int i=1; i<n-1; ++i)
    {
        if (tries[i].pos-tries[i].hei>tries[i-1].pos)
            res++;
        else if (tries[i].pos+tries[i].hei<tries[i+1].pos)
        {
            tries[i].pos+=tries[i].hei;
            res++;
        }
    }
    printf("%d\n", res);
}