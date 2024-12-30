#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include <string>
#include <rapidjson/document.h>

// Функция для обработки строки JSON
void parseAndPrintJSON(const std::string& json);

// Функция для обработки JSON-объекта
void parseAndPrintJSON(const rapidjson::Value& value);

#endif // JSON_PARSER_H