//DFS
#include <iostream>
#include <queue>
using namespace std;

class Graph {
public:
  void DFS(int G[][8], int start, int n) {
    int visited[8] = {0};

    DFSUtil(G, start, visited);
  }

private:
  void DFSUtil(int G[][8], int start, int visited[]) {
    if (visited[start] == 1) {
      return; 
    }

    cout << start;
    visited[start] = 1;

    for (int v = 1; v <= 8; v++) {
      if (G[start][v] == 1 && visited[v] == 0) {
        DFSUtil(G, v, visited);
      }
    }
  }
};


int main() {
    int G[8][8] = {{0, 0, 0, 0, 0, 0, 0,0},
                       {0, 0, 1, 1, 1,0, 0, 0},
                       {0, 1, 0, 1, 0,0, 0, 0},
                       {0, 1, 1, 0, 1, 1,0, 0},
                       {0, 1, 0, 1, 0, 1, 0,0},
                       {0, 0, 0, 1, 1, 0, 1,1},
                       {0, 0, 0, 0,0, 1, 0, 0},
					   {0, 0, 0, 0,0, 1, 0, 0}};
    Graph g;
    g.DFS(G, 5, 8);

    return 0;
}

