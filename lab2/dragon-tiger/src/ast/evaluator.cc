#include "evaluator.hh"
#include "../utils/errors.hh"

namespace ast {

int32_t ASTEvaluator::visit(const IntegerLiteral &literal) {
  return literal.value;
}

int32_t ASTEvaluator::visit(const StringLiteral &literal) {
  utils::error("Erreur String...");
}

int32_t ASTEvaluator::visit(const BinaryOperator &binop) {
  int32_t left_operator = binop.get_left().accept(*this);
  int32_t right_operator = binop.get_right().accept(*this);

  switch (binop.op)
  {
    case o_plus:
      return left_operator + right_operator;
    case o_minus:
      return left_operator - right_operator;
    case o_times:
      return left_operator * right_operator;
    case o_divide:
      return left_operator / right_operator;
    case o_eq: 
      return left_operator == right_operator;
    case o_neq:
      return left_operator != right_operator;
    case o_lt:
      return left_operator < right_operator;
    case o_gt:
      return left_operator > right_operator;
    case o_le:
      return left_operator <= right_operator;
    case o_ge:
      return left_operator >= right_operator;
    default:
      utils::error("Error unknown binary operator...");
  }
}

int32_t ASTEvaluator::visit(const Sequence &seqExpr) {
  const auto exprs = seqExpr.get_exprs();
  int32_t result;

  if (exprs.empty()) {
    utils::error("Erreur sequence vide ...");
  }

  for (auto expr = exprs.cbegin(); expr != exprs.cend(); expr++) {
    result = (*expr)->accept(*this);
  }

  return result;
}

int32_t ASTEvaluator::visit(const Let &) {
  utils::error("Erreur Let...");
}

int32_t ASTEvaluator::visit(const Identifier &){
  utils::error("Erreur Identifier...");
}

int32_t ASTEvaluator::visit(const IfThenElse &ite) {
  
  if(ite.get_condition().accept(*this))
  {
    return ite.get_then_part().accept(*this);
  }
  else
  {
    return ite.get_else_part().accept(*this);
  }
}


int32_t ASTEvaluator::visit(const VarDecl &) {
  utils::error("Erreur VarDecl....");
}

int32_t ASTEvaluator::visit(const FunDecl &) {
  utils::error("Erreur FunDecl...");
}

int32_t ASTEvaluator::visit(const FunCall &) {
  utils::error("Erreur FunCall...");
}

int32_t ASTEvaluator::visit(const WhileLoop &) {
  utils::error("Erreur While...");
}

int32_t ASTEvaluator::visit(const ForLoop &) {
  utils::error("Erreur For...");
}

int32_t ASTEvaluator::visit(const Break &) {
  utils::error("Erreur Break...");
}

int32_t ASTEvaluator::visit(const Assign &) {
  utils::error("Erreur Assign...");
}

}
