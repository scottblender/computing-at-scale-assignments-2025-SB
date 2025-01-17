#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include "mmio.h"
using namespace std;

typedef vector<vector<double>> Matrix;

void write_matrix_market(const Matrix& res){
	if (res.empty() || res[0].empty()) {
        	cerr << "Matrix is empty or uninitialized!" << endl;
        	return;
    	}
	MM_typecode matcode;
	int rows = res.size();
	int columns =  res[0].size();
	int nz = 0;	
	cout << "Matrix dimensions: " << rows << " x " << columns << endl;
	mm_initialize_typecode(&matcode);
    	mm_set_matrix(&matcode);
    	mm_set_coordinate(&matcode);
    	mm_set_real(&matcode);


	for (const auto& row : res) {
        	for (double value : row) {
            		if (value != 0.0) {
                		nz+=1;
            		}
        	}
    	}
	cout << "Non-zero count: " << nz << endl;
	mm_write_banner(stdout, matcode);
	mm_write_mtx_crd_size(stdout, rows, columns, nz);
	for (int i = 0; i < rows; ++i) {
        	for (int j = 0; j < columns; ++j) {
            		if (res[i][j] != 0.0) {
                		fprintf(stdout, "%d %d %10.3g\n", i + 1, j + 1, res[i][j]); 
			}
		}
	}

}
