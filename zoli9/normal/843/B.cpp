#include <bits/stdc++.h>
using namespace std;
int n, start, xx;
int kerd[50009];
int val[50009];
int kszam=0;
int aszam=0;
int kkerdes=997;
int okerdes=1997;
vector<pair<int, int> > t;
int getr(int meddig)
{
    int x1=rand()%meddig;
    int x2=rand()%meddig;
    int x3=rand()%meddig;
    return (x1+x2+x3)%meddig;
}
void vege()
{
    sort(t.begin(), t.end());
    pair<int, int> legk=t[0];
    int ij=0;
    while(legk.first<xx)
    {
        ij++;
        if(ij==t.size())
        {
            break;
            cout<<"! "<<-1<<endl;
            fflush(stdout);
            exit(0);
        }
        legk=t[ij];
    }
    if(ij>0)
    {
        legk=t[ij-1];
    }
    if(legk.first>=xx)
    {
        cout<<"! "<<legk.first<<endl;
        fflush(stdout);
        exit(0);
    }
    int indk=legk.second;
    int valk=legk.first;
    while(kszam<=okerdes && indk!=-1 && valk<xx)
    {
        //cout<<"* "<<kszam<<" "<<indk<<" "<<valk<<endl;
        cout<<"? "<<indk<<endl;
        fflush(stdout);
        int z1, z2;
        cin>>z1>>z2;
        valk=z1;
        indk=z2;
        kszam++;
    }
    if(valk>=xx)
    {
        cout<<"! "<<valk<<endl;
        fflush(stdout);
        exit(0);
    }
    cout<<"! "<<-1<<endl;
    fflush(stdout);
    exit(0);
}
void newask(int ind)
{
    cout<<"? "<<ind<<endl;
    fflush(stdout);
    int aa, bb;
    cin>>aa>>bb;
    val[ind]=aa;
    kerd[ind]=bb;
    t.push_back({aa, bb});
    kszam++;
    if(kszam==kkerdes)
    {
        //cout<<"kicsi"<<endl;
        vege();
    }
}
void asking(int indexe)
{
    aszam++;
    if(aszam>5*n) vege();
    if(kerd[indexe]!=0) return;
    newask(indexe);
}


int main()
{
    cin>>n>>start>>xx;
    asking(start);
    while(1)
    {
        int r1=getr(n)+1;
        asking(r1);
    }

    return 0;
}