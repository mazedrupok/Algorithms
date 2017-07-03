/*
   Name:  Md. Abdul Mazed
   Noakhali Science & Technology University
   Email:  mazedrupok@gmail.com || mazed4g@gmail.com
   FB id:  www.facebook.com/mazedrupok
   github: www.github.com/mazedrupok
   Catagory: Graph (Floyd Warshal Algorithm)
   Comment:  Finding All Pairs Shortest Path.
   Source: Geeksforgeek, https://www.youtube.com/watch?v=LwJdNfdLF9s
*/
#include <bits/stdc++.h>
using namespace std;
#define MX  30050
typedef long long LL;
#define V 4
#define INF 1e9
int path[V][V];
int dist[V][V];
int graph[V][V];
void printPath ();
void pathNodes(int, int);
void printSolution();
void floydWarshall () {
    int i, j, k;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];


    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (dist[i][j] != INF) path[i][j] = i;
            else path[i][j] = -1;
        }
    }
    for (k = 0; k < V; k++){
        for (i = 0; i < V; i++){
            for (j = 0; j < V; j++){
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }
    printSolution();
    printPath ();
}

void printSolution()
{
    printf ("Following matrix shows the shortest distances"
            " between every pair of vertices \n");
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

void pathNodes (int i, int j) {
    if (j == i) {
        printf ("[%d", i); return;
    }
    pathNodes (i, path[i][j]);
    printf (" %d", j);
}

void printPath () {
    printf ("Printing path between every two nodes\n");

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf ("[%d->%d] Path is: ", i, j);
            if (path[i][j] == -1) printf ("No path");
            else {pathNodes (i, j); printf ("] & Distance is: %d", dist[i][j]); }
            printf ("\n");
        }
    }
}

// driver program to test above function
int main()
{
    int graph1[V][V] ={ {0,   3,  6, 15},
                        {INF, 0,  -2, INF},
                        {INF, INF, 0,   2},
                        {1, INF, INF,   0}
                      };
    memcpy (graph, graph1, sizeof (graph));
    floydWarshall();
    return 0;
}
