# CMakeList.txt: проект CMake для LaboratoryBigInt; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (LaboratoryBigInt "LaboratoryInteger.cpp" "LaboratoryInteger.h")
add_compile_options(-werror -wall -fsanitize=address --coverage)

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
