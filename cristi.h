#pragma once
#include <bits/stdc++.h>
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