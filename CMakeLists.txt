# Указываем минимальную версию CMake
cmake_minimum_required(VERSION 3.10)

# Указываем имя проекта и его версию
project(COURCE_PROJECT VERSION 1.0)

# Указываем стандарт C++
set(CMAKE_CXX_STANDARD 11) # Устанавливаем стандарт C++ на 11
set(CMAKE_CXX_STANDARD_REQUIRED True) # Обязательное использование указанного стандарта

# Добавляем исполняемый файл
add_executable(MyExecutable main.cpp json_parser.cpp) # Создаем исполняемый файл из указанных исходников

# Указываем путь к заголовочным файлам RapidJSON
target_include_directories(MyExecutable PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Установка целевого каталога для установки
set(CMAKE_INSTALL_PREFIX "/usr/local")  # Установка по умолчанию

# Установка исполняемого файла
install(TARGETS MyExecutable DESTINATION bin) # Устанавливаем исполняемый файл в каталог bin

# Установка конфигурации для пакета
if(APPLE)
    set(CPACK_GENERATOR "DMG")  # Для macOS используем DMG
    set(CPACK_PACKAGE_FILE_NAME "MyExecutable-macos")  # Имя пакета для macOS
elseif(UNIX)
    set(CPACK_GENERATOR "DEB")  # Для Linux используем DEB
    set(CPACK_PACKAGE_FILE_NAME "MyExecutable-linux")  # Имя пакета для Linux
else()
    set(CPACK_GENERATOR "ZIP")  # Для Windows используем ZIP
    set(CPACK_PACKAGE_FILE_NAME "MyExecutable-windows")  # Имя пакета для Windows
endif()

# Дополнительные параметры пакета
set(CPACK_PACKAGE_VERSION "0.1.0") # Версия пакета
set(CPACK_PACKAGE_DESCRIPTION "MyExecutable package description") # Описание пакета
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Your Name <your.email@example.com>") # Поддержка пакета Debian
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6 (>= 2.3.1-6)") # Зависимости пакета Debian
set(CPACK_PACKAGE_CONTACT "Your Name <your.email@example.com>") # Контактная информация по пакету
set(CPACK_PACKAGE_HOMEPAGE "https://example.com") # Домашняя страница пакета
set(CPACK_PACKAGE_LICENSE "MIT") # Лицензия пакета

include(CPack)  # Включение CPack для создания установочных пакетов