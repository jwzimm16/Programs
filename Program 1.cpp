#include <iostream>
using namespace std;

main()
{
    int Numerator1;
    int Denominator1;
    int Numerator2;
    int Denominator2;

    cout << "FRACTION 1" << endl << endl;
    cout << "Enter the Numerator: ";
    cin >> Numerator1;
    cout << "Enter the Denominator: ";
    cin >> Denominator1;
    cout << endl;

    cout << "FRACTION 2" << endl << endl;
    cout << "Enter the Numerator: ";
    cin >> Numerator2;
    cout << "Enter the Denominator: ";
    cin >> Denominator2;
    cout << endl;

    cout << "RESULTS" << endl << endl;
    cout << Numerator1 << "/" << Denominator1 << " times " << Numerator2 << "/" << Denominator2 << " = ";
    cout << Numerator1 * Numerator2 << "/" << Denominator1 * Denominator2 << endl;

    cout << Numerator1 << "/" << Denominator1 << " divided by " << Numerator2 << "/" << Denominator2 << " = ";
    cout << Numerator1 * Denominator2 << "/" << Numerator2 * Denominator1 << endl;

    cout << Numerator1 << "/" << Denominator1 << " plus " << Numerator2 << "/" << Denominator2 << " = ";
    cout << (Numerator1 * Denominator2) + (Numerator2 * Denominator1) << "/" << Denominator1 * Denominator2 << endl;

    return 0;
}
