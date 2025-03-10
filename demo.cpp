#include <iostream>

struct Problem {
    char question[50];
    char answers[4][50];
    char correct_answer;
    unsigned int points;
};

struct Test {
    Problem problems[30];
    unsigned int total_points = 0;
};

void printQuestions(Test &test){
    char answer;
    for (int i = 0; i < 1; i++) {
        Problem problem = test.problems[i];
        std::cout << i + 1 << ".  " << problem.question "( " << problem.points << " Points)" << "\n\n";
        for (int j = 0; j < 4; j++) {
            char letter = j + 65;
            std::cout << letter << ": " << problem.answers[j] << "  ";
        }
        std::cout <<  << "\n\n" << "Enter an answer (A, B, C or D): ";
        std::cin >> answer;
        if (answer == problem.correct_answer) {
            test.total_points += problem.points;
        }
    }
}

void inputProblems(Problem& problem, Test& test) {

}

int main()
{
    Test test1;
    Problem problem1 = { "What is the value of Pi?","1.21", "3.14", "2,71", "6.67", 'B', 2};
    test1.problems[0] = problem1;
    printQuestions(test1);
    std::cout << "Total points: " << test1.total_points;
}

