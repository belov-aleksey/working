#include <iostream>
#include "Record.h"
#include "Container.h"

int main(){

    // Container records(10);
    // records.addRecord();
    // records.printRecords();

    std::ifstream inputFile("input.txt");
    Container records(inputFile);
    records.printRecords();
    inputFile.close();
    return 0;
}