template <class T>
extern T Sum(const T& a, const T& b);

// 1. перенос объявления функции в sum.h

// template <class T>
// T Sum(const T& a, const T& b) {
//     return a + b;
// }

// 2. extern + sum_impl.cpp
