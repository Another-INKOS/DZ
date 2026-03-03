
#include "Stock.h"
#include <limits>
#include <cstddef>

using namespace std;

Stock::Stock()
    : next_id(0)
{

}
void Stock::Add(int w, int v) 
{
    boxes.push_back({ w, v, next_id });

    next_id++;
}
int Stock::GetByW(int min_w) 
{
    int best_w = numeric_limits<int>::max();
    int best_id = -1;
    size_t best_idx = static_cast<size_t>(-1);
    for (size_t i = 0; i < boxes.size(); ++i)
    {
        if (boxes[i].w >= min_w) 
        {
            if (boxes[i].w < best_w) 
            {
                best_w = boxes[i].w;
                best_id = boxes[i].id;
                best_idx = i;
            }
            else if (boxes[i].w == best_w && boxes[i].id > best_id) 
            {
                best_id = boxes[i].id;
                best_idx = i;
            }
        }
    }
    if (best_idx == static_cast<size_t>(-1)) 
    {
        return -1;
    }
    int result = boxes[best_idx].id;
    boxes.erase(boxes.begin() + best_idx);
    return result;
}
int Stock::GetByV(int min_v) 
{
    int best_v = numeric_limits<int>::max();
    int best_id = -1;
    size_t best_idx = static_cast<size_t>(-1);
    for (size_t i = 0; i < boxes.size(); ++i) 
    {
        if (boxes[i].v >= min_v) 
        {
            if (boxes[i].v < best_v) 
            {
                best_v = boxes[i].v;
                best_id = boxes[i].id;
                best_idx = i;
            }
            else if (boxes[i].v == best_v && boxes[i].id > best_id) 
            {
                best_id = boxes[i].id;
                best_idx = i;
            }
        }
    }
    if (best_idx == static_cast<size_t>(-1)) 
    {
        return -1;
    }
    int result = boxes[best_idx].id;
    boxes.erase(boxes.begin() + best_idx);

    return result;
}
