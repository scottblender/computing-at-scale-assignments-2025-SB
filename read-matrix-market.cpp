#include "mmio.h"
#include <vector>
#include <cstdlib>

using namespace std;
using std::vector;

typedef vector<vector<int>> Matrix;

Matrix read_matrix_market(const char* filename) {
	MM_typecode matcode;
	FILE* f;
	int M, N, nz; 

	if ((f = fopen(filename, "r")) == nullptr) {
		exit(1);
        	printf("Could not open file.");
    	}

    	// Read the banner
    	if (mm_read_banner(f, &matcode) != 0) {
		exit(1);
        	printf("Could not process Matrix Market banner.");
    	}
	
    	// Read matrix dimensions
    	if (mm_read_mtx_crd_size(f, &M, &N, &nz) != 0) {
        	exit(1);
        	printf("Could not read matrix dimensions.");
    	}

    	// Initialize the matrix
    	Matrix matrix(M, vector<int>(N, 0));

    	// Read the entries
    	for (int i = 0; i < nz; ++i) {
        	int row, col, value;
        	if (fscanf(f, "%d %d %d\n", &row, &col, &value) != 3) {
            		exit(1);
            		printf("Error reading matrix entries.");
        	}
        	matrix[row - 1][col - 1] = value; // Adjust for 1-based indexing
    	}

    	fclose(f);
    	return matrix;
}
