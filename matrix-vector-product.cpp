#include <vector>

using std::vector;

typedef vector<vector<int>> Matrix;
typedef vector<int> Vector;

Vector matrix_vector_product(const Matrix& m1, const Vector& v1){
	int n = m1.size();
	int m = m1[0].size();
	Vector v2(n);

	for (int i = 0; i < n; ++i){
		int sum = 0;
		for (int j = 0; j < m; ++j){
			sum = sum + m1[i][j] * v1[j];
		}
		v2[i] = sum;
	}
	return v2;
}
