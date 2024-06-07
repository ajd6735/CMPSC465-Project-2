/**
*Academic Integrity Statement: I certify that, while others may have assisted me
in brain storming, debugging and validating this program, the program itself is
my own work. I understand that submitting code which is the work of other
individuals is a violation of the course Academic Integrity Policy and may
result in a zero credit for the assignment, or course failure and a report to
the Academic Dishonesty Board. I also understand that if I knowingly give my
original work to another individual that it could also result in a zero credit
for the assignment, or course failure and a report to the Academic Dishonesty
Board. See Academic Integrity Procedural Guidelines Links to an external site.
at:
https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelines
Links to an external site.

*Your Name: Ana Diru

*Your PSU user ID:  ajd6735

*Course title: CMPSC465 June 2024

*Due Time: 11:59pm, Sunday, June 20, 2024

*Time of Last Modification: N/A

*Description: The program generates all possible combinations of well-formed
parentheses for a given number of pairs. It takes an integer input from the user
representing the number of pairs of parentheses and outputs all valid strings of
parentheses that can be formed with that number of pairs.

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void generateParentheses(string current, int open, int close, int max,
                         vector<string> &result);

vector<string> generateParentheses(int n);

int main() {
  int n; // Number of pairs of parentheses

  // Prompt the user to enter the number of pairs of parentheses
  cout << "Enter the number of parentheses: ";
  cin >> n;

  if (cin.fail() || n < 0) { // Check for invalid input
    cout << "Invalid input." << endl;
    return 1;
  }

  // Generate all possible combinations of well-formed parentheses
  vector<string> parentheses = generateParentheses(n);

  cout << "All combinations of well-formed parenteses are: " << endl;

  // Print the generated parentheses
  for (const auto &p : parentheses) {
    cout << p << endl;
  }
  return 0;
}

// A helper function to generate all parentheses
void generateParentheses(string current, int open, int close, int max,
                         vector<string> &result) {
  if (current.length() == max * 2) {
    result.push_back(current); // Add the current string to the result
    return;
  }

  if (open < max) { // Add an open parenthesis
    generateParentheses(current + "(", open + 1, close, max, result);
  }

  if (close < open) { // Add a close parenthesis
    generateParentheses(current + ")", open, close + 1, max, result);
  }
}

// The main function to generate all parentheses
vector<string> generateParentheses(int n) {
  vector<string> result; // Vector to store the generated parentheses
  // Generate all parentheses with n pairs of parentheses
  generateParentheses("", 0, 0, n, result);
  return result;
}

/* Test cases:

Enter the number of parentheses: 4
All combinations of well formed parenteses are:
(((())))
((()()))
((())())
((()))()
(()(()))
(()()())
(()())()
(())(())
(())()()
()((()))
()(()())
()(())()
()()(())
()()()()

Enter the number of parentheses: 3
All combinations of well formed parenteses are:
((()))
(()())
(())()
()(())
()()()

Enter the number of parentheses: 2
All combinations of well formed parenteses are:
(())
()()

Enter the number of parentheses: -1
Invalid input.
*/
