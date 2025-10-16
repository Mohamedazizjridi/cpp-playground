#include <iostream>
#include <vector>

class SortingStrategy {
public:
    virtual void sort(std::vector<std::string>& array) = 0;
};

class BubbleSortStrategy : public SortingStrategy {
public:
    void sort(std::vector<std::string>& array) override {
        std::cout << "Sorting using Bubble Sort" << std::endl;
        // Actual Bubble Sort Logic here
    }
};

class MergeSortStrategy : public SortingStrategy {
public:
    void sort(std::vector<std::string>& array) override {
        std::cout << "Sorting using Merge Sort" << std::endl;
        // Actual Merge Sort Logic here
    }
};

class QuickSortStrategy : public SortingStrategy {
public:
    void sort(std::vector<std::string>& array) override {
        std::cout << "Sorting using Quick Sort" << std::endl;
        // Actual Quick Sort Logic here
    }
};

class SortingContext {
private:
    SortingStrategy* sortingStrategy;
public:
    SortingContext(SortingStrategy* sortingStrategy) : sortingStrategy(sortingStrategy) {}

    void setSortingStrategy(SortingStrategy* sortingStrategy) {
        this->sortingStrategy = sortingStrategy;
    }

    void performSort(std::vector<std::string>& array) {
        sortingStrategy->sort(array);
    }
};

int main() {
    std::vector<std::string> array1 = {"cpp","c","java","python3","csharp","html","css","javascript","php","cpp14","cobol","dart","go","julia","kotlin","lisp","matlab","node","objc","perl","r","rust","ruby","scala","swift","solidity","xml"};
    SortingContext sortingContext(new BubbleSortStrategy());
    sortingContext.performSort(array1); // Output: Sorting using Bubble Sort

    sortingContext.setSortingStrategy(new MergeSortStrategy());
    std::vector<std::string> array2 = {"cpp","c","java","python3","csharp","html","css","javascript","php","cpp14","cobol","dart","go","julia","kotlin","lisp","matlab","node","objc","perl","r","rust","ruby","scala","swift","solidity","xml"};
    sortingContext.performSort(array2); // Output: Sorting using Merge Sort

    sortingContext.setSortingStrategy(new QuickSortStrategy());
    std::vector<std::string> array3 = {"cpp","c","java","python3","csharp","html","css","javascript","php","cpp14","cobol","dart","go","julia","kotlin","lisp","matlab","node","objc","perl","r","rust","ruby","scala","swift","solidity","xml"};
    sortingContext.performSort(array3); // Output: Sorting using Quick Sort
    return 0;
}