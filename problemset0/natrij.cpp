#include<bits/stdc++.h>
#define endl '\n'
#define needforspeed ios_base::sync_with_stdio (false);cin.tie();
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define len(x) (int)(x).size()
#define ms(a,b) memset( (a), (b), sizeof( (a) ) )
#define xx first
#define yy second
#define LL long long
#define DB 0
#define MAXN 1005
#define inf 0x3f3f3f3f
using namespace std;

int to_int(string str)
{
    stringstream ss(str);
    int ret;
    ss >> ret;
    return ret;
}

vector<int>split(string str)
{
    stringstream ss(str);
    vector<int>ret;
    string tmp;
    while(getline(ss,tmp, ':'))
    {
        ret.push_back(to_int(tmp));
    }
    return ret;
}



tuple<int,int,int> difference(vector<int>t1, vector<int>t2)
{
    #define h 0
    #define m 1
    #define s 2
    int hour = 0, mins = 0,secs = 0;
    while(t1 != t2)
    {
        t1[s] += 1;
        if(t1[s] == 60)
        {
            t1[m] += 1;
            t1[s] = 0;
        }
        if(t1[m] == 60)
        {
            t1[h] += 1;
            t1[m] = 0;
        }
        if(t1[h] == 24)
        {
            t1[h] = 0;
        }
        secs++;
        if(secs == 60)
        {
            mins += 1;
            secs = 0;
        }
        if(mins == 60)
        {
            hour += 1;
            mins = 0;
        }
    }
    #undef h
    #undef m
    #undef s
    if(hour == 0 && mins == 0 && secs == 0)
        hour = 24, mins = 0, secs = 0;
    if(hour == 24)
        hour = 24, mins = 0, secs = 0;
    return make_tuple(hour,mins,secs);
}

int main()
{
    freopen("natrij_input.txt","r",stdin);
    needforspeed;
    string t1,t2;
    getline(cin, t1);
    getline(cin,t2);
    vector<int>vt1 = split(t1);
    vector<int>vt2 = split(t2);
    tuple<int, int, int>t = difference(vt1,vt2);
    printf("%02d:%02d:%02d",get<0>(t),get<1>(t),get<2>(t));
    return 0;
}
