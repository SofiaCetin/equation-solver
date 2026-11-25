# Equations solver

## Introduction

This program written with C aims at solving equations of different types(quadratic, polynomial/linear, etc...). It is presented as a symbolic engine that parses and determine the best way to solve the equation based on its type. Here are the steps of the algorithm explained as briefly as possible:

### Dependencies

Before starting anything related to the engine, we need to figure out elementary functions, and moreover structures that will be used in our program. You can find right below more description about the modules.

**mystr.h**: Shares all functions related to char and strings. Needed for the most basic form where our equation will start -> as a string input.

**list.h**: Provides doubly linked lists with dummies, which will greatly simplify dynamic operations on the token list.

