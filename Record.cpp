#include "Record.h"

void Record::input(std::ifstream &inputFile) {
    inputFile >> sport >> discipline >> type >> gender;
    char dateInput[11];
    inputFile >> dateInput;
    sscanf(dateInput, "%2d.%2d.%4d", &born[0], &born[1], &born[2]);
    inputFile.ignore();
    std::getline(inputFile, name);
    inputFile >> country >> achievement;
}

void Record::print() const {
    std::cout << "Спорт: " << sport << "\n"
              << "Дисциплина: " << discipline << "\n"
              << "Тип: " << (type == 1 ? "World" : "European") << "\n"
              << "Пол: " << (gender == 1 ? "Male" : "Female") << "\n"
              << "Дата рождения: " << born[0] << "." << born[1] << "." << born[2] << "\n"
              << "Имя: " << name << "\n"
              << "Страна: " << country << "\n"
              << "Достижение: " << std::fixed << std::setprecision(2) << achievement << "\n"
              << std::string(40, '-') << "\n"; // Разделитель
}

void Record::addRecord(Record *&records, int &N) {
    Record newRecord;

    // считывание данных для нового рекорда
    std::cout << "Введите вид спорта: ";
    std::cin >> newRecord.sport; 
    std::cout << "Введите дисциплину: ";
    std::cin >> newRecord.discipline;
    std::cout << "Введите тип (1 - Мировой, 2 - Европейский): ";
    std::cin >> newRecord.type;
    std::cout << "Введите пол (1 - Мужской, 2 - Женский): ";
    std::cin >> newRecord.gender;

    std::cout << "Введите дату рождения (ДД.ММ.ГГГГ): ";
    char dateInput[11];
    std::cin >> dateInput;
    sscanf(dateInput, "%2d.%2d.%4d", &newRecord.born[0], &newRecord.born[1], &newRecord.born[2]);

    std::cin.ignore();
    std::cout << "Введите имя: ";
    std::getline(std::cin, newRecord.name);
    std::cout << "Введите страну: ";
    std::getline(std::cin, newRecord.country);
    std::cout << "Введите достижение: ";
    std::cin >> newRecord.achievement;

    // загружаем существующие записи
    Record *tempRecords = nullptr;
    int existingRecordsCount = 0;

    std::ifstream inFile("input.txt");
    if (inFile.is_open()) {
        inFile >> existingRecordsCount; 
        tempRecords = new Record[existingRecordsCount];
        
        for (int i = 0; i < existingRecordsCount; ++i) {
            inFile >> tempRecords[i].sport 
                    >> tempRecords[i].discipline 
                    >> tempRecords[i].type 
                    >> tempRecords[i].gender;

            inFile >> tempRecords[i].born[0]; 
            inFile.ignore(); // Пропускаем разделитель "."
            inFile >> tempRecords[i].born[1];
            inFile.ignore(); // Пропускаем разделитель "."
            inFile >> tempRecords[i].born[2];

            inFile.ignore(); // Пропускаем пробел перед именем
            std::getline(inFile, tempRecords[i].name);
            std::getline(inFile, tempRecords[i].country);
            inFile >> tempRecords[i].achievement;
        }

        inFile.close();
    } else {
        std::cerr << "Не удалось открыть файл для чтения.\n";
        return;
    }

    // Проверяем на дублирование
    bool duplicate = false;
    for (int i = 0; i < existingRecordsCount; ++i) {
        if (tempRecords[i].name == newRecord.name && tempRecords[i].sport == newRecord.sport) {
            duplicate = true;
            break;
        }
    }

    if (!duplicate) {
        // увеличиваем размер массива
        Record *newRecords = new Record[existingRecordsCount + 1];
        for (int i = 0; i < existingRecordsCount; ++i) {
            newRecords[i] = tempRecords[i]; // копирование старых записей
        }
        newRecords[existingRecordsCount] = newRecord; 
        delete[] tempRecords; 

        // запись всеъ записей обратно в файл
        std::ofstream outFile("input.txt", std::ios::trunc);
        if (outFile.is_open()) {
            outFile << existingRecordsCount + 1 << std::endl; 
            for (int i = 0; i <= existingRecordsCount; ++i) {
                outFile << newRecords[i].sport << std::endl
                        << newRecords[i].discipline << std::endl
                        << newRecords[i].type << std::endl
                        << newRecords[i].gender << std::endl
                        << newRecords[i].born[0] << "." 
                        << newRecords[i].born[1] << "." 
                        << newRecords[i].born[2] << std::endl
                        << newRecords[i].name << std::endl
                        << newRecords[i].country << std::endl
                        << std::fixed << std::setprecision(2) 
                        << newRecords[i].achievement << std::endl;
            }

            outFile.close();
        } else {
            std::cerr << "Не удалось открыть файл для записи.\n";
        }

        delete[] newRecords; 
    } else {
        std::cout << "Запись с таким именем и видом спорта уже существует.\n";
        delete[] tempRecords;
    }
}

void Record::printFemaleRecords(Record *records, int N) {
    std::cout << "Рекордсменки:\n";
    for (int i = 0; i < N; ++i) {
        if (records[i].gender == 2) { 
            std::cout << records[i].name << " " 
                      << records[i].achievement << std::endl; 
        }
    }
}

void Record::countSportRecords(Record *records, int N) {
    std::map<std::string, int> sportCount;
    for (int i = 0; i < N; ++i) {
        sportCount[records[i].sport]++;
    }

    std::cout << "Количество рекордов по видам спорта:\n";
    for (const auto& entry : sportCount) {
        std::cout << entry.first << ": " << entry.second << std::endl;
    }
}
