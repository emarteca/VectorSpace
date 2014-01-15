
#ifndef SYMB_CHECK_REAL_H
#define SYMB_CHECK_REAL_H

#include <string>
#include <vector>

std::vector<std::string> splitBy(char, const std::string&);
std::vector<double> colRemCoeff(std::vector<std::string>& v);
void simpVars(std::vector<std::string>& v, std::vector<double>& c);
bool contains(const std::vector<std::string>& v, const std::string& check, int& index);
void remZeros(std::vector<std::string>& v, std::vector<double>& c);

class SymbCheck_Real {

    public:
        SymbCheck_Real(const std::string& s);
        SymbCheck_Real();
        SymbCheck_Real(int);
        SymbCheck_Real(char);

        bool operator == (const SymbCheck_Real&) const;
        const SymbCheck_Real operator + (const SymbCheck_Real&) const;
        const SymbCheck_Real operator * (const SymbCheck_Real&) const;

        void print() const;
        std::string getRep() const;
        bool isInteger() const;

    private:
        std::vector<std::string> vars;
        std::vector<double> coeffs;

};

#endif
