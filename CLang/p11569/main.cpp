//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define MAX_N 100000
#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)<(b))?(a):(b)

using namespace std;

//pair fist 정점 second 가중치 
int t, n, m, s, d;
vector<pair<int, int>> adj[MAX_N + 1];

int dijkstra[MAX_N + 1];
int trafficTime[MAX_N + 1];
int visit[MAX_N + 1];

int bfs(int s, int d) {
	queue<int> q;
	queue<int> dq;
	
	cout << "Start : " << s << " End : " << d << endl; 
	q.push(s);
	dq.push(0);
	int count = 0;
	while (q.size()) {
		int size = q.size();
		cout << "Queue Size : " << size <<endl; 
		for (int i = 0 ; i < size ; ++i) {
			int tmp = q.front(); q.pop();
			int distance = dq.front(); dq.pop();
			
			cout << "Node : " << tmp << " Distance : " << distance << endl; 
			
			if (tmp == s) {
				dijkstra[tmp] = 0;
			} else if (dijkstra[tmp] > distance || dijkstra[tmp] == -1) {
				dijkstra[tmp] = distance;
			}
			
			for (pair<int,int> p : adj[tmp]) {
				int node = p.first;
				int dis = p.second;
				
				
				if (dijkstra[node] > distance || dijkstra[node] == -1) {
					q.push(node);
					dq.push(dis+distance);
				}		
			}
		}
		++count;
	}
	
	return -1;
}

int main() {
	scanf("%d", &t);
	//cout<<t<<endl;
	for (int i = 0 ; i < t ; ++i) {
		//배열을 0으로 초기화 
		memset(visit, 0, MAX_N + 1);
		memset(trafficTime, 0, MAX_N + 1);
		for (int j = 0 ; j < MAX_N + 1 ; ++j) {
			dijkstra[j] = -1;
		}
		//벡터를 초기화
		for (int j = 0 ; j < n + 1 ; ++j) {
			adj[j].clear();
		}
		
	
		scanf("%d %d %d %d", &n, &m, &s, &d);
		//printf("%d %d %d %d\n", n, m, s, d);
		
		//간선 정보와 가중치를 받아온다. 
		for (int j = 0 ; j < m ; ++j) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			//printf("%d %d %d\n", a, b, c);
				adj[a].push_back(make_pair(b,c));
				adj[b].push_back(make_pair(a,c));
			}
		for (int j = 0 ; j < n ; ++j) {
			int tmp;
			scanf("%d", &tmp);
			trafficTime[j] = tmp; 
		}
		cout << bfs(s,d) << endl;
		for (int j = 0 ; j < m+1 ; ++j) {
			cout << dijkstra[j] << " ";
		}
		
	}
	return 0;
}
