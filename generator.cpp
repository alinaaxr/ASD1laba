#include "Generator.h"
#include <stack>
#include <vector>

Generator::Generator(int n, int k1, int k2) : n(n), k1(k1), k2(k2), count(0) {
    x.resize(n);  // Длина вектора x равна n
}

void Generator::GenerateAllRec(int index, int onesCount) {
    if (index == n) {
        if (onesCount >= k1 && onesCount <= k2) {
            SaveResult();
            count++;
        }
        return;
    }
    if (n - index - 1 >= k1 - onesCount) {
        x[index] = 0;
        GenerateAllRec(index + 1, onesCount);
    }

    x[index] = 1;
    if (onesCount + 1 <= k2) {
        GenerateAllRec(index + 1, onesCount + 1);
    }
}

void Generator::GenerateAllIterative() {
    count = 0;
    sampleResult.clear();

    struct State {
        int index;  //позиция в посл-ти
        int onesCount;
        std::vector<int> currentSequence;  //формируемая посл-ть
    };

    std::stack<State> stack;
    stack.push({ 0, 0, std::vector<int>(n) });     //00000...

    while (!stack.empty()) {
        State current = stack.top();
        stack.pop();

        if (current.index == n) {
            if (current.onesCount >= k1 && current.onesCount <= k2) {
                SaveResult(current.currentSequence);
                count++;
            }
            continue;
        }

        if (n - current.index - 1 >= k1 - current.onesCount) {   //если есть место для добавления 1, то добавляем 0
            std::vector<int> nextSequence = current.currentSequence;   //копия текущ посл-ти
            nextSequence[current.index] = 0;
            stack.push({ current.index + 1, current.onesCount, nextSequence });
        }


        if (current.onesCount + 1 <= k2) {  //если кол-во не превышает k2,то добавляем 1
            std::vector<int> nextSequence = current.currentSequence;
            nextSequence[current.index] = 1;
            stack.push({ current.index + 1, current.onesCount + 1, nextSequence });
        }
    }
}

void Generator::GenerateRecursive() {
    count = 0;
    GenerateAllRec(0, 0);
}

int Generator::GetCount() const {
    return count;
}

const std::vector<int>& Generator::GetResult(int idx) const {
    return sampleResult[idx];
}

void Generator::SaveResult() {
    sampleResult.push_back(x);
}

void Generator::SaveResult(const std::vector<int>& sequence) {
    sampleResult.push_back(sequence);
}