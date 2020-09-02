#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

bool vis[51][51];

const int row[4] = {-1, 1, 0, 0};
const int col[4] = {0, 0, -1, 1};
int n, m;
vector<string> a;

bool check(int x, int y)
{
    if (x >= 0 && y >= 0 && x < n && y < m && !vis[x][y] && a[x][y] != '#')
        return true;
    return false;
}

void dfs(int x, int y)
{

    vis[x][y] = 1;

    for (int i = 0; i < 4; ++i)
    {
        if (check(x + row[i], y + col[i]))
        {
            dfs(x + row[i], y + col[i]);
        }
    }
}

int main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {

        cin >> n >> m;
        a.resize(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        bool val = true;

        int x = -1;
        int y = -1;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (a[i][j] == 'B')
                {
                    if (i > 0 && a[i - 1][j] == '.')
                        a[i - 1][j] = '#';
                    else if (i > 0 && a[i - 1][j] == 'G')
                        val = false;

                    if (j > 0 && a[i][j - 1] == '.')
                        a[i][j - 1] = '#';
                    else if (j > 0 && a[i][j - 1] == 'G')
                        val = false;

                    if (i < n - 1 && a[i + 1][j] == '.')
                        a[i + 1][j] = '#';
                    else if (i < n - 1 && a[i + 1][j] == 'G')
                        val = false;

                    if (j < m - 1 && a[i][j + 1] == '.')
                        a[i][j + 1] = '#';
                    else if (j < m - 1 && a[i][j + 1] == 'G')
                        val = false;
                }
                if (a[i][j] == 'G')
                {
                    x = i;
                    y = j;
                }
            }
        }

        if (x == -1)
            cout << "Yes" << endl;
        else if (!val || a[n - 1][m - 1] == '#')
            cout << "No" << endl;
        else
        {

            memset(vis, false, sizeof(vis));
            a[n - 1][m - 1] = 'G';
            dfs(x, y);
            val = true;

            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    if (a[i][j] == 'G' && !vis[i][j])
                        val = false;
                    if (a[i][j] == 'B' && vis[i][j])
                        val = false;
                }
            }
            if (val)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        a.clear();
    }
}