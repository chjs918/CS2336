//Jisoo Choi
//CS 2336
//Lab 35

#include <d_matrix.h>

using namespace std;

bool isIdentityMatrix(const matrix<int>& mat) 
{
	for(int i = 0 ; i < mat.rows(); i++){
		for(int j = 0; j < mat.rows() ; j++) {
			if(i == j && mat[i][j] != 1)
				return false;
			if(i != j && mat[i][j] != 0)
				return false;
		}
	}
	return true;
}