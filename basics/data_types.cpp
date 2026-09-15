#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

int main() {
    int age = 21;
    double temperature = 36.6;
    float pi = 3.14159f;
    char grade = 'A';
    bool is_active = true;

    string name = "Ventie";

    int32_t exact_int = 42;
    uint64_t large_counter = 10000000000ULL;

    cout << "--- Primitive Types ---" << '\n';
    cout << "Name: " << name << '\n';
    cout << "Age: " << age << " (Size: " << sizeof(age) << " bytes)" << '\n';
    cout << "Temperature: " << temperature << " (Size: " << sizeof(temperature) << " bytes)" << '\n';
    cout << "Grade: " << grade << '\n';
    cout << "Is Active: " << std::boolalpha << is_active << '\n';

    cout << "\n--- Fixed-width Integers ---" << '\n';
    cout << "int32_t: " << exact_int << " (Size: " << sizeof(exact_int) << " bytes)" << '\n';
    cout << "uint64_t: " << large_counter << " (Size: " << sizeof(large_counter) << " bytes)" << '\n';

    return 0;
}