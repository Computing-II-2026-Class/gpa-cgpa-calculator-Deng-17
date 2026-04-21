/*
Name: DENG YAK DENG ATER
Registration Number: 25/X/BIO/01367/PD
*/

#include <stdio.h>

int gradePoint(int score) {
    if (score < 0 || score > 100) return -1;
    if (score >= 80) return 5;
    if (score >= 70) return 4;
    if (score >= 60) return 3;
    if (score >= 50) return 2;
    return 0;
}

char gradeChar(int score) {
    if (score >= 80) return 'A';
    if (score >= 70) return 'B';
    if (score >= 60) return 'C';
    if (score >= 50) return 'D';
    return 'F';
}

int main(void) {
    /* Declare variables here */
    const char *codes1[8] = {
        "TEMB 1101", "TEMB 1102", "TEMB 1103", "TEMB 1104",
        "TEMB 1105", "TEMB 1106", "TEMB 1107", "TEMB 1108"
    };

    const char *names1[8] = {
        "Fundamentals of Engineering Mathematics",
        "Biochemistry and Medical Physics",
        "Electrical Engineering Science",
        "Mechanics I",
        "Computing I",
        "Mechanical Drawing",
        "Engineering Profession",
        "Functional Anatomy and Physiology I"
    };

    int credits1[8] = {4, 3, 3, 3, 3, 3, 2, 3};

    const char *codes2[8] = {
        "TEMB 1201", "TEMB 1202", "TEMB 1203", "TEMB 1204",
        "TEMB 1205", "TEMB 1206", "TEMB 1207", "TEMB 1208"
    };

    const char *names2[8] = {
        "Further Engineering Mathematics",
        "Computing II",
        "Mechatronics Drawing",
        "Fluid Mechanics",
        "Thermodynamics",
        "Workshop Practice",
        "Functional Anatomy and Physiology II",
        "Electronics I"
    };

    int credits2[8] = {4, 3, 3, 3, 3, 3, 3, 3};

    int scores1[8], scores2[8];
    int i, gp;

    /* Read 16 scores */
    printf("=== Enter Semester I scores ===\n");
    for (i = 0; i < 8; i++) {
        printf("%s - %s: ", codes1[i], names1[i]);
        scanf("%d", &scores1[i]);

        /* Validate input */
        if (scores1[i] < 0 || scores1[i] > 100) {
            printf("Invalid score entered!\n");
            return 1;
        }
    }

    printf("=== Enter Semester II scores ===\n");
    for (i = 0; i < 8; i++) {
        printf("%s - %s: ", codes2[i], names2[i]);
        scanf("%d", &scores2[i]);

        /* Validate input */
        if (scores2[i] < 0 || scores2[i] > 100) {
            printf("Invalid score entered!\n");
            return 1;
        }
    }

    /* Determine grades and grade points */

    /* Semester I GPA */
    int totalCredits1 = 0;
    double totalWeighted1 = 0.0;

    printf("\n============================================================\n");
    printf("                  ACADEMIC REPORT - YEAR ONE\n");
    printf("============================================================\n");
    printf("\n--- Semester I ---\n");
    printf("%-12s %-45s %6s %5s %2s %10s\n", "Code", "Course", "Score", "Grade", "CU", "Weighted");
    printf("--------------------------------------------------------------------\n");

    for (i = 0; i < 8; i++) {
        gp = gradePoint(scores1[i]);
        double weighted = (double)gp * credits1[i];
        totalWeighted1 += weighted;
        totalCredits1 += credits1[i];
        printf("%-12s %-45s %6d %5c %2d %10.2f\n", codes1[i], names1[i], scores1[i], gradeChar(scores1[i]), credits1[i], weighted);
    }

    double gpa1 = totalWeighted1 / totalCredits1;

    /* Semester II GPA */
    int totalCredits2 = 0;
    double totalWeighted2 = 0.0;

    printf("\n--- Semester II ---\n");
    printf("%-12s %-45s %6s %5s %2s %10s\n", "Code", "Course", "Score", "Grade", "CU", "Weighted");
    printf("--------------------------------------------------------------------\n");

    for (i = 0; i < 8; i++) {
        gp = gradePoint(scores2[i]);
        double weighted = (double)gp * credits2[i];
        totalWeighted2 += weighted;
        totalCredits2 += credits2[i];
        printf("%-12s %-45s %6d %5c %2d %10.2f\n", codes2[i], names2[i], scores2[i], gradeChar(scores2[i]), credits2[i], weighted);
    }

    double gpa2 = totalWeighted2 / totalCredits2;

    /* Compute CGPA */
    double cgpa = (totalWeighted1 + totalWeighted2) / (totalCredits1 + totalCredits2);

    /* Determine classification */
    const char *classification;
    if (cgpa >= 4.40) {
        classification = "First Class";
    } else if (cgpa >= 3.60) {
        classification = "Second Class Upper";
    } else if (cgpa >= 2.80) {
        classification = "Second Class Lower";
    } else if (cgpa >= 2.00) {
        classification = "Pass";
    } else {
        classification = "Fail";
    }

    
    printf("\n============================================================\n");
    printf("Semester I GPA: %.2f\n", gpa1);
    printf("Semester II GPA: %.2f\n", gpa2);
    printf("CGPA: %.2f\n", cgpa);
    printf("Classification: %s\n", classification);
    printf("============================================================\n");

    return 0;
}
