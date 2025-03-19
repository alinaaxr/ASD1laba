#ifndef GENERATOR_H
#define GENERATOR_H

#include <vector>
#include <iostream>

class Generator {
    std::vector<int> x; // Текущая последовательность
    std::vector<std::vector<int>> sampleResult; // Для хранения всех сгенерированных последовательностей
    int n, k1, k2;
    int count; // Счетчик

public:
    // Конструктор
    Generator(int n, int k1, int k2);

    // Рекурсивная генерация
    void GenerateAllRec(int index, int onesCount);

    // Итеративная генерация
    void GenerateAllIterative();

    // Обертка для рекурсивной генерации
    void GenerateRecursive();

    // Получение количества сгенерированных последовательностей
    int GetCount() const;

    // Получение конкретной сгенерированной последовательности по индексу
    const std::vector<int>& GetResult(int idx) const;

private:
    // Метод для сохранения результата (текущего вектора x)
    void SaveResult();

    // Метод для сохранения переданной последовательности
    void SaveResult(const std::vector<int>& sequence);
};

#endif