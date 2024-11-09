#include <iostream>
#include "Record.h"
#include "Container.h"

int main(){
    std::setlocale(LC_ALL, "ru_RU.UTF-8");
    // Container records(10);
    // records.addRecord();
    // records.printRecords();

    std::ifstream inputFile("input.txt");
    Container records(inputFile);
    records.printRecords();
    inputFile.close();
    return 0;
}