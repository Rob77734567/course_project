#include "Json_parser.h"
#include <iostream>
#include <string>

void parseAndPrintJSON(const std::string& json) {
    // Создаем объект документа
    rapidjson::Document document;

    // Разбираем JSON
    rapidjson::ParseResult result = document.Parse(json.c_str());
    if (!result) {
        std::cerr << " JSON parsing error: " 
                  << rapidjson::GetParseError_En(result.Code()) 
                  << " (offset " << result.Offset() << ")\n";
        return;
    }

    // Проверяем, является ли JSON объектом
    if (!document.IsObject()) {
        std::cerr << "JSON must be an object\n";
        return;
    }

    // Итерируем по ключам объекта
    for (auto it = document.MemberBegin(); it != document.MemberEnd(); ++it) {
        std::cout << "Key: " << it->name.GetString() << "\n";

        // В зависимости от типа значения выводим его
        const auto& value = it->value;
        if (value.IsString()) {
            std::cout << "Value: " << value.GetString() << "\n";
        } else if (value.IsInt()) {
            std::cout << "Value: " << value.GetInt() << "\n";
        } else if (value.IsDouble()) {
            std::cout << "Value: " << value.GetDouble() << "\n";
        } else if (value.IsBool()) {
            std::cout << "Value: " << (value.GetBool() ? "true" : "false") << "\n";
        } else if (value.IsArray()) {
            std::cout << "Value: array\n";
            for (auto& arrayElement : value.GetArray()) {
                if (arrayElement.IsString())
                    std::cout << "  - " << arrayElement.GetString() << "\n";
                else if (arrayElement.IsInt())
                    std::cout << "  - " << arrayElement.GetInt() << "\n";
            }
        } else if (value.IsObject()) {
            std::cout << "Value: nested object\n";
        } else {
            std::cout << "Value: unknown type\n";
        }
    }
}