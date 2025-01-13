#include <iostream>
#include "matrix-matrix-product.hpp"

using namespace std;

int main() {
    // Define matrices A and B
    Matrix m1 = {
        {1, 2},
        {3, 4}
    };
    Matrix m2 = {
        {5, 6},
        {7, 8}
    };

    // Multiply matrices
    Matrix result = matrix_matrix_product(m1, m2);

    // Output the result
    cout << "Resultant matrix:" << endl;
    for (const auto& row : result) {
        for (int val : row) {
		cout << val << " ";
        }
	cout << endl;
    }

    return 0;
}
