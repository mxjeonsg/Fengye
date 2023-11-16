#pragma once

/*
  FengYe - CPPML Rewrite Project
  Tuesday, Nov 14, 2023 by mxjeonsg
  
  Typedef.h $ Type definitions
*/

//Integer/Float types
typedef unsigned char u8;
typedef const unsigned char imutu8;
typedef unsigned char* u8ptr;
typedef const unsigned char* imutu8ptr;
typedef unsigned char& u8ref;
typedef const unsigned char& imutu8ref;

typedef char* cstring;
typedef const char* imutcstring;
typedef char*& cstringref;
typedef const char*& imutcstringref;

typedef signed char i8;
typedef signed char* i8ptr;
typedef signed char& i8ref;

typedef unsigned short u16;
typedef unsigned short* u16ptr;
typedef unsigned short& u16ref;

typedef signed short i16;
typedef signed short* i16ptr;
typedef signed short& i16ref;

typedef unsigned int u32;
typedef unsigned int* u32ptr;
typedef unsigned int& u32ref;

typedef signed int i32;
typedef signed int* i32ptr;
typedef signed int& i32ref;

typedef unsigned long u64;
typedef unsigned long* u64ptr;
typedef unsigned long& u64ref;

typedef signed long i64;
typedef signed long* i64ptr;
typedef signed long& i64ref;

typedef float f32;
typedef float* f32ptr;
typedef float& f32ref;

typedef long f64;
typedef long* f64ptr;
typedef long& f64ref;

typedef long long l64;
typedef long long* l64ptr;
typedef long long& l64ref;

//Unsafe pointer type
typedef void* rawptr;

//Function types
typedef void(*func0)(void);
typedef u8(*u8func0)(void);
typedef u16(*u16func0)(void);
typedef u32(*u32func0)(void);
typedef u64(*u64func0)(void);
typedef cstring(*cstringfunc0)(void);


//Other types
#define infer auto
#define inferptr auto*
#define inferref auto&
typedef enum _fBool { yes = true, no = false } bbool;
typedef std::string string;
typedef std::string* stringptr;
typedef std::string& stringref;