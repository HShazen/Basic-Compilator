# Compilation Project5

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
