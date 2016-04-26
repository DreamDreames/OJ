#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;

int main(){ 
    int T; 
    cin >> T; 
    while (T--){ 
        int N, M, S, x, y, i, j;
        queue<int> nodes;
        cin >> N >> M;
        bool **graph = new bool* [N + 2];
        bool *visited = new bool[N + 2];
        int *distance = new int[N + 2];
        for(i = 1; i <= N; ++ i){
            graph[i] = new bool[N + 2];
            for(j = 1; j <= N; ++ j){
                graph[i][j] = false;
            }
            visited[i] = false;
            distance[i] = 0;
        }

        while(M --){
            cin >> x >> y;
            graph[x][y] = true;
            graph[y][x] = true;
        }
        cin >> S;
        nodes.push(S); 
        visited[S] = true;
        while(!nodes.empty()){
            int t = nodes.front();
            nodes.pop();
            for(i = 1; i <= N; ++ i){
                if(graph[t][i] && !visited[i]){
                    distance[i] = distance[t] + 1; 
                    visited[i] = true;
                    nodes.push(i);
                }
            }
        }
        for(i = 1; i <= N; ++ i){
            if(i == S) continue;
            if(distance[i] == 0)
                cout << "-1 ";
            else if(distance[i] > 0)
                cout << distance[i] * 6 << " ";
        }
        cout << endl;

        for(i = 1; i <= N; ++ i)
            delete[] graph[i];
        delete[] graph;
        delete[] visited;
        delete[] distance;
    }
}
