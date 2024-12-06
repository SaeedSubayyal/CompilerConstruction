%{
#include <iostream>
#include <string>            // Include string header for std::string
#include <llvm/IR/Value.h>   // Include LLVM header for llvm::Value
#include "IR.h"              // Include IR header for LLVM-related functions
%}

%union {
    int iVal;               // For integer values
    std::string* sVal;      // For string values (like identifiers)
    llvm::Value* llvmVal;   // For LLVM IR values (expressions)
}

%token <iVal> INTEGER
%token <sVal> IDENTIFIER
%token PLUS MINUS STAR SLASH  // Define tokens for operators

%type <llvmVal> expression

%left '+' '-'
%left '*' '/'
%right '='

%%

// Define your grammar rules here

%%

