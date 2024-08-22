#include <iostream>
#include <vector>

using namespace std;


#ifndef GRAFOS_H
#define GRAFOS_H


class Queue {
private:
    std::vector<int> data;
    int front;
    int rear;
    int size;

public:
    Queue(int capacity) : front(0), rear(-1), size(0) {
        data.resize(capacity);
    }

    void push(int value) {
        if (size == data.size()) {
            std::cout << "Queue is full" << std::endl;
            return;
        }
        rear = (rear + 1) % data.size();
        data[rear] = value;
        size++;
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return -1;
        }
        int value = data[front];
        front = (front + 1) % data.size();
        size--;
        return value;
    }

    bool isEmpty() {
        return size == 0;
    }
};

class Graph {
private:
    std::vector<std::vector<int>> adjacencyList;
    int numVertices;

public:
    Graph(int vertices) : numVertices(vertices) {
        adjacencyList.resize(vertices);
    }

    void addEdge(int v, int w) {
        adjacencyList[v].push_back(w);
        adjacencyList[w].push_back(v);  // For undirected graph
    }

    void BFS(int startVertex) {
        std::vector<bool> visited(numVertices, false);
        Queue queue(numVertices);

        visited[startVertex] = true;
        queue.push(startVertex);

        while (!queue.isEmpty()) {
            int currentVertex = queue.pop();
            std::cout << currentVertex << " ";

            for (int adjacentVertex : adjacencyList[currentVertex]) {
                if (!visited[adjacentVertex]) {
                    visited[adjacentVertex] = true;
                    queue.push(adjacentVertex);
                }
            }
        }
    }
};



#endif