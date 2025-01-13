#include <vector>

using std::vector;
typedef vector<vector<int>> Matrix;

Matrix matrix_matrix_product(const Matrix& m1, const Matrix& m2){
	int a = m1.size();
	int b = m1[0].size();
	int c = m2[0].size();
	Matrix m3(a, vector<int>(c));

	for (int i = 0; i < a; ++i){
		for (int j = 0; j < c; ++j) {
			int sum = 0;
			for (int k = 0; k < c; ++k) {
				sum = sum + m1[i][k]*m2[k][j];
			}
			m3[i][j] = sum;
		}
	}
	return m3;
}
