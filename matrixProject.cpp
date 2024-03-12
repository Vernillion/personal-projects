#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Matrix {
    double a11, a12, a21, a22;
};

void get_matrix(string name, Matrix &m) {
    cout << "Please enter values for the matrix " << name << endl;
    cout << "Enter value for Row 1, Column 1: ";
    cin >> m.a11;
    cout << "Enter value for Row 1, Column 2: ";
    cin >> m.a12;
    cout << "Enter value for Row 2, Column 1: ";
    cin >> m.a21;
    cout << "Enter value for Row 2, Column 2: ";
    cin >> m.a22;
}

void calc_sum(const Matrix &m1, const Matrix &m2, Matrix &sum) {
    sum.a11 = m1.a11 + m2.a11;
    sum.a12 = m1.a12 + m2.a12;
    sum.a21 = m1.a21 + m2.a21;
    sum.a22 = m1.a22 + m2.a22;
}

void calc_diff(const Matrix &m1, const Matrix &m2, Matrix &diff) {
    diff.a11 = m1.a11 - m2.a11;
    diff.a12 = m1.a12 - m2.a12;
    diff.a21 = m1.a21 - m2.a21;
    diff.a22 = m1.a22 - m2.a22;
}

void scalar_mult(double K, const Matrix &m, Matrix &k_m) {
    k_m.a11 = K * m.a11;
    k_m.a12 = K * m.a12;
    k_m.a21 = K * m.a21;
    k_m.a22 = K * m.a22;
}

void calc_prod(const Matrix &m1, const Matrix &m2, Matrix &prod) {
    prod.a11 = m1.a11 * m2.a11 + m1.a12 * m2.a21;
    prod.a12 = m1.a11 * m2.a12 + m1.a12 * m2.a22;
    prod.a21 = m1.a21 * m2.a11 + m1.a22 * m2.a21;
    prod.a22 = m1.a21 * m2.a12 + m1.a22 * m2.a22;
}

void calc_inv(const Matrix &m, Matrix &m_inv) {
    double Det = m.a11 * m.a22 - m.a21 * m.a12;
    if (Det == 0) {
        cout << "Matrix is singular, inverse does not exist" << endl;
        return;
    }
    m_inv.a11 = m.a22 / Det;
    m_inv.a12 = (-1 * m.a12) / Det;
    m_inv.a21 = (-1 * m.a21) / Det;
    m_inv.a22 = m.a11 / Det;
}

void print_matrix(const string &name, const Matrix &m) {
    cout << "Matrix " << name << ":" << endl;
    cout << m.a11 << " " << m.a12 << endl;
    cout << m.a21 << " " << m.a22 << endl;
}

int main() {
    int run = 1;
    Matrix m1, m2, sum, diff, k_m, prod, m_inv;
    string m1_name, m2_name;

    cout << "Matrix Calculator - CIS277" << endl;
    cout << "Jae An, Julio Morales, Kenneth Hahn, Nicolas Bozza" << endl;

    while (run == 1) {
        cout << "Please choose an operation" << endl;
        cout << "1. Matrix Addition" << endl;
        cout << "2. Matrix Subtraction" << endl;
        cout << "3. Scalar Multiplication" << endl;
        cout << "4. Matrix Multiplication" << endl;
        cout << "5. Matrix Inversion" << endl;
        
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Matrix 1" << endl;
                get_matrix("m1", m1);
                cout << "Matrix 2" << endl;
                get_matrix("m2", m2);
                calc_sum(m1, m2, sum);
                print_matrix("sum", sum);
                break;
            case 2:
                cout << "Matrix 1" << endl;
                get_matrix("m1", m1);
                cout << "Matrix 2" << endl;
                get_matrix("m2", m2);
                calc_diff(m1, m2, diff);
                print_matrix("diff", diff);
                break;
            case 3:
                double K;
                cout << "Enter scalar value: ";
                cin >> K;
                get_matrix("m1", m1);
                scalar_mult(K, m1, k_m);
                print_matrix("scalar_mult", k_m);
                break;
            case 4:
                cout << "Matrix 1" << endl;
                get_matrix("m1", m1);
                cout << "Matrix 2" << endl;
                get_matrix("m2", m2);
                calc_prod(m1, m2, prod);
                print_matrix("prod", prod);
                break;
            case 5:
                get_matrix("m1", m1);
                calc_inv(m1, m_inv);
                print_matrix("inv", m_inv);
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }

        cout << "Do you want to continue? (1/0): ";
        cin >> run;
    }

    return 0;
}
