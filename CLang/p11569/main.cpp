//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <functional>
#define MAX_N 100000
#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)<(b))?(a):(b)

using namespace std;

//pair fist ���� second ����ġ
int t, n, m, s, d;
vector<pair<int, int>> adj[MAX_N + 1];

long long dijkstra[MAX_N + 1];
int trafficTime[MAX_N + 1];

void intarrayset(int *a, int data, int size)
{
    for(int i = 0 ; i < size ; ++i)
    {
        a[i] = data;
    }
}

void longarrayset(long long *a, long long data, int size)
{
    for(int i = 0 ; i < size ; ++i)
    {
        a[i] = data;
    }
}

long long bfs(int s, int d)
{
    queue<int> q;
    queue<long long> dq;

    //cout << "Start : " << s << " End : " << d << endl;

    // ��� ���� �ð��� ť�� �ִ´�.
    q.push(s);
    q.push(-1);
    dq.push(0);

    int count = 0;

    //ť�� ������� ������
    while (q.size())
    {
        int size = q.size()/2;

        //cout << "Queue Size : " << size <<endl;

        for (int i = 0 ; i < size ; ++i)
        {

            //ť���� ���� �ð��� ������
            int tmp = q.front(); q.pop();
            int prevnode = q.front(); q.pop();
            long long time = dq.front(); dq.pop();

            //cout << "Node : " << tmp << " Time : " << time << endl;

            if (tmp == s)
            {
                dijkstra[tmp] = 0;
            }
            else if (dijkstra[tmp] > time || dijkstra[tmp] == -1)
            {
                dijkstra[tmp] = time;
            }
            int j = -1;
            int k = -1;
            for (pair<int,int> p : adj[tmp])
            {
                ++j;
                int node = p.first;
                if (node == prevnode) {
                    k = j;
                    continue;
                }
            }
            for (pair<int,int> p : adj[tmp])
            {
                int node = p.first;
                if (node == prevnode) {
                    continue;
                }
                long long tim = p.second;
                long long t = time;
                long long tr = trafficTime[tmp];
                long long siz = adj[tmp].size();
                long long cur = (t/tr)%siz;
                long long leftTime = ((t / tr + (k + siz - cur) % siz) * tr) - t;
                if (cur == k  || tmp == d || tmp == s)
                    leftTime = 0;

                //cout << "Now Node : " << tmp << " To Node : " << node << endl;
                //cout << "Time : " << t << " Currunt : " << cur <<  " To : " << to << " LeftTime : " << leftTime << " Time: " << time + tim + leftTime << endl;


                //�湮 ���� �ʾҰų� �ɸ� �ð��� �� ª����
                if (dijkstra[node] > time + tim + leftTime || dijkstra[node] == -1)
                {
                    q.push(node);
                    q.push(tmp);
                    dq.push(time + tim + leftTime);
                }
            }
            //cout << endl;
        }
        ++count;
    }
    return dijkstra[d];
}

int main()
{
    scanf("%d", &t);
    //cout<<t<<endl;
    for (int i = 0 ; i < t ; ++i)
    {
        //�迭�� 0���� �ʱ�ȭ
        intarrayset(trafficTime, 0, MAX_N + 1);
        longarrayset(dijkstra, -1, MAX_N + 1);

        //���͸� �ʱ�ȭ
        for (int j = 0 ; j < n + 1 ; ++j)
        {
            adj[j].clear();
        }


        scanf("%d %d %d %d", &n, &m, &s, &d);
        //printf("%d %d %d %d\n", n, m, s, d);

        //���� ������ ����ġ�� �޾ƿ´�.
        for (int j = 0 ; j < m ; ++j)
        {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            //printf("%d %d %d\n", a, b, c);
            adj[a].push_back(make_pair(b,c));
            adj[b].push_back(make_pair(a,c));
        }

        for (int j = 1 ; j < m + 1 ; ++j)
        {
            sort(adj[j].begin(), adj[j].end(), [](pair<int, int> &p1, pair<int, int> &p2)->bool{return p1.first < p2.first;});
        }

        for (int j = 1 ; j < n + 1 ; ++j)
        {
            int tmp;
            scanf("%d", &tmp);
            trafficTime[j] = tmp;
        }
        cout << bfs(s,d) << endl;
        for (int j = 0 ; j < n +1 ; ++j)
        {
            //cout << dijkstra[j] << " ";
        }

    }
    return 0;
}
