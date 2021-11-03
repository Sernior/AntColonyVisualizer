#ifndef COSTNODE
#define COSTNODE
struct CostNode{
    int index;
    int cost;
    int tick;//the time when you were created
    friend bool operator<(const CostNode& x, const CostNode& y){
        if(x.cost==y.cost){
            return x.tick>y.tick;
        }
        return x.cost>y.cost;
    }
};
#endif