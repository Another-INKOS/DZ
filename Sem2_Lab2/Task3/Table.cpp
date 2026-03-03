#include "Table.h"
#include <iostream>

using namespace std;

Table::Table(int r, int c)
    : rows(r),
    cols(c),
    data(r, vector<int>(c, 0))
{

}
int Table::get_value(int row, int col)
{
    return data[row][col];
}
void Table::set_value(int row, int col, int val)
{
    data[row][col] = val;
}
int Table::n_rows() const
{
    return rows;
}
int Table::n_cols() const
{
    return cols;
}
void Table::print()
{

    for (const auto& row : data)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}
double Table::average()
{
    double sum = 0;

    for (const auto& row : data)
    {
        for (int val : row)
        {
            sum += val;
        }
    }
    return sum / (rows * cols);
}
