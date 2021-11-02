#ifndef COSTNODE
#define COSTNODE
struct CostNode{
    int index;
    int cost;
    friend bool operator<(const CostNode& x, const CostNode& y){
        return x.cost>y.cost;
    }
};
#endif