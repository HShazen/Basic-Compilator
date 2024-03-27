# Compilation Project5
#### Computer Science Bachelor's Degree - Semester 5
#### Department of Computer Science - Compilation Module
#### TP Project: Creation of a Mini Compiler
#### 2023-2024
#### result: 19/20 ~ 95%

## Introduction: 
This project was developed as part of the Compilation module in the fifth semester of the Bachelor's degree program in Computer Science. The project leverages Flex and Bison, powerful tools for creating scanners and parsers, respectively. The goal of the project was to implement a compiler or a language-related tool, demonstrating understanding and proficiency in compiler construction concepts. The project received a notable grade of 19, equivalent to 95%.

## How to run:
### To compile the project, use the following commands:

```bash
bison -d synt.y
flex lex.l
gcc lex.yy.c synt.tab.c -o test
```

### To test the compiled program, use:
```
./test code.txt
```

where `code.txt` contains the code following the structure outlined in the attached PDF.

## Key Components:
- **Flex (Lexical Analyzer Generator):** Used to generate lexical analyzers (scanners) to tokenize input.
- **Bison (Parser Generator):** Utilized to generate parsers for syntactic analysis based on the provided grammar rules.
- **Compiler Features:** The project likely involved lexical analysis, syntactic analysis, and possibly semantic analysis and code generation, depending on the requirements of the project.
- **Testing:** The project would have undergone rigorous testing to ensure correctness and robustness.

This repository serves as a testament to the knowledge and skills acquired in the Compilation module and showcases practical implementation of compiler construction concepts.




## Explanation:
The goal of this project is to develop a mini-compiler for a language called "CodeL," covering the different phases of compilation: lexical, syntactic, and semantic.

### I. Description of the CodeL Language

#### II.1 General Structure
**A) List of Declarations**
In the CodeL language, we can declare simple variables and constants.
- Simple variable: Type VariableName;
- Constant: CONST Type ConstantName;

Example:
- The three possible types are: INT, FLOAT, and BOOL.
- Declaration of a set of variables is done by separating the variable names with ','.
- Each VariableName is an identifier. An identifier (idf) starts with an uppercase alphabetical letter (A-Z) followed by a sequence of digits (0-9), alphabetical letters (A-Z and a-z), or the symbol '_'. Its size must not exceed 10 characters.
Identifiers must adhere to the following conditions:
> The idf must not contain consecutive '_' symbols.
> The '_' symbol must not appear at the end of the idf.
- An identifier can refer to a constant. There are two types of constants:
a) Integer constants: A sequence of digits, which can be signed or not.
b) Real constants: A sequence of digits containing the decimal point, which

**B) List of Instructions**
In our language, ONLY the following instructions are allowed:
- Arithmetic expressions use arithmetic operators: + - * /
- Conditions use relational operators: < <= <> == > >=

**C) Comments**
- Comments are a sequence of any characters between '{' and '}', not containing '}'

**D) Tasks to be Completed:**
Below are the different phases to be performed to achieve the requested compiler.

- Lexical analysis with the FLEX tool.
- Syntactic analysis with the Bison tool.
- Semantic analysis for the following errors:
  ● Undeclared idf
  ● Double declared idf
  ● Type incompatibility
  ● Changing the value of a constant
- Management of the symbol table. The table must have at least the following fields:
  - Name: the identifier indicating the name of the variable or constant.
  - Type: the type of the variable or constant
  - Const: indicates whether the variable is constant or not.
- Error handling:
  It is requested to display the appropriate error messages at each stage of the compilation process, specifying the line number and column of the error.

Good luck!

### Instructions Description
Instruction | Description | Example
--- | --- | ---
Assignment | Idf := arithmetic expression; | A := C * B;<br> A := 2;
For Loop | For (var := valInit, condition, counter) { Block Instructions } | For (I := 1; i <= 10; i++) { B := B + 2; }
Condition | If (Condition) { Block instructions} else { Block instructions} | If (a == 2) { B := 5; C := B + 1; }

This explanation provides an overview of the project requirements, the structure of the CodeL language, and the tasks to be completed for developing the mini-compiler. Each section outlines specific details, ensuring clarity and guidance for anyone interested in understanding or contributing to the project.

