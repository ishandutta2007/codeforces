# include <cstdio>
# include <algorithm>
# include <vector>
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
using namespace std;
const bool Masha = true, Dasha = false;
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int g = gcd(a, b);
    a /= g;
    b /= g;
    vector <pair <long long, bool> > timetable;
    for (long long i = 0; i < a; ++i)
        timetable.push_back(make_pair(i * b, Masha));
    for (long long i = 0; i < b; ++i)
        timetable.push_back(make_pair(i * a, Dasha));
    sort(timetable.begin(), timetable.end());
    long long diff = 0;
    for (int i = 0; i < (int) timetable.size() - 1; ++i)
    {
        long long dt = timetable[i + 1].first - timetable[i].first;
        if (timetable[i + 1].second == Masha)
            diff += dt;
        else
            diff -= dt;
    }
    long long dt = (long long) a * b - timetable.back().first;
    if (a < b)
        diff += dt;
    else
        diff -= dt;
    if (diff == 0)
        printf("Equal\n");
    else if (diff < 0)
        printf("Dasha\n");
    else
        printf("Masha\n");
}