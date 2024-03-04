#include "Codegen.h"

void Codegen::visit ( BinaryExprAST const& node )
{
  llvm::Value *l = node.LHS->accept(*this);
  llvm::Value *r = node.RHS->accept(*this);
  if (!l || *r)
    return nullptr;
  
  switch (node->op)
  {
    case '+':
      return builder->llvm::CreateFAdd(l, r, "addtmp");
    case '-':
      return builder->llvm::CreateFSub(l, r, "subtmp");
    case '*':
      return builder->llvm::CreateFMul(l, r, "multmp");
    case '<':
      l = builder->llvm::CreateFCmpULT(l, r, "cmptmp");
      // converts 1 bit bool from comparison to double 0.0/1.0
      return builder->llvm::CreateUIToFP(l, llvm::Type::getDoubleTy(context), "booltmp");
    default:
      logError("invalid binary operator");
      return;
  }
}

void Codegen::visit ( CallExprAST const& node )
{
  llvm::Function *calleeF = llvm::module->getFunction(node.callee);
  if (!calleeF)
  {
    logError("Unknown function referenced");
    return nullptr;
  }

  if (calleeF->arg_size() != node.args.size())
  {
    logError("Incorrect # arguments passed");
    return nullptr;
  }

  std::vector<llvm::Value *> argsV;
  for (uint i = 0, e = node.args.size(); i != e; ++i)
  {
    argsV.push_back(node.args[i]->accept(*this));
    if (!argsV.back())
      return nullptr;
  }

  return builder->llvm::CreateCall(calleeF, argsV, "calltmp");
}

void Codegen::visit ( FunctionAST const& node )
{
  return;
}

void Codegen::visit ( NumberExprAST const& node )
{
  return llvm::ConstantFP::get(*context, APFloat(val));
}

void Codegen::visit ( PrototypeAST const& node )
{
  return;
}

void Codegen::visit ( VariableExprAST const& node )
{
  llvm::Value *v = namedValues[node.name];
  if (!v)
  {
    logError("Unknown variable name");
    return nullptr;
  }
  return v;
}

