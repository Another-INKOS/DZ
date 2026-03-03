#pragma once
#ifndef STOCK_H
#define STOCK_H
#include <vector>
class Stock 
{
private:

    struct Box {
        int w;
        int v;
        int id;
    };
    std::vector<Box> boxes;
    int next_id;

public:
    Stock();
    void Add(int w, int v);
    int GetByW(int min_w);
    int GetByV(int min_v);
};
#endif
