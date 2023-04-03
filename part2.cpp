#ifndef PART_2_CPP_INCLUDE
#define PART_2_CPP_INCLUDE

#include <iostream>
#include <random>
#include <unordered_map>
#include <vector>

struct Student
{
  int id = -1;
  int group = -1;
}; // End Student

// randomly assigns students to groups with a maximum of five students per group.
std::vector<Student> AssignStudents(std::vector<Student> &s, std::unordered_map<int, int> &g)
{
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(0, g.size() - 1);

  int rand_num;
  for (int i = 0; i < s.size();)
  {
    rand_num = distrib(gen);

    if (g[rand_num] < 5)
    {
      s.at(i).group = rand_num; // Assign student i to group rand_num
      g[rand_num]++;            // Increment the number of students in group rand_num
      i++;                      // Move onto next student
    }
    // Else produce another rand_num and try again
  }

  // Assign remaining students to groups with less than 5 members
  for (int i = 0; i < s.size(); i++)
  {
    if (s.at(i).group == -1) // Check if student is unassigned
    {
      for (int j = 0; j < g.size(); j++)
      {
        if (g[j] < 5) // Check if group has less than 5 members
        {
          s.at(i).group = j; // Assign student to group j
          g[j]++;            // Increment number of students in group j
          break;             // Move onto next unassigned student
        }
      }
    }
  }

  return s;
}

// print student ID and his group
void PrintStudents(const std::vector<Student> &s)
{
  for (const auto &student : s)
  {
    std::cout << "Student: " << student.id << " Group: " << student.group << std::endl;
  }
}

// print group index and he numbers of student inside the group
void PrintGroup(const std::unordered_map<int, int> g)
{
  for (const auto &[key, value] : g)
  {
    std::cout << "Group: " << key << " # of Students: " << value << std::endl;
  }
}

#endif
