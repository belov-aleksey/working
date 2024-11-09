#include "Container.h"
#include <iostream>

Container::Container(unsigned int max_lt)
{
    max_length = max_lt;
    records = new Record[max_length];
    existingRecordsCount = 0;
    cout << "\nВызван конструктор класса Container";
}

Container::Container(std::ifstream &inputFile)
{
    int max_lt;
    inputFile >> max_lt;
    max_length = max_lt;
    records = new Record[max_length];
    existingRecordsCount = 0;
    cout << "\nВызван конструктор класса Container с чтением из файла" << endl;
    for(int i = 0; i < max_lt; i++){
        records[i].input(inputFile);
        existingRecordsCount++;
    }
    cout << "Считано " << existingRecordsCount << " рекордсменов" << endl;
}

Container::~Container()
{
    max_length = 0;
    delete[] records;
    existingRecordsCount = 0;
    cout << "\nВызван деструктор класса Container";
}


void Container::addRecord()
{
    Record newRecord;

    // считывание данных для нового рекорда
    std::cout << "Введите вид спорта: ";
    string sport;
    std::cin >> sport;
    newRecord.set_sport(sport); 
    std::cout << "Введите дисциплину: ";
    string discipline;
    std::cin >> discipline;
    newRecord.set_discipline(discipline);
    std::cout << "Введите тип (1 - Мировой, 2 - Европейский): ";
    int type;
    std::cin >> type;
    newRecord.set_type(type);
    std::cout << "Введите пол (1 - Мужской, 2 - Женский): ";
    int gender;
    std::cin >> gender;
    newRecord.set_gender(gender);

    std::cout << "Введите дату рождения (ДД.ММ.ГГГГ): ";
    char dateInput[11];
    std::cin >> dateInput;
    int day, month, year;
    sscanf(dateInput, "%2d.%2d.%4d", &day,&month, &year);
    newRecord.set_born(day, month, year);
    std::cin.ignore();

    std::cout << "Введите имя: ";
    std::string name;
    std::getline(std::cin, name);
    newRecord.set_name(name);

    std::cout << "Введите страну: ";
    string country;
    std::getline(std::cin, country);
    newRecord.set_country(country);

    std::cout << "Введите достижение: ";
    double achievement;
    std::cin >> achievement;
    newRecord.set_achievement(achievement);

    if (existingRecordsCount < max_length){
        records[existingRecordsCount] = newRecord;
        existingRecordsCount++;
    }
    // Обновить N в текстовом файле (первая строка)
    // И добавить в конец текстового файла нового рекордсмена
}

void Container::printRecords(){
    for (int i = 0; i < existingRecordsCount; i++){
        records[i].print();
    }
}
