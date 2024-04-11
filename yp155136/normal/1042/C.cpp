#include <bits/stdc++.h>
using namespace std;

const int N = 200006;
int a[N];

bool used[N];

vector<int> pos,neg,zero;
int n;

void del_0()
{
    if ((int)zero.size() == 0) return;
    if ((int)zero.size() == n)
    {
        int mx = -1234567889;
        int mx_id = -1;
        for (int i:zero)
        {
            if (a[i] > mx)
            {
                mx = a[i];
                mx_id = i;
            }
        }
        vector<int> zero2;
        for (int i:zero)
        {
            if (i == mx_id) continue;
            zero2.push_back(i);
        }
        swap(zero,zero2);
        del_0();
        return;
    }
    int tar = zero[0];
    for (int i:zero) used[i] = true;
    for (int i:zero)
    {
        if (i == tar) continue;
        printf("1 %d %d\n",i,tar);
    }
    printf("2 %d\n",tar);
}

int main ()
{
    //int n;
    scanf("%d",&n);
    //vector<int> pos,neg,zero;
    for (int i=1;i<=n;++i)
    {
        int x;
        scanf("%d",&x);
        a[i] = x;
        if (x == 0) zero.push_back(i);
        else if (x > 0) pos.push_back(i);
        else if (x < 0) neg.push_back(i);
    }
    /*if ((int)zero.size() > 1)
    {
        
        for (int i=2;i<=n;++i)
        {
            printf("1 %d 1\n",i);
        }
        return 0;
    }*/
    #define SZ(x) ((int)(x).size())
    if (SZ(neg)%2 == 0)
    {
        if (SZ(zero) == 0)
        {
            for (int i=2;i<=n;++i)
            {
                printf("1 %d 1\n",i);
            }
            return 0;
        }
        else
        {
            del_0();
            //printf("2 %d\n",zero[0]);
            for (int i:neg) pos.push_back(i);
            if (SZ(pos) == 0) return 0;
            int tar = pos[0];
            for (int i:pos)
            {
                if (i == tar) continue;
                printf("1 %d %d\n",i,tar);
            }
            return 0;
        }
    }
    else
    {
        //delete abs small
        int mn = 1234567890;
        int mn_pos = -1;
        for (int i:neg)
        {
            if (abs(a[i]) < mn)
            {
                mn = abs(a[i]);
                mn_pos = i;
            }
        }
        zero.push_back(mn_pos);
        //cout << "mn_pos = " << mn_pos << endl;
        del_0();
        //cout << "finish delete 0" << endl;
        //printf("2 %d\n",mn_pos);
        //int tar = 1;
        for (int i:neg) if (i != mn_pos)pos.push_back(i);
        if (SZ(pos) == 0) return 0;
        int tar = pos[0];
        for (int i:pos)
        {
            if (i == tar) continue;
            printf("1 %d %d\n",i,tar);
        }
        /*if (mn_pos == 1) tar = 2;
        for (int i=2;i<=n;++i)
        {
            if (i == tar || i == mn_pos || used[i]) continue;
            printf("1 %d %d\n",i,tar);
        }
        */
        return 0;
    }
}