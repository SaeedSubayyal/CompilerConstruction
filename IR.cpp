#include "IR.h"
#include <llvm/IR/AllocaInst.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Module.h>

llvm::LLVMContext TheContext;
llvm::IRBuilder<> Builder(TheContext);
llvm::Module* TheModule = new llvm::Module("MyModule", TheContext);

void declareVariable(std::string* varName, const char* type) {
    llvm::Type* llvmType = llvm::Type::getInt32Ty(TheContext);  // Assume integer type for simplicity
    llvm::AllocaInst* alloca = Builder.CreateAlloca(llvmType, nullptr, *varName);
    TheModule->getFunctionList().begin()->getBasicBlockList().push_back(alloca);
}

llvm::Value* generateLLVMForExpression(llvm::Value* left, llvm::Value* right) {
    return Builder.CreateAdd(left, right, "addtmp");  // Example of addition in LLVM IR
}

void generateLLVMForDeclaration(std::string* varName, llvm::Value* value) {
    llvm::Type* llvmType = value->getType();
    llvm::AllocaInst* alloca = Builder.CreateAlloca(llvmType, nullptr, *varName);
    Builder.CreateStore(value, alloca);
}

