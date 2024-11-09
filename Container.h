#ifndef CONTAINER_H
#define CONTAINER_H
#include <string>
#include <fstream>
#include "Record.h"

using namespace std;
/*
Класс контейнер, содержаший объекты класса Record
Поля:
1. records - массив из Record
2. length - количество элементов в массиве

Методы:
    void addRecord(Record *&records, int &N); 
    static void printFemaleRecords(Record *records, int N);
    static void countSportRecords(Record *records, int N);
*/

class Container {
    private:
        int max_length;
        int existingRecordsCount;
        Record *records;
    public:
        Container(unsigned int max_lt); 
        Container(std::ifstream &inputFile);
        ~Container();

        // TODO: реализовать addRecord по аналогии со старым addRecord
        void addRecord(); 
        void printRecords();
        // void removeRecord(string name); // пока без него
        // void printRecordsToFile(); // часть кода, которая есть в старом addRecord (запись всеъ записей обратно в файл)
        // void printFemaleRecords(); // реализован, но передавать массив и количество элементов не нужно - они будут являться полями этого объекта
        // void countSportRecords();
};

#endif
// Container records(max_length=10); 


// Record Bolt(..,name = "Усэйн Болт");
// records.addRecord(Bolt);
// records.printFemaleRecords();
// records.printRecordsToFile(text_file_name);

// records.removeRecord("Усэйн Болт");

// Records records(file);