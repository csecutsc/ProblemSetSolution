#include<bits/stdc++.h>

using namespace std;


int main()
{
    freopen("server_input.txt","r",stdin);
    int N,T,cnt = 0;
    cin >> N >> T;
    for(int i = 0;i < N;i++)
    {
        int a;
        cin >> a;
        T -= a;
        if(T >= 0)
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}
