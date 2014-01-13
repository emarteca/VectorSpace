
#include "VectorSpaceCheck.h"
#include "SymbCheck_Real.h"
#include <iostream>

template <class VS, const int len> bool VectorSpaceCheck<VS, len>::checkAxiom1() const {
    SymbCheck_Real v1s[len], v2s[len];
    int curChar = 65;
    for (int i = 0; i < len; ++ i) {
        v1s[i] = SymbCheck_Real(static_cast<char>(curChar));
        v2s[i] = SymbCheck_Real(static_cast<char>(curChar + 1));
        curChar += 2;
    }

    VS v1(v1s), v2(v2s);

    VS LS = v1 + v2;
    VS RS = v2 + v1;

    return (LS == RS);
}

template <class VS, const int len> bool VectorSpaceCheck<VS, len>::checkAxiom2() const {
    SymbCheck_Real v1s[len], v2s[len], v3s[len];
    int curChar = 65;
    for (int i = 0; i < len; ++ i) {
        v1s[i] = SymbCheck_Real(static_cast<char>(curChar));
        v2s[i] = SymbCheck_Real(static_cast<char>(curChar + 1));
        v3s[i] = SymbCheck_Real(static_cast<char>(curChar + 2));
        curChar += 3;
    }

    VS v1(v1s), v2(v2s), v3(v3s);

    VS LS = (v1 + v2) + v3;
    VS RS = v1 + (v2 + v3);

    return (LS == RS);
}

template <class VS, const int len> bool VectorSpaceCheck<VS, len>::checkAxiom3() const {
    SymbCheck_Real vs[len];
    int curChar = 65;
    for (int i = 0; i < len; ++ i) {
        vs[i] = SymbCheck_Real(static_cast<char>(curChar));
        ++ curChar;
    }

    VS v(vs);

    VS z = v + v * (-1);
    bool isInt = true;
    for (int i = 0; i < len; ++ i)
        isInt = (isInt && z[i].isInteger());

    return isInt;
}

template <class VS, const int len> const VS VectorSpaceCheck<VS, len>::getZeroVector() const {
    if (!checkAxiom3())
        return NULL; // if the 0 vector does not exist, return NULL

    SymbCheck_Real vs[len];
    int curChar = 65;
    for (int i = 0; i < len; ++ i) {
        vs[i] = SymbCheck_Real(static_cast<char>(curChar));
        ++ curChar;
    }

    VS v(vs);

    return v + v * (-1);

}

template <class VS, const int len> bool VectorSpaceCheck<VS, len>::checkAxiom4() const {
    SymbCheck_Real vs[len];
    int curChar = 65;
    for (int i = 0; i < len; ++ i) {
        vs[i] = SymbCheck_Real(static_cast<char>(curChar));
        ++ curChar;
    }

    VS v(vs);

    return (v + v * (-1) == getZeroVector());

}

template <class VS, const int len> bool VectorSpaceCheck<VS, len>::checkAxiom5() const {
    SymbCheck_Real v1s[len], v2s[len];
    int curChar = 65;
    for (int i = 0; i < len; ++ i) {
        v1s[i] = SymbCheck_Real(static_cast<char>(curChar));
        v2s[i] = SymbCheck_Real(static_cast<char>(curChar + 1));
        curChar += 2;
    }

    SymbCheck_Real s(static_cast<char>(curChar));

    VS v1(v1s), v2(v2s);

    VS LS = (v1 + v2) * s;
    VS RS = v1 * s + v2 * s;

    return (LS == RS);
}

template <class VS, const int len> bool VectorSpaceCheck<VS, len>::checkAxiom6() const {
    SymbCheck_Real vs[len];
    int curChar = 65;
    for (int i = 0; i < len; ++ i) {
        vs[i] = SymbCheck_Real(static_cast<char>(curChar));
        ++ curChar;
    }

    SymbCheck_Real s1(static_cast<char>(curChar)), s2(static_cast<char>(++ curChar));

    VS v(vs);

    VS LS = v * (s1 + s2);
    VS RS = v * s1 + v * s2;

    return (LS == RS);
}

template <class VS, const int len> bool VectorSpaceCheck<VS, len>::checkAxiom7() const {
    SymbCheck_Real vs[len];
    int curChar = 65;
    for (int i = 0; i < len; ++ i) {
        vs[i] = SymbCheck_Real(static_cast<char>(curChar));
        ++ curChar;
    }

    SymbCheck_Real s1(static_cast<char>(curChar)), s2(static_cast<char>(++ curChar));

    VS v(vs);

    VS LS = v * (s1 * s2);
    VS RS = (v * s1) * s2;

    return (LS == RS);
}

template <class VS, const int len> bool VectorSpaceCheck<VS, len>::checkAxiom8() const {
    SymbCheck_Real vs[len];
    int curChar = 65;
    for (int i = 0; i < len; ++ i) {
        vs[i] = SymbCheck_Real(static_cast<char>(curChar));
        ++ curChar;
    }

    SymbCheck_Real s1(1);

    VS v(vs);

    VS LS = v * s1;
    VS RS = v;

    return (LS == RS);
}

template <class VS, const int len> bool VectorSpaceCheck<VS, len>::checkAllAxioms() const {
    return checkAxiom1() && checkAxiom2() && checkAxiom3() && checkAxiom4() && checkAxiom5()
            && checkAxiom6() && checkAxiom7() && checkAxiom8();
}
