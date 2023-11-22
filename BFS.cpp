#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node *next;
};

class Queue {
private:
    int front;
    int rear;
    int size;
    Node **Q;

public:
    Queue() {
        front = -1;
        rear = -1;
        size = 10;
        Q = new Node *[size];
    }

    Queue(int size) {
        front = -1;
        rear = -1;
        this->size = size;
        Q = new Node *[this->size];
    }

    bool isEmpty() {
        if (front == rear) {
            return true;
        } else {
            return false;
        }
    }

    bool isFull() {
        if (rear == size - 1) {
            return true;
        } else {
            return false;
        }
    }

    void enqueue(Node *x) {
        if (rear == size - 1) {
            cout << "Overflow" << endl;
        } else {
            rear++;
            Q[rear] = x;
        }
    }

    Node *dequeue() {
        Node *x = NULL;
        if (front == rear) {
            cout << "Empty" << endl;
        } else {
            x = Q[front + 1];
            front++;
        }
        return x;
    }
};

class Graph {
public:
    void BFS(int G[][8], int start, int n) {
        int u;
        Queue q(10);
        int visited[8] = {0};
        cout << start;
        visited[start] = 1;
        Node *temp = new Node;
        temp->data = start; 
        q.enqueue(temp);

        while (!q.isEmpty()) {
            u = q.dequeue()->data; 

            for (int v = 1; v <= n; ++v) {
                if (G[u][v] == 1 && visited[v] == 0) {
                    cout << v;
                    visited[v] = 1;
                    Node *temp2 = new Node;
                    temp2->data = v; 
                    q.enqueue(temp2);
                }
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
    g.BFS(G, 1, 8);

    return 0;
}

