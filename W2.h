
#ifndef W2_H
#define W2_H

#ifndef V_H
#include "V.h"
#include "V.cpp"
#endif

template <typename eltType, typename scalType> class W2 : public V<eltType, scalType, 2> {

    public:
        W2(const eltType ar[2]) : V<eltType, scalType, 2>(ar) {};
        W2() : V<eltType, scalType, 2>() {};

        const W2<eltType, scalType> operator + (const W2<eltType, scalType>&) const;
        const W2<eltType, scalType> operator * (const scalType&) const;

        const W2<SymbCheck_Real, SymbCheck_Real> getSampleRest() const;

};

#endif
