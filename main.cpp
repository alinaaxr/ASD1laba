#include "generator.h"
#include <iostream>

int main() {
    setlocale(LC_ALL, "RUS");
    int n = 4;   // Длина последовательности
    int k1 = 2;  // Минимальное количество единиц
    int k2 = 3;  // Максимальное количество единиц

    Generator generator(n, k1, k2);

    std::cout << "Рекурсия:\n";
    generator.GenerateRecursive();

    std::cout << "Кол-во: " << generator.GetCount() << " последовательностей.\n";

    for (int i = 0; i < generator.GetCount(); ++i) {
        const auto& result = generator.GetResult(i);
        for (int num : result) {  //перебор битов
            std::cout << num << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\nНе рекурсия:\n";

    generator.GenerateAllIterative();

    std::cout << "Кол-во: " << generator.GetCount() << " последовательностей.\n";

    for (int i = 0; i < generator.GetCount(); ++i) {
        const auto& result = generator.GetResult(i);
        for (int num : result) {
            std::cout << num << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
