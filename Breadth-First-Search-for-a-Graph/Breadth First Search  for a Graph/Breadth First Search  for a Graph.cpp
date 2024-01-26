#include <locale.h>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

//Ориентированный граф
class Graph
{
    int V;//вершины

    vector<list<int> > adj;//Указатель на массив, содержащий списки смежности

public:
    Graph(int V);

    void addEdge(int v, int w);// функция добавления ребра

    void BFS(int s);//выводит обход BFS от данного значения
};

Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
}
void Graph::addEdge(int v,int w)
{
    //добавляем w к списку v
    adj[v].push_back(w);
}

void Graph::BFS(int s)
{
    //Отмечаем все вершины что не прошли
    vector<bool> visited;
    visited.resize(V, false);

    //создаём очередь для BFS
    list<int> queue;

    //Отмечаем текущую вершину пройденной и добавляем в очередь
    visited[s] = true;
    queue.push_back(s);

    while (!queue.empty())
    {
        //убираем из очереди вершину и выводим её
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
        /*Находим все  смежные вершины от удалённой вершины s
        * если вершина ещё не была отмечена как пройденная
        * отмечаем и добавляем в очередь
        */
        for (auto adjacent : adj[s])
        {
            if (!visited[adjacent])
            {
                visited[adjacent] = true;
                queue.push_back(adjacent);
            }
        }
    }
}

int main()
{    
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Breadth First Traversal "
        << "(starting from vertex 2) \n";
    g.BFS(2);

    return 0;
}

