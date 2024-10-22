#ifndef SNAKE_H
#define SNAKE_H

#include <raylib.h>
#include <deque>

class Snake
{
public:
    std::deque<Vector2> body;  // Тіло змії
    Vector2 movementDirection;  // Напрямок руху змії

    Snake();  // Конструктор для ініціалізації змії
    void render();  // Відповідає за відображення змії на екрані
    void move();  // Оновлює положення змії на карті
    void reset();  // Скидає змію до початкового стану
};

#endif
