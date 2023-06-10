#pragma once
#include <fstream>
#include <ctime>
#include <windows.h>
#include <iomanip>
#include <map>

using namespace std;

ifstream fin("i.txt");
ofstream fout("o.txt");

// 1 byte = 8 bits
// 1 byte  = 2^8
// char - 1 byte
// sizeof(int) = 4
using uchar = unsigned char;      // same thing
typedef unsigned char uchar;      // same thing
using sint = short int;           // 2 bytes = -2^15 - 2^15 - 1
using si32 = short int;           // 2 bytes = -2^15 - 2^15 - 1
using usint = unsigned short int; // 2 bytes = 0 - 2^16 - 1
using usi32 = unsigned short int; // 2 bytes = 0 - 2^16 - 1
using i32 = int;                  // 4 bytes = -2^31 - 2^31 - 1
using uint = unsigned int;        // 4 bytes = 0 - 2^32 - 1
using ui32 = unsigned int;        // 4 bytes = 0 - 2^32 - 1
// float - 4 bytes
using ll = long long int;           // 8 bytes = -2^63 - 2^63 - 1
using ull = unsigned long long int; // 8 bytes = 0 - 2^64 - 1
// double - 8 bytes
using ld = long double;

clock_t start_time, end_time;
void time_start_()
{
    start_time = clock();
}
void time_end_()
{
    end_time = clock();
    long double runtime = double(end_time - start_time) / double(CLOCKS_PER_SEC);
    fout << fixed << setprecision(10) << endl;
    fout << runtime << " seconds" << endl;
}

void sleep(unsigned int miliseconds)
{
    Sleep(miliseconds);
}

long long ceil_(long double number)
{
    if (number != (long long)(number))
    {
        return (long long)(number) + 1;
    }
    else if (number == (long long)(number))
    {
        return (long long)(number);
    }
}

long long floor_(long double number)
{
    return (long long)(number);
}

bool is_integer_(long double number)
{
    if (number == (long long)(number))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool is_float_(long double number)
{
    if (number != (long long)(number))
    {
        return true;
    }
    else
    {
        return false;
    }
}

long long pow_int_(long long base, int exponent)
{
    long long result = 1;
    for (int i = 0; i < exponent; i += 1)
    {
        result *= base;
    }
    return result;
}

long double pow_float_(long double base, int exponent, int precision)
{
    fout << fixed << setprecision(precision);
    long double result = 1;
    for (int i = 0; i < exponent; i += 1)
    {
        result *= base;
    }
    return result;
}

void prime_factors_(long long number)
{
    if (number == 0)
    {
        fout << "nu se poate" << endl;
    }
    else if (number == 1)
    {
        fout << 1 << endl;
    }
    else
    {
        map<int, int> m;
        while (number > 1)
        {
            bool found = false;
            for (int i = 2; i * i <= number; i += 1)
            {
                if (number % i == 0)
                {
                    m[i] += 1;
                    number /= i;
                    found = true;
                    break;
                }
            }
            if (found == false)
            {
                m[number] += 1;
                number = 1;
            }
        }
        for (auto i : m)
        {
            fout << i.first << "^" << i.second << "  ";
        }
        fout << " " << endl;
    }
}

bool prime_(long long number)
{
    if (number == 1 || number == 0)
    {
        return false;
    }
    for (int i = 2; i * i <= number; i += 1)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}

long double max_(long double first_nr, long double second_nr)
{
    if (first_nr >= second_nr)
    {
        return first_nr;
    }
    else if (second_nr > first_nr)
    {
        return second_nr;
    }
}

long double min_(long double first_number, long double second_number)
{
    if (first_number <= second_number)
    {
        return first_number;
    }
    else if (second_number < first_number)
    {
        return second_number;
    }
}

long long gcd_(long long first_nr, long long second_nr)
{
    int x;
    while (second_nr != 0)
    {
        x = first_nr;
        first_nr = second_nr;
        second_nr = x % second_nr;
    }
    return first_nr;
}

long long lcm_(long long first_nr, long long second_nr)
{
    long long gcd = gcd_(first_nr, second_nr);
    long long result = (first_nr / gcd) * second_nr;
    return result;
}