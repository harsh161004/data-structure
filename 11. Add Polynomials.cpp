#include <iostream>
using namespace std;

struct Term {
    int coefficient;
    int exponent;
};

void addPolynomials(Term p1[], int len1, Term p2[], int len2, Term result[], int& lenResult) {
    int i=0, j=0, k=0;

    while (i < len1 && j < len2) {
        if (p1[i].exponent > p2[j].exponent) {
            result[k] = p1[i];
            i++;
        }
        else if (p1[i].exponent < p2[j].exponent) {
            result[k] = p2[j];
            j++;
        }
        else {
            result[k].coefficient = p1[i].coefficient + p2[j].coefficient;
            result[k].exponent = p1[i].exponent;
            i++;
            j++;
        }
        k++;
    }

    while (i < len1) {
        result[k] = p1[i];
        i++;
        k++;
    }

    while (j < len2) {
        result[k] = p2[j];
        j++;
        k++;
    }

    lenResult = k;
}

int main() {
    Term p1[] = {{3, 2}, {5, 1}, {2, 0}};
    int len1 = 3;

    Term p2[] = {{4, 3}, {2, 1}, {1, 0}};
    int len2 = 3;

    Term result[6];
    int lenResult;

    addPolynomials(p1, len1, p2, len2, result, lenResult);

    cout << "Sum of Polynomials: ";
    for (int i = 0; i < lenResult; i++) {
        cout << result[i].coefficient << "x^" << result[i].exponent;
        if (i < lenResult - 1) {
            cout << " + ";
        }
    }
    cout << endl;

    return 0;
}
