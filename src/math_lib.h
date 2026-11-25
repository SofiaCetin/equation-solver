#ifndef MATH_LIB_H
#define MATH_LIB_H

typedef long double Real;

typedef struct MathFunction{
    const char* name;
    Real (*function)(const Real *args);
    int argc;
}MathFunction;

typedef struct MathConstant{
    const char* symbol;
    Real value;
}MathConstant;

extern const MathFunction FUNCTIONS[];

#endif