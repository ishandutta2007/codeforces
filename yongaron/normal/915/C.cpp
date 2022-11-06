#include <iostream>
#include <vector>

using namespace std;
long long a, b;
int aa[10], bb[10];
vector<int> v, w;

int hig(int x)
{
    for(int i = x; i >= 0; i--)
        if(aa[i] > 0)
            return i;
    return -1;
}

int main()
{
    cin>>a>>b;
    int na = 0, nb = 0;
    while(a > 0)
    {
        aa[a%10]++;
        bb[a%10]++;
        a /= (long long)10;
        na++;
    }
    while(b > 0)
    {
        v.push_back(b%10);
        b /= (long long)10;
        nb++;
    }
    if(nb > na)
        for(int i = 9; i >= 0; i--)
            for(int j = 0; j < aa[i]; j++)
                cout<<i;
    else
    {
        for(int i = na; i >= 0; i--)
        {
            for(int i = 0; i <= 9; i++)
                aa[i] = bb[i];
            w.clear();
            bool ok = true, was = false;
            for(int j = 0; j < na; j++)
            {

                int h = hig(v[na-j-1]);
                if(j == i)
                    h = hig(v[na-j-1]-1);
                if(was)
                    h = hig(9);
                //cout<<was<<" "<<v[na-j-1]<<" "<<h<<endl;
                if(h == -1)
                {
                    ok = false;
                    break;
                }
                aa[h]--;
                if(h < v[na-j-1])
                    was = true;
                w.push_back(h);
            }
            //cout<<i<<endl;
            /*for(int i = 0; i < w.size(); i++)
                cout<<w[i];
            cout<<endl;*/
            if(ok)
                break;
        }
        for(int i = 0; i < w.size(); i++)
            cout<<w[i];
    }
    cout<<endl;
    return 0;
}
/*
319784245254625
543615945149815

319784254625
543615149815
*/