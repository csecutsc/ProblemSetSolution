#include<bits/stdc++.h>

using namespace std;

int N, cnt;

int main()
{
    freopen("cold_input.txt","r",stdin);
    cin >> N;
    for(int i = 0;i < N;i++)
    {
        int in;
        cin >> in;
        if(in < 0)
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}
