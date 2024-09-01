# Logical Expression Equivalence Checker

This project is a C++ program that generates and evaluates truth tables for logical expressions. It compares two logical expressions to determine if they are equivalent across all possible combinations of variables.

## Features

- **Input Custom Logical Expressions**: Users can define their own logical statements using variables `A`, `B`, and `C` with `AND` and `OR` operators.
- **Truth Table Generation**: The program generates a complete truth table for the logical expressions based on all possible values of `A`, `B`, and `C`.
- **Equivalence Check**: Compares the truth tables of two expressions to determine if they are logically equivalent.

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
