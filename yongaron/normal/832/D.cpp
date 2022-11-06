#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, q, k;
int vzd[100005], a[100005], b[100005], c[100005];
int otec[100005][20];
vector<int> graf[100005];
queue<pair<int, int> > fr;

int predek(int vr1, int vr2);
void nacti();
void vyres();
void sir();
void ot();

int main()
{
    nacti();
    vyres();
    return 0;
}

void nacti()
{
    int x, y, z;
    cin>>n;
    cin>>q;
    vzd[0] = -1;
    vzd[1] = 0;
    otec[1][0] = 1;
    for(int i = 2; i <= n; i++)
    {
        otec[i][0] = i;
        vzd[i] = -1;
        cin>>x;
        graf[i].push_back(x);
        graf[x].push_back(i);
    }
    for(int i = 0; i < q; i++)
    {
        cin>>a[i];
        cin>>b[i];
        cin>>c[i];
    }
}
void sir()
{
    int a, d;
    fr.push(make_pair(1, 0));
    otec[1][1] = 0;
    while(!fr.empty())
    {
        a = fr.front().first;
        d = fr.front().second;
        fr.pop();
        for(int i = 0; i < graf[a].size(); i++)
        {
            if(vzd[graf[a][i]] == -1)
            {
                vzd[graf[a][i]] = d+1;
                fr.push(make_pair(graf[a][i], d+1));
                otec[graf[a][i]][1] = a;
            }
        }
    }
}
void vyres()
{
    int pab, pbc, pac, ab, ac, bc, x;
    sir();
    ot();
    for(int i = 0; i < q; i++)
    {
        pab = predek(a[i], b[i]);
        pbc = predek(b[i], c[i]);
        pac = predek(a[i], c[i]);
        ab = vzd[a[i]]+vzd[b[i]]-2*vzd[pab];
        ac = vzd[a[i]]+vzd[c[i]]-2*vzd[pac];
        bc = vzd[b[i]]+vzd[c[i]]-2*vzd[pbc];
        x = max(max(ab+ac-bc, ac+bc-ab), ab+bc-ac);
        cout<<x/2+1<<endl;
    }
}
void ot()
{
    for(int i = 2; i < 20; i++)
        for(int j = 1; j <= n; j++)
            otec[j][i] = otec[otec[j][i-1]][i-1];
}
int predek(int vr1, int vr2)
{
    int x, a;
    if(vzd[vr1] < vzd[vr2])
    {
        x = vr1;
        vr1 = vr2;
        vr2 = x;
    }
    for(int i = 19; i > 0; i--)
    {
        if(vzd[otec[vr1][i]] >= vzd[vr2])
            vr1 = otec[vr1][i];
    }
    for(int i = 19; i >= 0; i--)
    {
        if(otec[vr1][i] == otec[vr2][i])
            a = otec[vr1][i];
        else
        {
            vr1 = otec[vr1][i];
            vr2 = otec[vr2][i];
        }
    }
    return a;
}