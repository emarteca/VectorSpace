
#include "V.h"
#include <iostream>

template <typename eltType, typename scalType, const int len> V<eltType, scalType, len>::V(const eltType ar[len]) {
    for (int i = 0; i < len; ++ i)
        vect[i] = ar[i];
}

template <typename eltType, typename scalType, const int len> const eltType V<eltType, scalType, len>::operator[](int k) const {
    return vect[k];
}

template <typename eltType, typename scalType, const int len> const V<eltType, scalType, len> V<eltType, scalType, len>::operator +
                                                                                (const V<eltType, scalType, len>& v) const {

    V<eltType, scalType, len> sum(vect);

    for (int i = 0; i < len; ++ i)
        sum.vect[i] = sum.vect[i] + v.vect[i];

    return sum;
}

template <typename eltType, typename scalType, const int len> const V<eltType, scalType, len> V<eltType, scalType, len>::operator *
                                                                                (const scalType& s) const {

    V<eltType, scalType, len> prod(vect);

    for (int i = 0; i < len; ++ i)
        prod.vect[i] = prod.vect[i] * s;

    return prod;
}

template <typename eltType, typename scalType, const int len> void V<eltType, scalType, len>::print() const {
    std::cout << "\n";
    for (int i = 0; i < len; ++ i)
        std::cout << vect[i] << "  ";
}

template <typename eltType, typename scalType, const int len> bool V<eltType, scalType, len>::operator == (const V<eltType, scalType, len>& v) const {
    bool isEqual = true;
    for (int i = 0; i < len; ++ i)
        isEqual = (isEqual && (vect[i] == v[i]));
    return isEqual;
}

template <typename eltType, typename scalType, const int len> const V<SymbCheck_Real, SymbCheck_Real, len> V<eltType, scalType, len>::getSampleRest() const {
    SymbCheck_Real vs[len];
    int curChar = 65;
    for (int i = 0; i < len; ++ i) {
        vs[i] = SymbCheck_Real(static_cast<char>(curChar));
        ++ curChar;
    }

    return V<SymbCheck_Real, SymbCheck_Real, len>(vs);
}
