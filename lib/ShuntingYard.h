#pragma once
#include <string>
#include <queue>
#include <algorithm>
#include <iostream>
#include <stack>
#include <exception> 

class ShuntingYard {
public:
    /**     
    @param Выражение.
    @return  Конечный ответ в виде вещественного числа.
    */
    double calc(const std::string& expression);

    enum class Associativity {
        Left,
        Right
    };


    enum class Unarity  {
        Unary,
        Binary
    };
    
    static double Pi;
    /**
    @brief Приоритет операций.
    */
    static std::vector<std::vector<std::string>> priorityVector;

    /**
    @brief Допустимые операции.
    */
    static std::vector<std::string> functionsVector;

    /**
    @brief Унарные операции.
    */
    static std::vector<std::string> unaryVector;

    /**
    @brief Правоассоциативные операции.
    */        
    static std::vector<std::string> rightAssociativityVector;
    /**
    @param Вещественное число.
    @return Модуль числа.
    */
    double fabs(double x);

    /**
    @param Вещественное число больше нуля.
    @return Логарифм числа.
    @details Используется ряд Тейлора.
    */
    double ln(double x);

    /**
    @param Два вещественных числа.
    @return Возведение числа a в b-нную степень.
    @details Используется ряд Тейлора.
    */
    double pow(double a, double b);

    /**     
    @param Вещественное число.
    @return Синус числа.
    @details Используется ряд Тейлора.
    */
    double sin(double x);

        /**     
    @param Вещественное число.
    @return Косинус числа.
    @details Косинус выражен через формулу sin(2x) = 2sin(x)*cos(x)
    */
    double cos(double x);

        /**     
    @param Вещественное число по модулю меньше или равно 1.
    @return Синус числа.
    @details Используется ряд Тейлора.
    */
    double asin(double x);

        /**     
    @param Вещественное число по модулю меньшее или равное 1.
    @return Арккосинус числа.
    @details используется формула arccos(x) = Pi/2 - arcsin(x)
    */
    double acos(double x);

    /**     
    @param Вещественное число x, cos(x) != 0.
    @return арккосинус числа.
    @details Используется формула tg(x) = sin(x) / cos(x).
    */
    double tg(double x);

        /**     
    @param Вещественное число x, sin(x) != 0.
    @return арккосинус числа.
    @details Используется формула ctg(x) = sin(x) / cos(x).
    */
    double ctg(double x);

        /**     
    @param Вещественное число 
    @return арккосинус числа.
    @details Используется формула ctg(x) = sin(x) / cos(x).
    */
    double atg(double x);

    /**     
    @param Строка-токен. 
    @details Проверяет, является ли токен числом.
    */
    bool isNumber(std::string token);

    /**     
    @param Строка-токен. 
    @details Проверяет, является ли строка функцией.
    */
    bool isFunction(const std::string& token);

    /**     
    @param Строка-токен. 
    @details Проверяет, является ли строка операцией.
    */
    bool isOperator(const std::string& token);

    /**     
    @param Строка-токен. 
    @details Проверяет, какой приоритет у функции.
    @return Уровень приоритета функции.
    */
    static ptrdiff_t priority(const std::string& token);

    /**     
    @param Строка-токен. 
    @details Проверяет ассоциативность.
    @return Ассоциативность(Левая или Правая)
    */
    Associativity associativity(const std::string& token);

    /**     
    @param Строка-токен. 
    @details Проверяет, является ли функция унарной.
    */
    Unarity unarity(const std::string& token);

    /**     
    @param Функция и вещественное число.
    @details Выполняет унарную операцию.
    @return Результат.
    */
    double unary(const std::string& operation, double operand);

    /**     
    @param Функция и два вещественных числа.
    @details Выполняет бинарные операции.
    @return Результат.
    */
    double binary(const std::string& operation, double operand1, double operand2);

    /**     
    @param Изначальная строка.
    @details Разделяет строку на токены.
    @return Вектор токенов.
    */
    std::vector<std::string> tokenize(const std::string& expression);

    /**     
    @param Вектор токенов.
    @details Выполняет алгоритм сортировочной станции.
    @return  Очередь в виде обратной польской нотации.
    */
    std::queue<std::string> shuntingYard(const std::vector<std::string>& tokenVector);

    /**     
    @param Очередь в виде польской нотации.
    @details Выполняет математические операции.
    @return  Конечный ответ в виде вещественного числа.
    */
    double calculate(std::queue<std::string> output);
};
