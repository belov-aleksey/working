#ifndef RECORD_H
#define RECORD_H

#include <string>
#include <iostream>
#include <iomanip>
#include <map>
#include <fstream>

class Record {
private:
    std::string sport;
    std::string discipline;
    int type; // 1 - World, 2 - European
    int gender; // 1 - Male, 2 - Female
    unsigned int born[3]; // [day, month, year]
    std::string name;
    std::string country;
    double achievement;

public:

    void set_sport(std::string sport_);
    void set_discipline(std::string discipline_);
    void set_type(int type_);
    void set_gender(int gender_);
    void set_born(int day, int month, int year);
    void set_name(std::string name_);
    void set_country(std::string country_);
    void set_achievement(double achievement_);


    void input(std::ifstream &inputFile);
    void print() const;
    void addRecord(Record *&records, int &N); 
    static void printFemaleRecords(Record *records, int N);
    static void countSportRecords(Record *records, int N);
};

#endif // RECORD_H
