#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

const int N = 100006;

int pre_mx[N];
int a[N];

bool is_mx[N];

int main ()
{
    int n;
    scanf("%d",&n);
    int now=0;
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&a[i]);
        if (a[i] > pre_mx[i-1])
        {
            is_mx[i] = 1;
            now++;
        }
        pre_mx[i] = max(pre_mx[i-1],a[i]);
    }
    int ans = -1;
    int can_more = -2;
    stack<int> sta;
    for (int i=n;i>=1;i--)
    {
        int tmp=0;
        int before_mx = pre_mx[i-1];
        while (!sta.empty() && sta.top() < a[i])
        {
            if (sta.top() > before_mx) tmp++;
            sta.pop();
        }
        sta.push(a[i]);
        if (is_mx[i]) --tmp;
        //cout << "i = "<<i<<" , tmp = "<<tmp<<endl;
        if (tmp > can_more)
        {
            ans = a[i];
            can_more = tmp;
        }
        else if (tmp == can_more)
        {
            ans = min(a[i],ans);
        }
    }
    printf("%d\n",ans);
}