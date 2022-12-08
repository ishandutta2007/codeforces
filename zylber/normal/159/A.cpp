#include <iostream>
#include <string>
#include <queue>
#include <utility>
using namespace std;

int friends[2005][2005];
int last[2005][2005];
string names[2005];
int cnames;

int findname(string name)
{
    for(int i=0; i<cnames; i++)
    if(names[i]==name)
    return i;

    names[cnames]=name;
    cnames++;
    return cnames-1;
}

int main()
{
    int N, D;
    cin >> N >> D;
    cnames=0;
    int cfriends=0;

    for(int i=0; i<2005; i++)
    for(int j=0; j<2005; j++)
    last[i][j]=-1;
    int lastt=-1;
    queue<pair<int,int> > nose;

    for(int i=0; i<N; i++)
    {
        string name1, name2; int t;
        cin >> name1 >> name2 >> t;

        if(t!=lastt)
        while(!nose.empty())
        {
            last[nose.front().first][nose.front().second]=lastt;
            nose.pop();
        }
        lastt=t;

        int cname1=findname(name1), cname2=findname(name2);

        if(last[cname2][cname1]>=0 && t-last[cname2][cname1]<=D)
        {
            if(friends[cname1][cname2]==0)
            cfriends++;

            friends[cname1][cname2]=1;
            friends[cname2][cname1]=1;

        }
        nose.push(make_pair(cname1,cname2));
    }

    cout << cfriends << endl;

    for(int i=0; i<cnames; i++)
    for(int j=0; j<i; j++)
    if(friends[i][j]==1)
    cout << names[i] << " " << names[j] << endl;
}