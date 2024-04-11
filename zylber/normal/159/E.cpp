#include <iostream>
#include <string>
#include <cstdio>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int blocks[100005][3];
long long csize[100005];
int ssize[100005];
vector< vector <pair <long long,int> > > ordblocks;
vector< vector <pair <long long,int> > > sums;

bool greatersfirst(pair <long long, int> a, pair<long long,int> b)
{
    if(a.first>b.first)return true;return false;
}

int main()
{
    map<long long,int> colors;
    int ccolors=0;
    int N;
    cin >> N;
    ordblocks.resize(100005);

    for(int i=0; i<N; i++)
    {
        cin >> blocks[i][0] >> blocks[i][1];

        if(colors.count(blocks[i][0])>0)
        {
            ordblocks[colors[blocks[i][0]]].push_back(make_pair(blocks[i][1],i+1));
            csize[colors[blocks[i][0]]]++;
        }
        else
        {
            ordblocks[ccolors].push_back(make_pair(blocks[i][1],i+1));
            colors.insert(make_pair(blocks[i][0],ccolors));
            csize[ccolors]=1;
            ccolors++;
        }
    }

    for(int i=0; i<ccolors; i++)
    sort(ordblocks[i].begin(),ordblocks[i].end(),greatersfirst);

    for(int i=0; i<ccolors; i++)
    for(int j=1; j<csize[i]; j++)
    ordblocks[i][j].first+=ordblocks[i][j-1].first;

    long long maxsize=0;
    for(int i=0; i<ccolors; i++)
    maxsize=max(maxsize,csize[i]);
    maxsize++;

    sums.resize(maxsize);
    for(int i=0; i<ccolors; i++)
    {
        for(int j=0; j<csize[i]-1; j++)
        {
        sums[j].push_back(make_pair(ordblocks[i][j].first, i));
        ssize[j]++;
        }
        sums[csize[i]-1].push_back(make_pair(ordblocks[i][csize[i]-1].first, i));
        sums[csize[i]].push_back(make_pair(ordblocks[i][csize[i]-1].first, i));
        ssize[csize[i]-1]++;
        ssize[csize[i]]++;
    }

    for(int i=0; i<maxsize; i++)
    sort(sums[i].begin(),sums[i].end(),greatersfirst);

    long long bestsum=0, color1=0, color2=0;
    for(int i=0; i<ccolors; i++)
    if(ssize[csize[i]]>1)
    {
        int actcol=0;
        long long actsum=ordblocks[i][csize[i]-1].first;

        if(sums[csize[i]][0].second==i)
        {
            actsum+=sums[csize[i]][1].first;
            actcol=sums[csize[i]][1].second;
        }
        else
        {
            actsum+=sums[csize[i]][0].first;
            actcol=sums[csize[i]][0].second;
        }

        if(bestsum<actsum)
        {
            bestsum=actsum;
            color1=i;
            color2=actcol;
        }
    }

    cout << bestsum << endl;

    long long bestcant=2LL*csize[color1];
    if(csize[color2]>csize[color1])
    bestcant++;
    cout << bestcant << endl;

    for(int i=0; i<csize[color1]-1; i++)
    cout << ordblocks[color2][i].second << " " << ordblocks[color1][i].second << " ";
    cout << ordblocks[color2][csize[color1]-1].second << " " << ordblocks[color1][csize[color1]-1].second;

    if(bestcant%2)
    cout << " " << ordblocks[color2][csize[color1]].second;

    cout << endl;
}