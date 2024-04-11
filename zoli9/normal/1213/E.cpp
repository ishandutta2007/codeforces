#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n;
int t[2][2];
int darab[3];
bool van(int x, int y)
{
    return ((t[0][0]==x && t[0][1]==y) || (t[1][0]==x && t[1][1]==y));
}
int perm[6][3]={{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            char ccc;
            cin>>ccc;
            t[i][j]=ccc-'a';
            darab[t[i][j]]++;
        }
    }
    if(t[0][0]==t[0][1] || t[1][0]==t[1][1])
    {
        for(int i=0; i<6; i++)
        {
            if(van(perm[i][0], perm[i][1])) continue;
            if(van(perm[i][1], perm[i][2])) continue;
            if(van(perm[i][2], perm[i][0])) continue;
            cout<<"YES"<<endl;
            for(int k=0; k<n; k++)
            {
                cout<<(char)('a'+perm[i][0]);
                cout<<(char)('a'+perm[i][1]);
                cout<<(char)('a'+perm[i][2]);
            }
            cout<<endl;
            return 0;
        }
    }
    else
    {
        int kozep;
        int m1=-1, m2=-1;
        for(int i=0; i<3; i++)
        {
            if(darab[i]<=1)
            {
                kozep=i;
                break;
            }
        }
        for(int i=0; i<3; i++)
        {
            if(i==kozep) continue;
            if(m1==-1) m1=i;
            else m2=i;
        }
        int eleje;
        int vege;
        if(van(m1, kozep) || van(kozep, m2))
        {
            swap(m1, m2);
        }
        cout<<"YES"<<endl;
        for(int i=0; i<n; i++) cout<<((char)('a'+m1));
        for(int i=0; i<n; i++) cout<<((char)('a'+kozep));
        for(int i=0; i<n; i++) cout<<((char)('a'+m2));
        cout<<endl;
        return 0;
    }

    return 0;
}