#include "Json_parser.h"
#include <iostream>
#include <rapidjson/document.h>
#include <rapidjson/error/en.h>

// Функция для обработки JSON-объекта
void parseAndPrintJSON(const rapidjson::Value& value) {
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
            parseAndPrintJSON(arrayElement); // Рекурсивная обработка
        }
    } else if (value.IsObject()) {
        std::cout << "Value: nested object\n";
        for (auto it = value.MemberBegin(); it != value.MemberEnd(); ++it) {
            std::cout << "Key: " << it->name.GetString() << "\n";
            parseAndPrintJSON(it->value); // Рекурсивная обработка
        }
    } else {
        std::cout << "Value: unknown type\n";
    }
}

// Функция для обработки строки JSON
void parseAndPrintJSON(const std::string& json) {
    rapidjson::Document document;

    // Разбор JSON-строки
    rapidjson::ParseResult result = document.Parse(json.c_str());
    if (!result) {
        std::cerr << "JSON parsing error: "
                  << rapidjson::GetParseError_En(result.Code())
                  << " (offset " << result.Offset() << ")\n";
        return;
    }

    // Проверяем, является ли корневой элемент объектом
    if (!document.IsObject()) {
        std::cerr << "JSON must be an object\n";
        return;
    }

    // Итерируем по ключам объекта
    for (auto it = document.MemberBegin(); it != document.MemberEnd(); ++it) {
        std::cout << "Key: " << it->name.GetString() << "\n";
        parseAndPrintJSON(it->value); // Обрабатываем значение
    }
}