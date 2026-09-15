#include <iostream>
#include <string>
#include <string_view>
#include <cstdint>
#include <optional>

enum class Status {
    Ok = 0,
    Error = 1
};

int main() {
    /*
     * Примитивные целочисленные типы
     *
     * Размеры зависят от архитектуры, но стандарт гарантирует минимальные соотношения:
     * sizeof(char) <= sizeof(short) <= sizeof(int) <= sizeof(long) <= sizeof(long long)
     */
    char c = 'A';                  // Хранит ASCII-код символа (например, 'A' == 65, 1 байт)
    short s = 32767;              // Короткое целое (-32,768 .. 32,767, 2 байта)
    int i = 2147483647;           // 4 байта. Базовое целое (-2^31 .. 2^31 - 1)
    long l = 2147483647L;         // 4 или 8 байт (8 байт на Linux x86_64, 4 байта на Windows x86_64)
    long long ll = 9223372036854775807LL; // 8 байт. Гарантированно 64-битный знаковый инт
    unsigned int ui = 4294967295U; // 4 байта. Беззнаковый инт (только >= 0, диапозон до 2^32 - 1)

    std::cout << "--- 1. PRIMITIVE INTEGRAL TYPES ---\n";
    std::cout << "char:          " << c << " | size: " << sizeof(c) << " B\n";
    std::cout << "short:         " << s << " | size: " << sizeof(s) << " B\n";
    std::cout << "int:           " << i << " | size: " << sizeof(i) << " B\n";
    std::cout << "long:          " << l << " | size: " << sizeof(l) << " B\n";
    std::cout << "long long:     " << ll << " | size: " << sizeof(ll) << " B\n";
    std::cout << "unsigned int:  " << ui << " | size: " << sizeof(ui) << " B\n\n";

    /*
     * FIXED-WIDTH INTEGERS (<cstdint>)
     *
     * Гарантируют фиксированный размер в битах НА ЛЮБОЙ платформе и Ос
     */
    std::int8_t i8 = -128;          // 8-битный знаковый инт (-128 .. 127)
    std::uint8_t u8 = 255;          // 8-битный беззнаковый инт / байт (0 .. 255)
    std::int32_t i32 = -2147483648; // 32-битный знаковый инт
    std::uint64_t u64 = 18446744073709551615ULL; // 64-битный беззнаковый инт
    std::size_t size = 1024;        // Беззнаковый тип для размеров объектов/индексов (8 B на 64-бит)
    std::uintptr_t ptr_val = 0;     // Беззнаковый инт, равный по размеру адресной шине (для работы с адресами)

    std::cout << "--- 2. FIXED-WIDTH INTEGERS (<cstdint>) ---\n";
    std::cout << "int8_t:        " << static_cast<int>(i8) << " | size: " << sizeof(i8) << " B\n";
    std::cout << "uint8_t:       " << static_cast<int>(u8) << " | size: " << sizeof(u8) << " B\n";
    std::cout << "int32_t:       " << i32 << " | size: " << sizeof(i32) << " B\n";
    std::cout << "uint64_t:      " << u64 << " | size: " << sizeof(u64) << " B\n";
    std::cout << "size_t:        " << size << " | size: " << sizeof(size) << " B\n";
    std::cout << "uintptr_t:     " << ptr_val << " | size: " << sizeof(ptr_val) << " B\n\n";

    /*
     * Числа с плавающей точкой
     */
    float f = 3.14159f;                   // Одинарная точность (~7 значащих цифр, 4 байта)
    double d = 3.141592653589793;         // Двойная точность (~15-17 значащих цифр, 8 байт)
    long double ld = 3.14159265358979323846L; // Расширенная точность (зависит от компилятора, 8-16 байт)

    std::cout << "--- 3. FLOATING-POINT TYPES ---\n";
    std::cout << "float:         " << f << " | size: " << sizeof(f) << " B\n";
    std::cout << "double:        " << d << " | size: " << sizeof(d) << " B\n";
    std::cout << "long double:   " << ld << " | size: " << sizeof(ld) << " B\n\n";

    /*
     * BOOLEAN & NULLPTR
     */
    bool flag = true;                   // Логический тип (true / false, 1 байт)
    std::nullptr_t null_type = nullptr; // Собственный тип ключевого слова nullptr для нулевых указателей

    std::cout << "--- 4. BOOLEAN & NULLPTR ---\n";
    std::cout << "bool:          " << std::boolalpha << flag << " | size: " << sizeof(flag) << " B\n";
    std::cout << "nullptr_t:     size: " << sizeof(null_type) << " B\n\n";

    /*
     * Строковые типы
     */
    std::string str = "Hello World";    // Динамическая строка. Владеет буфером памяти в куче (heap)
    std::string_view sv = str;          // Невладеющая "ссылка" на строку (указатель + длина). Без аллокаций

    std::cout << "--- 5. TEXT & STRINGS ---\n";
    std::cout << "std::string:   \"" << str << "\" | size: " << sizeof(str) << " B\n";
    std::cout << "string_view:   \"" << sv << "\" | size: " << sizeof(sv) << " B\n\n";

    /*
     * Составные типы и утилиты
     */
    int value = 42;
    int* ptr = &value;                 // Указатель: хранит адрес переменной в оперативной памяти
    int& ref = value;                  // Ссылка: псевдоним (alias) для существующей переменной
    Status status = Status::Ok;        // enum class: Строго типизированное перечисление
    std::optional<int> opt = 100;      // Контейнер, который может либо содержать значение, либо быть пустым

    std::cout << "--- 6. COMPOUND & UTILITY TYPES ---\n";
    std::cout << "Pointer (int*):     Address=" << ptr << " | Value=" << *ptr << " | size: " << sizeof(ptr) << " B\n";
    std::cout << "Reference (int&):   Value=" << ref << '\n';
    std::cout << "enum class:         Value=" << static_cast<int>(status) << '\n';
    std::cout << "std::optional:      HasValue=" << opt.has_value() << " | Value=" << *opt << '\n';

    return 0;
}