#ifndef PHPINTERP_COMPILE_H
#define PHPINTERP_COMPILE_H

#include <stdint.h>
#include "parse.h"


typedef enum Operator {
    OP_INVALID = 0,
    OP_ECHO,
    OP_STR,
    OP_LONG, // Long in next two operators
    OP_TRUE,
    OP_FALSE,
    OP_BIN, // Type in next operator
    OP_ASSIGN,
    OP_LOOKUP, // String in next operator
    OP_JMP,
    OP_JMPZ,
    OP_NOP
} Operator;

typedef struct Function {
    char* name;
    Operator* ip;
    size_t codesize;
    size_t codecapacity;
    Operator* code;

    char** strs;
    uint16_t strlen;
    uint16_t strcapacity;
} Function;

Function* create_function();
void free_function(Function* fn);

Function* compile(Function* fn, AST* root);

char* get_op_name(Operator op);
void print_code(Function* fn);

#endif //PHPINTERP_COMPILE_H