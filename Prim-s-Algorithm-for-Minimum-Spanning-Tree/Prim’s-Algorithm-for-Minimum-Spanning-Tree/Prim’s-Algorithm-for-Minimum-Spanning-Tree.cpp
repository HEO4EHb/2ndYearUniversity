#include <iostream>
using namespace std;

// Number of vertices in the graph
#define V 5

// функция для нахождения вершины с минимальным весом, из всех вершин
// не включенных в Минимальное остовное дерево
int minKey(int key[], bool mstSet[])
{
    // минимальное значение 
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

//Вспомогательная функция для печати построенного МОД, хранящегося в parent[]
void printMST(int parent[], int graph[V][V])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t"
        << graph[i][parent[i]] << " \n";
}

// Функция построения и печати MST для
// графа представленного с помощью матрицы смежности
void primMST(int graph[V][V])
{
    // Массив для хранения составленного МОД
    int parent[V];

    // значения чтобы получить минмальный вес
    int key[V];

    // значения для обозначения вершин включенных в МОД
    bool mstSet[V];

    // делаем все значения бесконечным 
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    // 1-я вершина всегда в МОД
    // key 0 чтобы эта вершина всегда была первой 
    // 
    key[0] = 0;

    // первая вершина всегда корень МОД
    parent[0] = -1;

    // у МОД V вершин
    for (int count = 0; count < V - 1; count++) {

        // берём самую "маленькую" веришну не из МОД
        
        int u = minKey(key, mstSet);

        // добавляем её в МОД
        mstSet[u] = true;

        //обновляем значение и иднекс родителя смешных вершин для данной вершины        
        // рассматриваем только те вершины что не включены в МОД
        
        for (int v = 0; v < V; v++)

            // граф[u][v] не нулевой только для смежных вершин из МОД и нулевой для тех что не включенны в МОД
            // обновеляем key[u][v] тоглько когда граф меньше key[v]            
            if (graph[u][v] && mstSet[v] == false
                && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    // вывод составленного МОД
    printMST(parent, graph);
}


int main()
{
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };

    // вывод решения 
    primMST(graph);

    return 0;
}