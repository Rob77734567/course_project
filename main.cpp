#include <iostream>
#include "json_parser.h"

int main(){
    std::string json = R"(
    {
        "name": "John",
        "age": 49,
        "is_student": false,
        "grades": [5, 4, 3, 5],
        "address": {
            "city": "Tomsk",
            "street": "Lenina"
        }
    }
    )";

    std::cout << "Parse JSON:\n";
    parseAndPrintJSON(json);

    return 0;
}
