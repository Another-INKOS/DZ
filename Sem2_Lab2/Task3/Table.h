#pragma once
#ifndef TABLE_H
#define TABLE_H
#include <vector>

class Table
{
private:
    std::vector<std::vector<int>> data;
    int rows;
    int cols;

public:
    Table(int r, int c);
    int get_value(int row, int col);
    void set_value(int row, int col, int val);

    int n_rows() const;
    int n_cols() const;

    void print();

    double average();
};
#endif
