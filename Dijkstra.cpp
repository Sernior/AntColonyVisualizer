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
    Source.tick = timeManager->getTick();
    prev[Source.index] = Source.index;
    Dest.index = Food;
    Dest.cost = INT_MAX;
    Dest.tick = timeManager->getTick();
    prev[Dest.index] = -1;
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
    /*menu->console.pushMessage(std::string("examining x : ").append(std::to_string(map->IndexToTile(curr.index).getPosition().x).append(" y : ").append(
        std::to_string(map->IndexToTile(curr.index).getPosition().y))));*/
    if(curr.index == Dest.index){
        return true;
    }
    for (auto& adj : map->Adj4(curr.index)){
        if(map->isWall(adj))continue;
        CostNode tmp;
        tmp.index = adj;
        tmp.cost = curr.cost + map->GetWeight(adj);
        tmp.tick = timeManager->getTick();
        if (Updated.count(tmp.index)==0||Updated[tmp.index].cost>tmp.cost){
            Updated[tmp.index] = tmp;
            priorityQ.push(tmp);
            prev[adj] = curr.index;
        }
    }
    return false;
}
void Dijkstra::Clear(){
    Updated.clear();
    prev.clear();
    while(!priorityQ.empty()){
        priorityQ.pop();
    }
}

void Dijkstra::RenderPath(){
    int tr = prev[Dest.index];
    while(tr != Source.index){
        map->NotifyPath(tr);
        tr = prev[tr];
    }
}