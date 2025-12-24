#include <iostream>
#include <climits>
#include <cstdlib>
#include <ctime>
using namespace std;
int get_from_interval(int a, int b) {
    return rand() % (b - a + 1) + a;
}
void echo_matrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
}

int** fill_matrix(int n, int a, int b) {
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            matrix[i][j] = get_from_interval(a, b);
        }
    }
    return matrix;
}
void clear_matrix(int**& matrix, int n) {
    if (matrix) {
        for (int i = 0; i < n; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
        matrix = nullptr;
    }
}
void draw_green(int**& matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j > i && j < n - 1 - i) {
                matrix[i][j] = INT_MAX;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j > i && (i + j) > (n - 1)) {
                matrix[i][j] = INT_MIN;
            }
        }
    }
}
pair<int*, int*> find_elements(int** matrix, int n) {
    int* max_negative = nullptr;
    int* min_positive = nullptr;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j > i && j < n - 1 - i && matrix[i][j] < 0) {
                if (!max_negative || matrix[i][j] > *max_negative) {
                    max_negative = &matrix[i][j];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j > i && (i + j) > (n - 1) && matrix[i][j] > 0) {
                if (!min_positive || matrix[i][j] < *min_positive) {
                    min_positive = &matrix[i][j];
                }
            }
        }
    }
    return make_pair(max_negative, min_positive);
}
void swap_elements(int** matrix, pair<int*, int*> elements) {
    if (elements.first && elements.second) {
        swap(*elements.first, *elements.second);
    }
}
int main() {
    srand(time(nullptr));
    int n, a, b;
    cout << "Enter array size: ";
    cin >> n;
    if (n <= 0) {
        cout << "Invalid size!" << endl;
        return 1;
    }
    cout << "Enter interval for values generation [a, b]: ";
    cin >> a >> b;
    if (a > b) {
        swap(a, b);
    }
    int** matrix = fill_matrix(n, a, b);
    cout << "\nOriginal matrix:" << endl;
    echo_matrix(matrix, n);
    auto elements = find_elements(matrix, n);
    swap_elements(matrix, elements);
    cout << "\nAfter swap:" << endl;
    echo_matrix(matrix, n);
    clear_matrix(matrix, n);

    return 0;
}
