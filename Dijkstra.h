#ifndef DIJKSTRA
#define DIJKSTRA
#include "CostNode.h"
#include<queue>
#include<unordered_map>
class Dijkstra
{
private:
    std::unordered_map<int,CostNode> Updated;
    std::priority_queue<CostNode> priorityQ;
    CostNode Source;
    CostNode Dest;
    bool inited;
public:
    Dijkstra();
    ~Dijkstra();
    bool isInit();
    void init(int Ant, int Food);
    bool Step();//true when destination is reached
};


#endif