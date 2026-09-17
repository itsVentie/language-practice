#include <iostream>
#include <memory>
#include <string>
#include <string_view>
#include <utility>

// Вспомогательная структура для демонстрации RAII и времени жизни объектов в куче
struct Resource {
    int id;
    Resource(int id) : id(id) { std::cout << "  [+] Resource(" << id << ") allocated\n"; }
    ~Resource() { std::cout << "  [-] Resource(" << id << ") destroyed\n"; }
    void do_work() const { std::cout << "  [*] Resource(" << id << ") working...\n"; }
};

// Функция, принимающая string_view — предотвращает ненужную аллокацию памяти
void print_view(std::string_view sv) {
    std::cout << "  string_view value: \"" << sv << "\" (length: " << sv.length() << ")\n";
}

int main() {
    /*
     * ССЫЛКИ И ВКАЗАТЕЛИ 
     *
     * Ссылка (&) - это синтаксический псевдоним (alias) объекта. Не может быть nullptr.
     * Указатель (*) - переменная, хранящая адрес другой переменной в памяти.
     */
    int a = 10;
    int b = 20;

    int& ref = a; // ref ссылается на a
    ref = b;      // ВНИМАНИЕ: Это не меняет ссылку, это присваивает значение b переменной a!

    int* ptr = &a; // ptr хранит адрес переменной a

    std::cout << "--- 1. REFERENCES & POINTERS ---\n";
    std::cout << "a value: " << a << " | Address: " << &a << '\n';
    std::cout << "ref value: " << ref << " | Alias for address: " << &ref << '\n';
    std::cout << "ptr points to address: " << ptr << " | Dereferenced value: " << *ptr << "\n\n";

    /*
     * МОДИФИКАТОРЫ КОНСТАНТНОСТИ ДЛЯ УКАЗАТЕЛЕЙ
     *
     * Порядок чтения справа налево (const оставляет неизменяемым то, что слева от него):
     * const int*     — Указатель на константу (данные нельзя менять, указатель можно).
     * int* const     — Константный указатель (данные менять можно, сам адрес нельзя).
     * const int* const — Константный указатель на константу.
     */
    int val1 = 100;
    int val2 = 200;

    const int* ptr_to_const = &val1;
    // *ptr_to_const = 150; // ОШИБКА КОМПИЛЯЦИИ: данные защищены от записи
    ptr_to_const = &val2;   // ОК: адрес в указателе менять можно

    int* const const_ptr = &val1;
    *const_ptr = 150;       // ОК: данные менять можно
    // const_ptr = &val2;   // ОШИБКА КОМПИЛЯЦИИ: адрес зафиксирован

    std::cout << "--- 2. CONSTNESS WITH POINTERS ---\n";
    std::cout << "Modified val1 via const_ptr: " << val1 << "\n\n";

    /*
     * НEВЛАДЕЮЩИЕ ССЫЛКИ И STRING_VIEW
     *
     * std::string_view (C++17) содержит только указатель на начало строки и её длину.
     * Не делает аллокаций в куче (Zero-allocation view).
     */
    std::cout << "--- 3. NON-OWNING VIEWS (std::string_view) ---\n";
    std::string str = "Dynamic string in Heap";
    const char* c_str = "C-style string literal";

    print_view(str);     // Без копирования буфера
    print_view(c_str);   // Без создания std::string
    print_view("Literal"); // Прямой обзор литерала

    std::cout << "Size of std::string: " << sizeof(str) << " B\n";
    std::cout << "Size of std::string_view: " << sizeof(std::string_view) << " B (ptr + length)\n\n";

    /*
     * СУМАРНЫЕ УМНЫЕ УКАЗАТЕЛИ
     *
     * Управляют ресурсами в куче через концепцию RAII.
     * Автоматически освобождают память при выходе из области видимости.
     */
    std::cout << "--- 4. SMART POINTERS & RAII ---\n";

    {
        // std::unique_ptr — монопольное владение. Скопировать нельзя, можно только переместить (move).
        std::cout << "Creating std::unique_ptr:\n";
        std::unique_ptr<Resource> u_ptr1 = std::make_unique<Resource>(1);
        u_ptr1->do_work();

        // std::unique_ptr<Resource> u_ptr2 = u_ptr1; // ОШИБКА КОМПИЛЯЦИИ: Копирование запрещено
        std::unique_ptr<Resource> u_ptr2 = std::move(u_ptr1); // Передача владения

        if (!u_ptr1) {
            std::cout << "  u_ptr1 is now nullptr after std::move\n";
        }
        u_ptr2->do_work();
    } // Здесь u_ptr2 выходит из области видимости, автоматически вызывается delete

    std::cout << "\nCreating std::shared_ptr and std::weak_ptr:\n";
    std::weak_ptr<Resource> w_ptr;
    {
        // std::shared_ptr — разделяемое владение (подсчет ссылок в Control Block).
        std::shared_ptr<Resource> s_ptr1 = std::make_shared<Resource>(2);
        std::cout << "  s_ptr1 use_count: " << s_ptr1.use_count() << '\n';

        {
            std::shared_ptr<Resource> s_ptr2 = s_ptr1; // Увеличивает счетчик ссылок
            std::cout << "  s_ptr1 use_count inside inner scope: " << s_ptr1.use_count() << '\n';

            w_ptr = s_ptr1; // weak_ptr НЕ увеличивает счетчик владения (предотвращает циклические ссылки)
            std::cout << "  w_ptr expired? " << std::boolalpha << w_ptr.expired() << '\n';
        } // s_ptr2 уничтожается, счетчик уменьшается

        std::cout << "  s_ptr1 use_count after inner scope: " << s_ptr1.use_count() << '\n';
    } // s_ptr1 уничтожается, счетчик становится 0, ресурс удаляется

    std::cout << "  w_ptr expired after outer scope? " << w_ptr.expired() << "\n\n";

    return 0;
}