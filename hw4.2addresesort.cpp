#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

class Address {
    std::string city;
    std::string street;
    int house;
    int apartment;
public:
    Address(std::string city, std::string street, int house, int apartment) {
        this->city = city;
        this->street = street;
        this->house = house;
        this->apartment = apartment;
    }
    std::string get_output_address() {
        std::string convers = city + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(apartment);
        return convers;
    }
    std::string get_city() {
        return city;
    }
};

void sort(Address* addresses, int size) {
    for (int i = 0; i < size; i++)
        for (int j = i; j < size - 1; j++)
        {
            if (addresses[j].get_city() > addresses[j + 1].get_city()) {
                Address temp = addresses[j];
                addresses[j] = addresses[j + 1];
                addresses[j + 1] = temp;
            }
        }
};

int main()
{
    SetConsoleOutputCP(1251);
    Address** adr;
    int count{};
    std::string city;
    std::string street;
    int house;
    int apartment;
    std::ifstream in{ "in.txt" };
    if (in.is_open()) {
        if (in >> count) {
            adr = new Address * [count];
            for (int i = 0; i < count; ++i) {
                in >> city >> street >> house >> apartment;
                adr[i] = new Address(city, street, house, apartment);
                sort( adr[i], count);
            }

            

            std::ofstream out{ "out.txt" };
            if (out.is_open()) {
                out << count << std::endl;
                for (int i = count - 1; i >= 0; --i) {
                    out << adr[i]->get_output_address() << std::endl;
                }
                out.close();
                for (int i = 0; i < count; ++i) {
                    delete adr[i];
                }
                delete[] adr;
            }
            else {
                std::cout << "Не получилось открыть файл! \"out.txt\"" << std::endl;
            }
        }
        in.close();
    }
    else {
        std::cout << "Не получилось открыть файл! \"in.txt\"" << std::endl;
    }
}