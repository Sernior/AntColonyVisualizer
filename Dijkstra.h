#ifndef DIJKSTRA
#define DIJKSTRA
#include<queue>
#include<unordered_map>
#include "CostNode.h"
class Dijkstra
{
private:
    std::unordered_map<int,CostNode> Updated;
    std::unordered_map<int,int> prev;
    std::priority_queue<CostNode> priorityQ;
    CostNode Source;
    CostNode Dest;
public:
    bool inited;
    Dijkstra();
    ~Dijkstra();
    bool isInit();
    void init(int Ant, int Food);
    bool Step();//true when destination is reached
    void Clear();
    void RenderPath();
};


#endif