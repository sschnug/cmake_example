#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <Eigen/Dense>
#include <Eigen/SparseCore>

#include <iostream>

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

// OKAY BEHAVIOUR -> dense
template <typename ScalarT>
static void take_matrix(const Eigen::Array<ScalarT, Eigen::Dynamic, Eigen::Dynamic> matrix_in, int a) {
  std::cout << "Dense overload" << std::endl;

  if constexpr(std::is_same_v<ScalarT, float>) {
    std::cout << "float" << std::endl;
  }
  else if constexpr(std::is_same_v<ScalarT, double>) {
    std::cout << "double" << std::endl;
  }
  else if constexpr(std::is_same_v<ScalarT, bool>) {
    std::cout << "bool" << std::endl;
  }
  else if constexpr(std::is_same_v<ScalarT, int8_t>) {
    std::cout << "int8_t" << std::endl;
  }
  else if constexpr(std::is_same_v<ScalarT, int16_t>) {
    std::cout << "int16_t" << std::endl;
  }
  else if constexpr(std::is_same_v<ScalarT, int32_t>) {
    std::cout << "int32_t" << std::endl;
  }
  else if constexpr(std::is_same_v<ScalarT, int64_t>) {
    std::cout << "int64_t" << std::endl;
  }
  else if constexpr(std::is_same_v<ScalarT, uint8_t>) {
    std::cout << "uint8_t" << std::endl;
  }
  else if constexpr(std::is_same_v<ScalarT, uint16_t>) {
    std::cout << "uint16_t" << std::endl;
  }
  else if constexpr(std::is_same_v<ScalarT, uint32_t>) {
    std::cout << "uint32_t" << std::endl;
  }
  else if constexpr(std::is_same_v<ScalarT, uint64_t>) {
    std::cout << "uint64_t" << std::endl;
  }
  else 
    std::cout << "some other type" << std::endl;
}

// NOT OKAY BEHAVIOUR -> sparse
template<typename ScalarT, int Options>
static void take_matrix(const Eigen::SparseMatrix<ScalarT, Options> matrix_in, int a) {
  std::cout << "Sparse overload" << std::endl;

  if constexpr(std::is_same_v<ScalarT, float>) {
    std::cout << "float" << std::endl;
  }
  else if constexpr(std::is_same_v<ScalarT, double>) {
    std::cout << "double" << std::endl;
  }
  else if constexpr(std::is_same_v<ScalarT, bool>) {
    std::cout << "bool" << std::endl;
  }
  else if constexpr(std::is_same_v<ScalarT, int8_t>) {
    std::cout << "int8_t" << std::endl;
  }
  else if constexpr(std::is_same_v<ScalarT, int16_t>) {
    std::cout << "int16_t" << std::endl;
  }
  else if constexpr(std::is_same_v<ScalarT, int32_t>) {
    std::cout << "int32_t" << std::endl;
  }
  else if constexpr(std::is_same_v<ScalarT, int64_t>) {
    std::cout << "int64_t" << std::endl;
  }
  else if constexpr(std::is_same_v<ScalarT, uint8_t>) {
    std::cout << "uint8_t" << std::endl;
  }
  else if constexpr(std::is_same_v<ScalarT, uint16_t>) {
    std::cout << "uint16_t" << std::endl;
  }
  else if constexpr(std::is_same_v<ScalarT, uint32_t>) {
    std::cout << "uint32_t" << std::endl;
  }
  else if constexpr(std::is_same_v<ScalarT, uint64_t>) {
    std::cout << "uint64_t" << std::endl;
  }
  else 
    std::cout << "some other type" << std::endl;
}

namespace py = pybind11;

PYBIND11_MODULE(cmake_example, m) {

    // dense
    // -----

    m.def("take_matrix", &take_matrix<bool>, pybind11::arg("matrix_in").noconvert(), pybind11::arg("x"));
    m.def("take_matrix", &take_matrix<float>, pybind11::arg("matrix_in").noconvert(), pybind11::arg("x"));
    m.def("take_matrix", &take_matrix<double>, pybind11::arg("matrix_in").noconvert(), pybind11::arg("x"));

    // sparse
    // ------

    m.def("take_matrix", &take_matrix<bool, Eigen::ColMajor>, pybind11::arg("matrix_in").noconvert(), pybind11::arg("x"));
    m.def("take_matrix", &take_matrix<bool, Eigen::RowMajor>, pybind11::arg("matrix_in").noconvert(), pybind11::arg("x"));

    m.def("take_matrix", &take_matrix<float, Eigen::ColMajor>, pybind11::arg("matrix_in").noconvert(), pybind11::arg("x"));
    m.def("take_matrix", &take_matrix<float, Eigen::RowMajor>, pybind11::arg("matrix_in").noconvert(), pybind11::arg("x"));

    m.def("take_matrix", &take_matrix<double, Eigen::ColMajor>, pybind11::arg("matrix_in").noconvert(), pybind11::arg("x"));
    m.def("take_matrix", &take_matrix<double, Eigen::RowMajor>, pybind11::arg("matrix_in").noconvert(), pybind11::arg("x"));

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
