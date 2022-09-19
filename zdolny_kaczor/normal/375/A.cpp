# include <cstdio>
# include <algorithm>
# include <cstring>
using namespace std;
const int MN = 1000000;
char tab[MN];
int main()
{
    scanf("%s", tab);
    int n = strlen(tab);
    while (true)
    {
        random_shuffle(tab, tab + n);
        int sum = 0;
        for (int i = 0; i < n; ++i)
            sum = (sum * 3 + tab[i] - '0') % 7;
        if (sum == 0)
        {
            int cou = 0;
            bool in = false;
            for (int i = 0; i < n; ++i)
                if (in)
                    putchar(tab[i]);
                else if (tab[i] == '0')
                    cou ++;
                else
                {
                    in = true;
                    putchar(tab[i]);
                }
            for (int i = 0; i < cou; ++i)
                putchar('0');
            return 0;
        }
    }
}