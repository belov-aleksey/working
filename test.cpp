#include <iostream>
#include "Record.h"
#include "Container.h"

int main(){
    // Record record1;
    // Record record2;
    // Container records(10);
    // records.addRecord(record1);
    // records.printRecords();

    std::ifstream inputFile("input.txt");
    Container records(inputFile);
    records.printRecords();
    return 0;
}