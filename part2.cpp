#ifndef PART_2_CPP_INCLUDE
#define PART_2_CPP_INCLUDE

#include <iostream>
#include <random>
#include <unordered_map>
#include <vector>

struct Student {
  int id = -1;
  int group = -1;
};

std::vector<Student> AssignStudents(std::vector<Student>& s, std::unordered_map<int, int>& g) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(0, g.size() - 1);

  int assigned_students = 0;
  int available_spots = g.size() * 5;
  while (assigned_students < s.size() && available_spots > 0) {
    int rand_num = distrib(gen);
    
    if (g[rand_num] < 5) { //only checks the max
      s.at(assigned_students).group = rand_num;
      g[rand_num]++;
      assigned_students++;
      available_spots--;
    }
  }

  return s;
}

void PrintStudents(const std::vector<Student>& s) {
  for (const auto& student : s) {
    std::cout << "Student: " << student.id << " Group: " << student.group << std::endl;
  }
}

void PrintGroups(const std::unordered_map<int, int>& g) {
  for (const auto& [key, value] : g) {
    std::cout << "Group: " << key << " # of Students: " << value << std::endl;
  }
}

#endif