#include <iostream>
#include "IR.h"  // Include IR header
#include "lex.yy.c"  // Include the lexer

int main() {
    std::cout << "Starting parser..." << std::endl;

    // Initialize LLVM's native target
    llvm::InitializeNativeTarget();
    llvm::InitializeNativeTargetAsmPrinter();
    llvm::InitializeNativeTargetAsmParser();

    // Parse the input using Bison and Flex
    yyparse();

    std::cout << "Parsing complete!" << std::endl;

    // Optionally, output the LLVM IR or save to a file
    TheModule->print(llvm::outs(), nullptr);

    return 0;
}

