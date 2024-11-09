#include <iostream>
#include "Record.h"

int main() {
    std::setlocale(LC_ALL, "ru_RU.UTF-8");
    std::ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Ошибка при открытии файла!" << std::endl;
        return 1;
    }

    int N;
    inputFile >> N;
    Record *records = new Record[N];

    for (int i = 0; i < N; i++) {
        records[i].input(inputFile);
    }

    inputFile.close();
    int choice;

    do {
        for (int i = 0; i < N; ++i) {
            records[i].print();
        }
        std::cout << "Выберите действие:\n";
        std::cout << "1 - Добавить нового рекордсмена\n";
        std::cout << "2 - Вывести рекорды женщин\n";
        std::cout << "3 - Посчитать количество рекордов по видам спорта\n";
        std::cout << "4 - Завершить программу\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;

        if (choice == 1) {
            std::ofstream outFile("input.txt", std::ios::out | std::ios::app);

if (!outFile) {
    std::cerr << "Ошибка открытия файла!" << std::endl;
    return 1;
}

records[N].addRecord(records, N); 


outFile.close(); 
        } else if (choice == 2) {
            Record::printFemaleRecords(records, N);
        } else if (choice == 3) {
            Record::countSportRecords(records, N);
        }

    } while (choice != 4);

    delete[] records; 
    return 0;
}
