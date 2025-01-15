#include <iostream>
#include <vector>
#include "matrix-matrix-product.hpp"
#include "matrix-vector-product.hpp"
#include "read-matrix-market.hpp"

using namespace std;
typedef vector<vector<int>> Matrix;
typedef vector<int> Vector;

int main(int argc, char* argv[]) {
    const char* file1 = argv[1];
    const char* file2 = argv[2];
    int operation_type = atoi(argv[3]);

    if (operation_type == 1){
    	Matrix m1 = read_matrix_market(file1);
	cout << "Matrix 1 loaded." << endl;
        Matrix m2 = read_matrix_market(file2);
	cout << "Matrix 2 loaded." << endl;

        Matrix result = matrix_matrix_product(m1, m2);
	
	// Output the result
    	cout << "Resultant matrix:" << endl;
    	for (const auto& row : result) {
        	for (int val : row) {
			cout << val << " ";
        	}
		cout << endl;
    	}
    }
    return 0;
}
