/**
 * @file main.cpp
 * @brief main function designed to test the vector class.
 * @author
 * @date
 */

#include "vector.hpp"

int main()
{
    Vector v1;

    // Insert testen
    for (int i = 1; i < 10; ++i)
    {
        v1.insert(i, i);
    }

    // Ausgabe (operator<<) testen 
    std::cout << v1 << std::endl;
    // Erwartete Ausgabe:
    // 0 1 2 3 4 5 6 7 8 9

    // Kopierkonstruktor:
    Vector v2(v1); // Ebenso: Vector v2=v1;
    // op= (Zuweisung)
    Vector v3;
    v3 = v2 = v1;

    v1 = v1;

    std::cout << v2 << std::endl;
    std::cout << v3 << '\n' << std::endl;
    // Erwartete Ausgabe:
    // 0 1 2 3 4 5 6 7 8 9
    // 0 1 2 3 4 5 6 7 8 9

    // v1 verändern (Testen von erase())
    v1.erase(0);

    std::cout << std::endl << v1 << std::endl << v2 << std::endl << v3 << std::endl;
    // Erwartete Ausgabe:
    // 1 2 3 4 5 6 7 8 9
    // 0 1 2 3 4 5 6 7 8 9
    // 0 1 2 3 4 5 6 7 8 9

    v2.insert(0, -1);
    std::cout << v2 << std::endl;
    // Erwartete Ausgabe:
    // -1 0 1 2 3 4 5 6 7 8 9

    v2.insert(10, -1);
    std::cout << v2 << std::endl;
    // Erwartete Ausgabe:
    //  -1 0 1 2 3 4 5 6 7 8 -1 9

    v2.insert(15, -1);
    std::cout << v2 << std::endl;
    // Erwartete Ausgabe:
    // -1 0 1 2 3 4 5 6 7 8 -1 9 0 0 0 -1

    v2[14] = -2;
    std::cout << v2 << std::endl;
    // Erwartete Ausgabe: 
    // -1 0 1 2 3 4 5 6 7 8 -1 9 0 0 -2 -1

    sort(v2);
    std::cout << v2 << std::endl;
    return 0;
}