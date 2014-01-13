
#include "SymbCheck_Real.h"
#include <iostream>
#include <sstream>

SymbCheck_Real::SymbCheck_Real(const std::string& s) {
    vars = splitBy('+', s);
    coeffs = colRemCoeff(vars);
    simpVars(vars, coeffs);
    remZeros(vars, coeffs);
}

SymbCheck_Real::SymbCheck_Real() { // default is 0
    vars.push_back("1");
    coeffs.push_back(0);
}

SymbCheck_Real::SymbCheck_Real(char c) {
    std::stringstream sstm("");
    sstm << c;
    vars = splitBy('+', sstm.str());
    coeffs = colRemCoeff(vars);
    simpVars(vars, coeffs);
    remZeros(vars, coeffs);
}

SymbCheck_Real::SymbCheck_Real(int val) {
    vars.push_back("1");
    coeffs.push_back(val);
}

bool SymbCheck_Real::operator == (const SymbCheck_Real& scr) const {
    if (scr.vars.size() != vars.size())
        return false;
    for (int i = 0; i < vars.size(); ++ i) {
        int index = i;
        if (!contains(scr.vars, vars[i], index))
            return false;
        else if (coeffs[i] != scr.coeffs[index])
            return false;
    }
    return true;
}

const SymbCheck_Real SymbCheck_Real::operator + (const SymbCheck_Real& scr) const {
    std::string sum = getRep();
    sum += "+" + scr.getRep();

    return SymbCheck_Real(sum);
}

const SymbCheck_Real SymbCheck_Real::operator * (const SymbCheck_Real& scr) const {
    std::stringstream sstm("");
    for (int i = 0; i < vars.size(); ++ i) {
        if (i != 0)
            sstm << "+";
        for (int j = 0; j < scr.vars.size(); ++ j) {
            if (j != 0)
                sstm << "+";
            int cMult = coeffs[i] * scr.coeffs[j];
            if (cMult != 1)
                sstm << cMult << "*";
            sstm << vars[i] << "*" << scr.vars[j];
        }
    }

    return SymbCheck_Real(sstm.str());
}

void SymbCheck_Real::print() const {
    std::cout << "\n";
    for (int i = 0; i < vars.size(); ++ i) {
        if (i != 0)
            std::cout << " + ";
        if (coeffs[i] != 1)
            std::cout << "(" << coeffs[i] << ")";
        std::cout << vars[i];
    }
}

std::string SymbCheck_Real::getRep() const {
    std::stringstream sstm("");
    for (int i = 0; i < vars.size(); ++ i) {
        if (i != 0)
            sstm << "+";
        if (coeffs[i] != 1)
            sstm << coeffs[i] << "*";
        sstm << vars[i];
    }
    return sstm.str();
}

std::vector<std::string> splitBy(char delim, const std::string& toSplit) {
    std::vector<std::string> div;

    std::string temp = "";
    for (int i = 0; i < toSplit.size(); ++ i) {
        if (toSplit[i] != delim)
            temp += toSplit[i];
        if (toSplit[i] == delim || (i == toSplit.size() - 1 && temp != "")) {
            div.push_back(temp);
            temp = "";
        }
    }
    return div;
}

bool SymbCheck_Real::isInteger() const {
    // in this case, the length of the vars vector is 1, and the only value is it is 1
    return (vars.size() == 1 && vars[0] == "1");
}

bool contains(const std::vector<std::string>& v, const std::string& check, int& index) {
    std::vector<std::string> checkSet = splitBy('*', check);
    for (int i = 0; i < v.size(); ++ i) {
        if (v[i] == check) { // simple case
            index = i;
            return true;
        }
        std::vector<std::string> viSet = splitBy('*', v[i]);

        if (checkSet.size() != viSet.size())
            continue;

        bool has = true;
        for (int k = 0; k < checkSet.size(); ++ k) {
            bool hasSet = false;
            for (int j = 0; j < viSet.size(); ++ j) {
                hasSet = (hasSet || (checkSet[k] == viSet[j]));
            }
            has = has && hasSet;
        }

        if (has) {
            index = i;
            return true;
        }
    }
    return false;
}

std::vector<int> colRemCoeff(std::vector<std::string>& v) {
    std::vector<int> coeffs(v.size());

    for (int i = 0; i < v.size(); ++ i) {
        std::vector<std::string> vSplit = splitBy('*', v[i]);
        int curCoeff = 1;
        std::string curVar = "";
        for (int j = 0; j < vSplit.size(); ++ j) {
            std::stringstream sstm(vSplit[j]);
            int val = 0;
            sstm >> val;
            if (sstm.fail()) {
                curCoeff *= 1;
                if (curVar != "")
                    curVar += "*";
                curVar += vSplit[j];
            }
            else
                curCoeff *= val;
        }
        coeffs[i] = curCoeff;
        if (curVar == "")
            curVar = "1";
        v[i] = curVar;
    }

    return coeffs;
}

void simpVars(std::vector<std::string>& v, std::vector<int>& c) {
    // this is to remove duplicates.  the vector should contain a list of all the variables, as a set
    std::vector<std::string> vSet;
    std::vector<int> cSet;
    for (int i = 0; i < v.size(); ++ i) {
        int index = i; // index will be changed to the value of where the value is stored in vSet
        if (!contains(vSet, v[i], index)) {
            vSet.push_back(v[i]);
            cSet.push_back(c[i]);
        }
        else  // value is found at position index
            cSet[index] += c[i];
    }
    v = vSet;
    c = cSet;
}

void remZeros(std::vector<std::string>& v, std::vector<int>& c) {
    std::vector<std::string> vNO;
    std::vector<int> cNO;

    for (int i = 0; i < v.size(); ++ i) {
        if (c[i] != 0) {
            vNO.push_back(v[i]);
            cNO.push_back(c[i]);
        }
    }

    if (vNO.empty()) {
        vNO.push_back("1");
        cNO.push_back(0);
    }
    v = vNO;
    c = cNO;
}
