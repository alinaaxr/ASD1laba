#define CATCH_CONFIG_MAIN
#include "catch.h"
#include "generator.h"
#include <vector>
#include <algorithm>

TEST_CASE("Тест на совпадение посл-тей по количеству", "[generator]") {
    int n = 4;
    int k1 = 2;
    int k2 = 3;

    // Создаем экземпляры генератора для рекурсивного и нерекурсивного подхода
    Generator generatorRecursive(n, k1, k2);
    Generator generatorIterative(n, k1, k2);

    // Генерация последовательности
    generatorRecursive.GenerateRecursive();
    generatorIterative.GenerateAllIterative();

    int countRecursive = generatorRecursive.GetCount();
    int countIterative = generatorIterative.GetCount();

    REQUIRE(countRecursive == countIterative);
}

TEST_CASE("Тест на содержимое", "[generator]" /*тег для тестового кейса*/) {
    int n = 4;
    int k1 = 2;
    int k2 = 3; 

    Generator generatorRecursive(n, k1, k2);
    Generator generatorIterative(n, k1, k2);

    generatorRecursive.GenerateRecursive();
    generatorIterative.GenerateAllIterative();

  
    std::vector<std::vector<int>> resultsRecursive; //хранят сгенерированные посл-ти
    std::vector<std::vector<int>> resultsIterative;

    for (int i = 0; i < generatorRecursive.GetCount(); ++i) {
        resultsRecursive.push_back(generatorRecursive.GetResult(i));
    }

    for (int i = 0; i < generatorIterative.GetCount(); ++i) {
        resultsIterative.push_back(generatorIterative.GetResult(i));
    }

   
    if (!resultsRecursive.empty()) {
        const auto& expectedSequence = resultsRecursive[0]; //проверка первых сгенер. посл-тей
        const auto& actualSequence = resultsIterative[0];

        REQUIRE(expectedSequence == actualSequence);
    }
}

TEST_CASE("Тест на сравнение наборов", "[generator]") {
    int n = 4; 
    int k1 = 2; 
    int k2 = 3; 

    Generator generatorRecursive(n, k1, k2);
    Generator generatorIterative(n, k1, k2);

    generatorRecursive.GenerateRecursive();
    generatorIterative.GenerateAllIterative();

    std::vector<std::vector<int>> resultsRecursive;
    std::vector<std::vector<int>> resultsIterative;

    for (int i = 0; i < generatorRecursive.GetCount(); ++i) {
        resultsRecursive.push_back(generatorRecursive.GetResult(i));
    }

    for (int i = 0; i < generatorIterative.GetCount(); ++i) {
        resultsIterative.push_back(generatorIterative.GetResult(i));
    }

    std::sort(resultsRecursive.begin(), resultsRecursive.end());
    std::sort(resultsIterative.begin(), resultsIterative.end());

    REQUIRE(resultsRecursive == resultsIterative); // Проверяем, что результаты одинаковы
}
