#ifndef SKYLARK_QUERY_HPP
#define SKYLARK_QUERY_HPP

// Defines a generic basic queries (Height, Width, etc.) on matrices

namespace skylark { namespace base {

template<typename T>
int Height(const sparse_matrix_t<T>& A) {
    return A.height();
}

template<typename T>
int Width(const sparse_matrix_t<T>& A) {
    return A.width();
}

template<typename T>
int Height(const El::Matrix<T>& A) {
    return A.Height();
}

template<typename T>
int Width(const El::Matrix<T>& A) {
    return A.Width();
}

template<typename T>
int Height(const El::AbstractDistMatrix<T>& A) {
    return A.Height();
}

template<typename T>
int Width(const El::AbstractDistMatrix<T>& A) {
    return A.Width();
}
template<typename T, El::Distribution U, El::Distribution V>
int Height(const El::DistMatrix<T, U, V>& A) {
    return A.Height();
}

template<typename T, El::Distribution U, El::Distribution V>
int Width(const El::DistMatrix<T, U, V>& A) {
    return A.Width();
}

#if 0
#if SKYLARK_HAVE_COMBBLAS

template<typename IT, typename VT>
IT Height(const SpParMat<IT, VT, SpDCCols<IT, VT> >& A) {
    return A.getnrow();
}

template<typename IT, typename VT>
IT Width(const SpParMat<IT, VT, SpDCCols<IT, VT> >& A) {
    return A.getncol();
}

template<typename IT, typename VT>
IT Height(const FullyDistMultiVec<IT, VT>& A) {
    return A.dim;
}

template<typename IT, typename VT>
IT Width(const FullyDistMultiVec<IT, VT>& A) {
    return A.size;
}

#endif // SKYLARK_HAVE_COMBBLAS

#endif

} } // namespace skylark::base

#endif // SKYLARK_QUERY_HPP
