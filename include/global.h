#ifndef GLOBAL_H
#define GLOBAL_H

#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
#include <algorithm>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <vector>
#include <memory>
#include <utility>
#include <map>

std::unique_ptr<llvm::LLVMContext> context;
std::unique_ptr<llvm::IRBuilder<>> builder(context);
std::unique_ptr<llvm::Module> module;
std::map<std::string, llvm::Value *> namedValues;


#endif