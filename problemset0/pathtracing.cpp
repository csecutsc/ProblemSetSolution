#include<bits/stdc++.h>
#define ms(a,b) memset( (a), (b), sizeof( (a) ) )

using namespace std;

char grid[250][250];
enum dir{UP,RT,DN,LT};
int N = 50, E = 50, W = 50, S = 50;
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

int main()
{
    freopen("pathtracing_input.txt","r",stdin);
    string in;
    int r = 50,c = 50;
    ms(grid, ' ');
    grid[r][c] = 'S';
    while(cin >> in)
    {
        if(in == "down")
            r += dr[DN], c += dc[DN];
        if(in == "up")
            r += dr[UP], c += dc[UP];
        if(in == "left")
            r += dr[LT], c += dc[LT];
        if(in == "right")
            r += dr[RT], c += dc[RT];
        grid[r][c] = '*';
        // keep track of most distant coordinates
        N = max(N, r);
        W = min(W, c);
        E = max(E, c);
        S = min(S, r);
    }
    grid[50][50] = 'S';
    grid[r][c] = 'E';
    for(int i = W-1;i <= E+1;i++)
        cout << "#";
    cout << endl;
    for(int i = S; i <= N;i++)
    {
        cout << "#";
        for(int j = W;j <= E;j++)
        {
            cout << grid[i][j];
        }
        cout << "#\n";
    }
    for(int i = W-1;i <= E+1;i++)
        cout << "#";
    cout << endl;
    return 0;
}
