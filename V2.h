
#ifndef V2_H
#define V2_H

#ifndef V_H
#include "V.h"
#include "V.cpp"
#endif

template <typename eltType, typename scalType> class V2 : public V<eltType, scalType, 2> {

    public:
        V2(const eltType ar[2]) : V<eltType, scalType, 2>(ar) {};
        V2() : V<eltType, scalType, 2>() {};

        const V2<eltType, scalType> operator + (const V2<eltType, scalType>&) const;
        const V2<eltType, scalType> operator * (const scalType&) const;

};

#endif

