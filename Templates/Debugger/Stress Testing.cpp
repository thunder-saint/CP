#include<bits/stdc++.h>
using namespace std;

const int ITER = 100; // select the number of iterations

int32_t main() {
  string correct = "g++ -o correct correct.cpp"; // change here
  system(correct.c_str()); 
  string wrong = "g++ -o wrong wrong.cpp"; // change here
  system(wrong.c_str()); 
  string generator = "g++ -o generator generator.cpp";
  system(generator.c_str()); 

  auto st = clock();
  for (int t = 1; t <= ITER; t++) {
    cerr << "Trying for the " << t << "-th time :((\n";

    string in = "input.txt";
    string generator = "generator > input.txt";
    system(generator.c_str()); 

    string correct_solution = "correct < input.txt > correct_solution.txt";
    system(correct_solution.c_str());

    string wrong_solution = "wrong < input.txt > wrong_solution.txt";
    system(wrong_solution.c_str());

    ifstream correct_file;
    correct_file.open("correct_solution.txt"); 
    string correct_output = "", line;
    while (getline(correct_file, line, '.')) { 
      correct_output += line;
    }

    ifstream wrong_file;
    wrong_file.open("wrong_solution.txt"); 
    string wrong_output = "";
    while (getline(wrong_file, line, '.')) { 
      wrong_output += line;
    }

    if (correct_output != wrong_output) {
      cout << "MISMATCH FOUND while running test case " << t << "\n\n";
      cerr << "MISMATCH FOUND while running test case " << t << "\n\n";
      cout << "Check the input.txt file to find the case, correct_solution.txt to find the correct output and similarly check the wrong_solution.txt\n";
      cerr << "Time taken = " << 1.0 * (clock() - st) / CLOCKS_PER_SEC << "s\n";
      exit(0);
    }

    correct_file.close();
    wrong_file.close();
  }
  cout << "No cases found!\n";
  cerr << "No cases found!\n";
  cerr << "Time taken = " << 1.0 * (clock() - st) / CLOCKS_PER_SEC << "s\n";
  return 0;
}
