    python3 -m pip install .
    python3 -m pytest


    tests/test_basic.py Dense matrix @ python
    [[1. 2. 3. 4.]
    [5. 6. 7. 8.]]
    float32

    Sparse matrix @ python
      (0, 0)        1.0
      (0, 1)        2.0
      (0, 2)        3.0
      (0, 3)        4.0
      (1, 0)        5.0
      (1, 1)        6.0
      (1, 2)        7.0
      (1, 3)        8.0
    float32

    CALL instantiation -> with dense => c++ receives type?
    Dense overload
    float
    CALL instantiation -> with sparse => c++ receives type?
    Sparse overload
    bool

Why `float vs. bool`?