
#ifndef V_H
#define V_H

#include "SymbCheck_Real.h"

template <typename eltType, typename scalType, const int len> class V {

    public:
        V(const eltType ar[len]);
        V() {};

        const V<eltType, scalType, len> operator + (const V<eltType, scalType, len>&) const;
        const V<eltType, scalType, len> operator * (const scalType&) const;
        const eltType operator[](int k) const;
        bool operator == (const V<eltType, scalType, len>&) const;

        void print() const;

        const V<SymbCheck_Real, SymbCheck_Real, len> getSampleRest() const;

    protected:
        eltType vect[len];

};

#endif


