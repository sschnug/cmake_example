import cmake_example as m
import numpy as np
import scipy as sp

def test_main():
    assert m.__version__ == "0.0.1"

    matrix = np.array(
        [
            [1, 2, 3, 4],
            [5, 6, 7, 8]
        ], dtype=np.float32
    )
    print('Dense matrix @ python')
    print(matrix)
    print(matrix.dtype)
    print()

    # -----

    sparse_matrix = sp.sparse.coo_array(matrix)
    print('Sparse matrix @ python')
    print(sparse_matrix)
    print(sparse_matrix.dtype)
    print()

    # -----

    print('CALL instantiation -> with dense => c++ receives type?')
    m.take_matrix(matrix, True)
    print('CALL instantiation -> with sparse => c++ receives type?')
    m.take_matrix(sparse_matrix, True)