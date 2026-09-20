// src/grading.cpp
#include "grading.h"

#include "gradebook.h"

#include <algorithm>

#include "utilities.h"

double student_average(const Gradebook& student, const int num_assignments) {
    double total{};

    // Total the assignment scores for this student
    for (auto i{0}; i < num_assignments; i++) {
        total += student.cores[i];
    }

    return total / num_assignments;
}

double assignment_average(const Gradebook* book, int assignment_index, const int num_students, const int num_assignments) {
    double total{};

    // Total this assignment's score down every student row
    for (auto i{0}; i < num_students; i++) {
        total += book[i].scores[assignment_index];
    }

    return total / num_students;
}

double class_average(const Gradebook* book, const int num_students, const int num_assignments) {
    double total{};

    for (auto i{0}; i < num_students; i++) {
        for (auto j{0}; j < num_assignments; j++) {
            total += book[i].scores[j];
        }
    }

    return total / (num_students * num_assignments);
}

void find_extremes(const Gradebook& student, const int num_students, const int num_assignments, double& lowest, double& highest){
    // Start from a real score so the result is correct for any range of
    // values, including all-negative ones
    lowest = student.scores[0];
    highest = student.scores[0];

    for (auto i{1}; i < num_assignments; i++) {
        if (student.scores[i] < lowest) {
            lowest = student.scores[i];
        }
        if (student.scores[i] > highest) {
            highest = student.scores[i];
        }
    }
}

int count_grade(const Gradebook* book, char target, const int num_students, const int num_assignments) {
    int count{};

    for (auto i{0}; i < num_students; i++) {
        if (letter_grade(student_average(book[i]) == target) {
            count++;
        }
    }

    return count;
}

bool has_perfect_score(const Gradebook& student, const int num_students, const int num_assignments) {
    for (auto i{0}; i < num_assignments; i++) {
        if (student.scores[i] >= 100.0) {
            return true;
        }
    }

    return false;
}

bool is_at_risk(const Gradebook& student, const int num_students, const int num_assignments) {
    if (student_average(student) < 70.0) {
        return true;
    }

    for (auto i{0}; i < num_assignments; i++) {
        if (student.scores[i] < 50.0) {
            return true;
        }
    }

    return false;
}
