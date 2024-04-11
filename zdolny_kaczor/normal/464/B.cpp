# include <cstdio>
# include <algorithm>
# include <map>
using namespace std;
int coos[8][3];
long long dist(int a[3], int b[3])
{
    long long res = 0;
    for (int i = 0; i < 3; ++i)
        res += (a[i] - (long long) b[i]) * ((long long)a[i] - b[i]);
    return res;
}
bool iscube()
{
    map <long long, int> dists;
    for (int i = 0; i < 8; ++i)
        for (int k = i + 1; k < 8; ++k)
            dists[dist(coos[i], coos[k])]++;
    if (dists.size() != 3)
        return false;
    pair <long long, int> a[3];
    int cou = 0;
    for (auto x : dists)
    {
        a[cou] = x;
        cou++;
    }
    return a[0].second == 12 && a[1].second == 12 && a[2].second == 4 &&
    a[0].first * 2 == a[1].first && a[0].first * 3 == a[2].first;
    
}
int main()
{
	
	for (int i = 0; i < 8; ++i)
		for (int k = 0; k < 3; ++k)
			scanf("%d", &coos[i][k]);
		for (int i = 0; i < 8; ++i)
			sort(coos[i], coos[i] + 3);
    do
        do
            do
                do 
                    do
                        do
                            do
                                if (iscube())
                                {
																		printf("YES\n");
                                    for (int i = 0; i < 8; ++i)
                                    {
                                        for (int k = 0; k < 3; ++k)
                                            printf("%d ", coos[i][k]);
                                        printf("\n");
                                    }
                                    return 0;
                                }
                            while (next_permutation(coos[1], coos[1] + 3));
                        while (next_permutation(coos[3], coos[3] + 3));
                    while (next_permutation(coos[5], coos[5] + 3));
                while (next_permutation(coos[7], coos[7] + 3));
            while (next_permutation(coos[2], coos[2] + 3));
        while (next_permutation(coos[4], coos[4] + 3));
    while (next_permutation(coos[6], coos[6] + 3));
    printf("NO\n");
}