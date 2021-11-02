#include "Dijkstra.h"
#include "Globals.h"

Dijkstra::Dijkstra() {
    inited=false;
}
Dijkstra::~Dijkstra() {
    
}
bool Dijkstra::isInit(){
    return inited;
}
void Dijkstra::init(int Ant, int Food){
    Source.index = Ant;
    Source.cost = 0;
    Dest.index = Food;
    Dest.cost = INT_MAX;
    priorityQ.push(Source);
    Updated[Source.index] = Source;
    inited = true;
}
bool Dijkstra::Step() {
    CostNode curr = priorityQ.top();
    priorityQ.pop();
    while(Updated.count(curr.index)!=0 && Updated[curr.index].cost!=curr.cost){
        curr = priorityQ.top();
        priorityQ.pop();
    }
    map->NotifyTileFound(curr.index);
    printf("%d ",curr.index);
    menu->console.pushMessage(std::string("examining : ").append(std::to_string(curr.index)));
    if(curr.index == Dest.index){
        return true;
    }
    for (auto& adj : map->Adj4(curr.index)){
        CostNode tmp;
        tmp.index = adj;
        tmp.cost = curr.cost + map->GetWeight(adj);
        if (Updated.count(tmp.index)==0||Updated[tmp.index].cost>tmp.cost){
            Updated[tmp.index] = tmp;
            priorityQ.push(tmp);
        }
    }
    return false;
}
