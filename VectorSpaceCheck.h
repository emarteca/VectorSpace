
#ifndef VECTOR_SPACE_CHECK_H
#define VECTOR_SPACE_CHECK_H

template <class VS, const int len> class VectorSpaceCheck {

    public:

        // no constructor b/c default one is ok (this class has no datafields)

        bool checkClosure1() const;
        bool checkClosure2() const;

        bool checkAxiom1() const;
        bool checkAxiom2() const;
        bool checkAxiom3() const;
        bool checkAxiom4() const;
        bool checkAxiom5() const;
        bool checkAxiom6() const;
        bool checkAxiom7() const;
        bool checkAxiom8() const;

        bool checkAllAxioms() const;

        const VS getZeroVector() const; // returns NULL if the 0 vector doesn't exist
};

#endif
