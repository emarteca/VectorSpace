
#include "V2.h"

template <typename eltType, typename scalType> const V2<eltType, scalType> V2<eltType, scalType>::operator +
                                                                                (const V2<eltType, scalType>& v) const {

    V2<eltType, scalType> sum(this->vect);

    for (int i = 0; i < 2; ++ i)
        sum.vect[i] = sum.vect[i] + v.vect[i];

    return sum;
}

template <typename eltType, typename scalType> const V2<eltType, scalType> V2<eltType, scalType>::operator *
                                                                                (const scalType& s) const {

    V2<eltType, scalType> prod(this->vect);

    for (int i = 0; i < 2; ++ i)
        prod.vect[i] = prod.vect[i] * s;

    return prod;
}
