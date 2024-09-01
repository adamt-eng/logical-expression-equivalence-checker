#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

// A struct to hold statement details.
struct statement
{
    string variables;
    string op;
    bool negate_first = false;
    bool negate_second = false;
};

// Function prototypes
bool translate_variable(char variable);
bool translate_operator(const string& op, bool variable1, bool variable2);
bool evaluate_statement(const statement& stmt);
void get_input(int label, statement& stmt);
void generate_truth_table(const string& label, vector<statement>& statements, int& index, int expressions[]);
bool evaluate_expression(const vector<bool>& results, const vector<char>& ops);

int a = 1, b = 1, c = 1;

int main()
{
    int expressions[16]{};
    int index = 0;

    vector<statement> expression_a;
    vector<statement> expression_b;

    generate_truth_table("Expression A", expression_a, index, expressions);
    generate_truth_table("Expression B", expression_b, index, expressions);

    // Compare the truth table results for equivalence.
    bool equivalent = equal(begin(expressions), begin(expressions) + 8, begin(expressions) + 8);
    cout << "\nThe two expressions are " << (equivalent ? "equivalent." : "not equivalent.") << "\n";

    return 0;
}

bool translate_variable(char variable)
{
    switch (variable)
    {
	    case 'A': return a;
	    case 'B': return b;
	    case 'C': return c;
	    default: return false;
    }
}

bool translate_operator(const string& op, bool variable1, bool variable2)
{
    if (op == "OR")
    {
        return variable1 || variable2;
    }

    if (op == "AND")
    {
        return variable1 && variable2;
    }

    return false;
}

bool evaluate_statement(const statement& stmt)
{
    if (stmt.variables.empty())
    {
        return false;
    }

    bool first = translate_variable(stmt.variables[0]);
    first = stmt.negate_first ? !first : first;

    if (stmt.variables.length() == 1)
    {
        return first;
    }

    bool second = translate_variable(stmt.variables[1]);
    second = stmt.negate_second ? !second : second;

    return translate_operator(stmt.op, first, second);
}

void get_input(int label, statement& stmt)
{
    cout << "\nWhich variables would you like to use in Statement " << label << "? (Maximum 2) (A/B/C): ";
    cin >> stmt.variables;

    char prompt;

    if (stmt.variables.length() == 2)
    {
        cout << "Do you want to negate the first variable? (Y/N): ";
        cin >> prompt;
        stmt.negate_first = prompt == 'Y';

        cout << "Do you want to negate the second variable? (Y/N): ";
        cin >> prompt;
        stmt.negate_second = prompt == 'Y';

        cout << "What's the operator between the two variables? (OR/AND): ";
        cin >> stmt.op;
    }
    else if (stmt.variables.length() == 1)
    {
        cout << "Do you want to negate that variable? (Y/N): ";
        cin >> prompt;
        stmt.negate_first = prompt == 'Y';
    }

    cout << "\nSaved Statement " << label << ": " << stmt.variables[0]
        << (stmt.negate_first ? '\'' : char())
        << (stmt.variables.length() == 2 ? " " + stmt.op + " " + stmt.variables[1] + (stmt.negate_second ? '\'' : char()) : "")
        << "\n";
}

void generate_truth_table(const string& label, vector<statement>& statements, int& index, int expressions[])
{
    cout << "\n" << label << "\n\nHow many statements do you need?: ";

    int count;
    cin >> count;

    statements.resize(count);

    // Get input for the statements
    for (int i = 0; i < count; ++i)
    {
        get_input(i + 1, statements[i]);
    }

    // Get the operators between the statements
    vector<char> operators(count - 1);
    cout << "\nPlease enter the " << operators.size() << " operator(s) you want to separate your statements with (& for AND, | for OR): ";
    for (auto& op : operators)
    {
        cin >> op;
    }

    cout << "\n" << label << " Expression Truth Table\n\nA\tB\tC\t";

    for (int i = 1; i <= count; ++i)
    {
        cout << "S" << i << "\t";
    }

    cout << "Result\n";

    // Generate truth table
    for (a = 1; a >= 0; --a)
    {
        for (b = 1; b >= 0; --b)
        {
            for (c = 1; c >= 0; --c)
            {
                vector<bool> results;

                results.reserve(count);

                for (int i = 0; i < count; ++i)
                {
                    results.push_back(evaluate_statement(statements[i]));
                }

                bool expression = evaluate_expression(results, operators);

                expressions[index++] = expression;

                cout << a << "\t" << b << "\t" << c << "\t";

                for (auto result : results)
                {
                    cout << result << "\t";
                }

                cout << expression << "\n";
            }
        }
    }
}

bool evaluate_expression(const vector<bool>& results, const vector<char>& ops)
{
    if (results.empty()) return false;

    bool result = results[0];

    for (size_t i = 0; i < ops.size(); ++i)
    {
        if (ops[i] == '&')
        {
            result = result && results[i + 1];
        }
        else if (ops[i] == '|')
        {
            // Evaluate the OR by checking the next result
            bool next_result = results[i + 1];

            // If there is an AND operation after this OR, it should be evaluated first
            while (i + 1 < ops.size() && ops[i + 1] == '&')
            {
                next_result = next_result && results[i + 2];
                i++;
            }

            result = result || next_result;
        }
    }

    return result;
}
