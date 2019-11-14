#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

#define MAX_N 100000

using namespace std;

int N, M, S;

vector<int> adj[MAX_N + 1];
bool visit[MAX_N + 1];

void bfs(int n)
{
    queue<int> q;
    visit[n] = 1;
    q.push(n);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0 ; i < size ; ++i)
        {
            int cNode = q.front();
            q.pop();
            cout << cNode;

            for (int nNode : adj[cNode])
            {
                if (!visit[nNode])
                {
                    visit[nNode] = 1;
                    q.push(nNode);
                }
            }
            if (!q.empty())
            {
                cout << " ";
            }
        }
    }
}

void dfs(int n)
{
    int cNode = n;
    stack<int> s;

    visit[n] = 1;
    s.push(n);

    cout << n;

    while (!s.empty())
    {
        int count = 0;
        for (int nNode : adj[cNode])
        {
            if (!visit[nNode])
            {
                ++count;
            }
        }

        if (count)
        {
            for (int nNode : adj[cNode])
            {
                if (!visit[nNode])
                {
                    visit[nNode] = 1;
                    s.push(nNode);
                    cNode = nNode;
                    break;
                }
            }
        }
        else
        {
            s.pop();
            if (s.empty())
            {
                return;
            }
            cNode = s.top();
            //cout << cNode << endl;
            continue;
        }
        cout << " " << cNode;
    }
}

int main()
{
    scanf("%d %d %d", &N, &M, &S);
    for (int i = 0 ; i < M ; ++i)
    {
        int a, b;
        scanf ("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1 ; i < N +1 ; ++i)
    {
        sort(adj[i].begin(),adj[i].end());
    }

    memset(&visit, 0, MAX_N + 1);
    dfs(S);
    cout << endl;
    memset(&visit, 0, MAX_N + 1);
    bfs(S);
    cout << endl;

    return 0;
}
