#ifndef PART_2_CPP_INCLUDE
#define PART_2_CPP_INCLUDE

#include <iostream>
#include <random>
#include <unordered_map>
#include <vector>

struct Student {
  int id = -1;
  int group = -1;
}; // End Student
// FIX-ME: When there are more students than available spots in groups, function loops forever.
std::vector<Student> AssignStudents(std::vector<Student>& s, std::unordered_map<int, int>& g) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(0, g.size() - 1);

  int rand_num;
  for (int i = 0; i < s.size();) {
    rand_num = distrib(gen);

    if (g[rand_num] < 5) {
      s.at(i).group = rand_num; // Assign student i to group rand_num
      g[rand_num]++;            // Increment the number of students in group rand_num
      i++;                      // Move onto next student
    }
    // Else produce another rand_num and try again
  }

  return s;
}

void PrintStudents(const std::vector<Student>& s) {
  for (const auto& student : s) {
    std::cout << "Student: " << student.id << " Group: " << student.group << std::endl;
  }
}

void PrintGroup(const std::unordered_map<int, int> g) {
  for (const auto& [key, value] : g) {
    std::cout << "Group: " << key << " # of Students: " << value << std::endl;
  }
}

#endif
