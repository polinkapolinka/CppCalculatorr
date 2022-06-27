#include "funcs.h"
/**
 * Функция суммирования
 * @param a первое число
 * @param b второе число
 * @return сумма чисел
 * */
int Summ(int a, int b) {
    int k;
    k = a + b;
    return k;
}

/**
 * Функция вычитания
 * @param a первое число
 * @param b второе число
 * @return разность чисел
 * */
int Diff(int a, int b) {
    int k;
    k = a - b;
    return k;
}

/**
 * Функция умножения
 * @param a первое число
 * @param b второе число
 * @return произведение чисел
 * */
int Mult(int a, int b) {
    int k;
    k = a * b;
    return k;
}

/**
 * Функция возведения в квадрат
 * @param a первое число
 * @return квадрат числа
 * */
int Square(int a) {
    int k;
    k = a * a;
    return k;
}

/**
 * Функция для генерации случайной последовательности
 * @return последовательность
 * */
int Rnd() {
    int a = rand() * 100000 + rand() * 10000 + rand() * 1000 + rand() * 100 +
        rand() * 10 + rand();
    return a;
}
/**
 * Функция нахождения логарифма
 * @param a первое число
 * @param b второе число (основание)
 * @return логарифм числа a по основанию b
 * */
int Loga_b(int a, int b) {
    int k;
    k = std::log(a) / std::log(b);
    return k;
}

/**
 * Функция перевода числа из 10 СС в 2 СС
 * @param num данное число
 * @return новое число
 * */
int from10to2(int num) {
    {
        int bin = 0, k = 1;

        while (num) {
            bin += (num % 2) * k;
            k *= 10;
            num /= 2;
        }

        return bin;
    }
}

/**
 * Функция перевода числа из 10 СС в 8 СС
 * @param num данное число
 * @return новое число
 * */
int from10to8(int num) {
    int bin = 0, k = 1;

    while (num) {
        bin += (num % 8) * k;
        k *= 10;
        num /= 8;
    }

    return bin;
}

/**
 * Функция перевода числа из 10 СС в 4 СС
 * @param num данное число
 * @return новое число
 * */
int from10to4(int num) {
    int bin = 0, k = 1;

    while (num) {
        bin += (num % 4) * k;
        k *= 10;
        num /= 4;
    }

    return bin;
}

/**
 * Функция перевода числа из 10 СС в новую СС
 * @param num данное число
 * @param num2 основание новой СС
 * @return новое число
 * */
int from10toyour(int num, int num2) {
    int bin = 0, k = 1;

    while (num) {
        bin += (num % num2) * k;
        k *= 10;
        num /= num2;
    }

    return bin;
}

/**
 * Функция подсчета процентов
 * @param a исходное число
 * @param b число процентов
 * @return новое число
 * */
int Persent(int a, int b) {
    int res;
    res = MulDiv(a, b, 100);
    return res;
}
/////////////Заимствовование/////////////////
/**
 * Функция нпреобразования строки в число
 * @param s строка
 * @return число
 * */
int StrToInt(char *s)
{
    int temp = 0;
    int i = 0;
    int sign = 0;
    if (s[i] == '-') {
        sign = 1;
        i++;
    }
    while (s[i] >= 0x30 && s[i] <= 0x39) {
        temp = temp + (s[i] & 0x0F);
        temp = temp * 10;
        i++;
    }
    temp = temp / 10;
    if (sign == 1)
        temp = -temp;
    return (temp);
}
/**
 * Функция нпреобразования числа в строку
 * @param n число
 * @return строка
 * */
char *IntToStr(int n) {
    char s[40], t, *temp;
    int i, k;
    int sign = 0;
    i = 0;
    k = n;
    if (k < 0) {
        sign = 1;
        k = -k;
    }
    do {
        t = k % 10;
        k = k / 10;
        s[i] = t | 0x30;
        i++;
    } while (k > 0);
    if (sign == 1) {
        s[i] = '-';
        i++;
    }
    temp = new char[i];
    k = 0;
    i--;
    while (i >= 0) {
        temp[k] = s[i];
        i--;
        k++;
    }
    temp[k] = '\0';
    return (temp);
}
//////////конец заимствования/////////////