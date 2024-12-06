#ifndef IR_H
#define IR_H

#include <llvm/IR/Value.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>

extern llvm::LLVMContext TheContext;
extern llvm::IRBuilder<> Builder;
extern llvm::Module* TheModule;

void declareVariable(std::string* varName, const char* type);
llvm::Value* generateLLVMForExpression(llvm::Value* left, llvm::Value* right);
void generateLLVMForDeclaration(std::string* varName, llvm::Value* value);

#endif // IR_H

