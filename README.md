# Logical Expression Equivalence Checker

This project is a C++ program that generates and evaluates truth tables for logical expressions. It compares two logical expressions to determine if they are equivalent across all possible combinations of variables.

## Features

- **Input Custom Logical Expressions**: Users can define their own logical statements using variables `A`, `B`, and `C` with `AND` and `OR` operators.
- **Truth Table Generation**: The program generates a complete truth table for the logical expressions based on all possible values of `A`, `B`, and `C`.
- **Equivalence Check**: Compares the truth tables of two expressions to determine if they are logically equivalent.

## Installation

### Installation Using [Visual Studio](https://visualstudio.microsoft.com/downloads/)

1. **Clone the Repository**

   Clone the repository to your local machine using the following command:

   ```bash
   git clone https://github.com/adamt-eng/logical-expression-equivalence-checker
   ```

2. **Open the Project**

   - Navigate to the directory where the repository was cloned.
   - Open the `Logical Expression Equivalence Checker.sln` solution file in Visual Studio.

3. **Build the Project**

   - Once the project is opened in Visual Studio, build the solution by selecting `Build > Build Solution` from the menu or pressing `Ctrl + Shift + B`.

4. **Run the Program**

   - After building the solution, you can run the program by pressing `F5` or selecting `Debug > Start Debugging`.

### Alternative Compilation

If you prefer not to use Visual Studio, you can directly compile the `Program.cpp` file using a standard C++ compiler of your choice.

### Additional Notes

- If there are any missing dependencies or libraries, Visual Studio will prompt you to install them automatically.
- Ensure that your system has the necessary C++ development tools and libraries installed through Visual Studio's installer or your preferred development environment.

## Usage

To use the Logical Expression Equivalence Checker, follow these steps:

1. **Input the First Logical Expression (Expression A):**
   - When prompted, enter the number of logical statements (combinations of variables and operators) that make up your expression.
   - For each statement:
     - Select the variables (`A`, `B`, `C`).
     - Specify whether you want to negate the variables.
     - Choose the operator (`AND`, `OR`) to combine the variables.
   - Once you've defined all the statements, provide the operators that connect these statements (use `&` for `AND`, `|` for `OR`).

2. **Generate the Truth Table for Expression A:**
   - The program will then generate and display the truth table for Expression A, showing all possible combinations of variables and the corresponding result for each.

3. **Input the Second Logical Expression (Expression B):**
   - Similar to Expression A, define the logical statements for Expression B by specifying the variables, negation options, and operators.
   - Provide the operators that connect the statements of Expression B.

4. **Generate the Truth Table for Expression B:**
   - The program will generate and display the truth table for Expression B, based on the provided statements and operators.

5. **Equivalence Check:**
   - After generating the truth tables for both expressions, the program will compare the results for each possible combination of variables.
   - If the results of both expressions match for all combinations, the program will confirm that the expressions are equivalent.
   - Otherwise, the program will indicate that the expressions are not equivalent.

## Example

I have a logical expression: `(A && B) || (B || C) && (B && C) || (B && C) && !(B && C)`, I have simplified it to `B && (A || C)`. I need to confirm that my simplification was accurate and so I use the C++ program as follows:

Expression A Input:
```
Expression A

How many statements do you need?: 5

Which variables would you like to use in Statement 1? (Maximum 2) (A/B/C): AB
Do you want to negate the first variable? (Y/N): N
Do you want to negate the second variable? (Y/N): N
What's the operator between the two variables? (OR/AND): AND

Saved Statement 1: A AND B

Which variables would you like to use in Statement 2? (Maximum 2) (A/B/C): BC
Do you want to negate the first variable? (Y/N): N
Do you want to negate the second variable? (Y/N): N
What's the operator between the two variables? (OR/AND): OR

Saved Statement 2: B OR C

Which variables would you like to use in Statement 3? (Maximum 2) (A/B/C): BC
Do you want to negate the first variable? (Y/N): N
Do you want to negate the second variable? (Y/N): N
What's the operator between the two variables? (OR/AND): AND

Saved Statement 3: B AND C

Which variables would you like to use in Statement 4? (Maximum 2) (A/B/C): BC
Do you want to negate the first variable? (Y/N): N
Do you want to negate the second variable? (Y/N): N
What's the operator between the two variables? (OR/AND): AND

Saved Statement 4: B AND C

Which variables would you like to use in Statement 5? (Maximum 2) (A/B/C): BC
Do you want to negate the first variable? (Y/N): Y
Do you want to negate the second variable? (Y/N): Y
What's the operator between the two variables? (OR/AND): OR

Saved Statement 5: B' OR C'

Please enter the 4 operator(s) you want to separate your statements with (& for AND, | for OR): |&|&
```

Expression A Output:
```
Expression A Expression Truth Table

A       B       C       S1      S2      S3      S4      S5      Result
1       1       1       1       1       1       1       0       1
1       1       0       1       1       0       0       1       1
1       0       1       0       1       0       0       1       0
1       0       0       0       0       0       0       1       0
0       1       1       0       1       1       1       0       1
0       1       0       0       1       0       0       1       0
0       0       1       0       1       0       0       1       0
0       0       0       0       0       0       0       1       0
```

Expression B Input:
```
Expression B

How many statements do you need?: 2

Which variables would you like to use in Statement 1? (Maximum 2) (A/B/C): B
Do you want to negate that variable? (Y/N): N

Saved Statement 1: B

Which variables would you like to use in Statement 2? (Maximum 2) (A/B/C): AC
Do you want to negate the first variable? (Y/N): N
Do you want to negate the second variable? (Y/N): N
What's the operator between the two variables? (OR/AND): OR

Saved Statement 2: A OR C

Please enter the 1 operator(s) you want to separate your statements with (& for AND, | for OR): &
```

Expression A Output:
```
Expression B Expression Truth Table

A       B       C       S1      S2      Result
1       1       1       1       1       1
1       1       0       1       1       1
1       0       1       0       1       0
1       0       0       0       1       0
0       1       1       1       1       1
0       1       0       1       0       0
0       0       1       0       1       0
0       0       0       0       0       0
```

Final Output:
```
The two expressions are equivalent.
```
