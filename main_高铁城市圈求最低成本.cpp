/**
 * 题目描述
高铁城市圈对人们的出行、经济的拉动效果明显。每年都会规划新的高铁城市圈建设。

在给定：城市数量，可建设高铁的两城市间的修建成本列表、以及结合城市商业价值会固定建设的两城市建高铁。

请你设计算法，达到修建城市高铁的最低成本。

注意，需要满足城市圈内城市间两两互联可达(通过其他城市中转可达也属于满足条件）。

输入描述
第一行，包含此城市圈中城市的数量、可建设高铁的两城市间修建成本列表数量、必建高铁的城市列表。三个数字用空格间隔。
可建设高铁的两城市间的修建成本列表，为多行输入数据，格式为3个数字，用空格分隔，长度不超过1000。
固定要修建的高铁城市列表，是上面参数2的子集，可能为多行，每行输入为2个数字，以空格分隔。
城市id从1开始编号，建设成本的取值为正整数，取值范围均不会超过1000

输出描述
修建城市圈高铁的最低成本，正整数。如果城市圈内存在两城市之间无法互联，则返回-1。

用例
输入	3 3 0
1 2 10
1 3 100
2 3 50
输出	60
说明	3 3 0城市圈数量为3，表示城市id分别为1,2,3
1 2 10城市1，2间的高铁修建成本为10
1 3 100城市1，3间的高铁修建成本为100
2 3 50城市2，3间的高铁修建成本为50
满足修建成本最低，只需要建设城市1，2间，城市2，3间的高铁即可，城市1，3之间可通过城市2中转来互联。这样最低修建成本就是60。

显示详细信息
输入	3 3 1
1 2 10
1 3 100
2 3 50
1 3
输出	110
说明	无

 *
 *使用最小生成树，克鲁斯卡尔算法 求解
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find(int x, vector<int>& parent)
{
    while (parent[x] != x) {
        x = parent[x];
    }
    return x;
}

int unionCount = 0; //标记当前有多少个集合，将连通了高铁的城市加入同一个集合
void join(int x, int y, vector<int>& parent)
{
    int fx = find(x, parent);
    int fy = find(y, parent);
    if (fx != fy) {
        parent[fy] = fx;
        unionCount--;
    }
}

struct Edge {
    int start;
    int end;
    int weight;
    Edge(int start, int end, int weight) : start(start), end(end), weight(weight) {}
};

struct Graph {
    int edgeCount;
    int nodeCount;
    vector<Edge*> edges;
    vector<int> nodes;
};

int main()
{
    int nodeCount;
    int edgeCount;
    int mustBuildCount;
    vector<int> parent;  //用于标记城市加入城市圈的城市id
    parent.push_back(0); //城市id从1开始，所以先填充一个0，以满足最初 parent[i] = i;
    cin >> nodeCount >> edgeCount >> mustBuildCount;
    unionCount = nodeCount;
    if (edgeCount < nodeCount - 1) {
        cout << -1 << endl; //将n个点连通 需要的最小边数是n-1,如果少于该数量则必定不能连通，根据题意返回-1
        return 0;
    }
    Graph graph;
    graph.nodeCount = nodeCount;
    graph.edgeCount = edgeCount;
    for (int i = 0; i < edgeCount; i++) { //根据输入初始化边
        int start, end, weight;
        cin >> start >> end >> weight;
        auto edge = new Edge(start, end, weight);
        graph.edges.push_back(edge);
    }
    
    for (int i = 1; i < nodeCount + 1; i++) { //根据输入初始化点
        parent.push_back(i);
        graph.nodes.push_back(i);
    }

    vector<Edge*> mustBuildEdges;
    for (int i = 0; i < mustBuildCount; i++) {
        int start, end;
        cin >> start >> end;
        int weight = 0;
        int edgeSize = graph.edges.size();
        for (int i = 0; i < edgeSize; i++) {
            auto edge = graph.edges[i];
            if (((edge->start == start) && (edge->end == end)) || ((edge->start == end) && (edge->end == start))) {
                weight = edge->weight;
                break;
            }
        }
        mustBuildEdges.push_back(new Edge(start, end, weight));
    }
    cout << "init end mustBuildCount = " << mustBuildEdges.size() << endl;
    int totalWeight = 0;
    for (int i = 0; i < mustBuildCount; i++) {
        auto edge = mustBuildEdges[i];
        totalWeight += edge->weight;
        join(edge->start, edge->end, parent);
    }
    cout << "unionCount = " << unionCount << endl;
    if (unionCount == 1) { //所有城市都连通了
        cout << totalWeight << endl;
        return 0;
    }
    //完成了必建的城市高铁修建后，未连通所有城市

    //将线段按权重值排序
    sort(graph.edges.begin(), graph.edges.end(),
        [](const Edge* edge1, const Edge* edge2) -> bool { return edge1->weight < edge2->weight; });
    cout << "after sort" << endl;
    for (int i = 0; i < edgeCount; i++) {
        int city1 = graph.edges[i]->start;
        int city2 = graph.edges[i]->end;
        int weight = graph.edges[i]->weight;
        if (find(city1, parent) != find(city2, parent)) {
            totalWeight += weight;
            join(city1, city2, parent);
        }
        if (unionCount == 1) {
            break;
        }
    }

    if (unionCount > 1) {
        cout << -1 << endl;
    } else {
        cout << totalWeight << endl;
    }
    cout << "main end" << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")