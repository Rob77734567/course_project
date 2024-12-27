#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include "rapidjson/document.h" // Для работы с JSON-документами
#include "rapidjson/error/en.h" // Для вывода ошибок парсинга
#include <iostream>
#include <string>

void parseAndPrintJSON(const std::string& json);

#endif //JSON_PARSER_H