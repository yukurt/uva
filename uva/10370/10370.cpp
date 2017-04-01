#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int main() {
    char line[10000];
    char *pch;
    int num_cases, num_students;
    int students_processed, cases_processed;
    int grades[10000];
    int x, i, num_above;
    float ave;
    float above_percentage;

    // 0 start
    // 1 obtained num_cases
    // 2 obtained num_students
    // 3 all cases processed
    int status = 0;

    cases_processed = 0;
    while (1) {
        gets(line);
        pch = strtok(line, " \t\n");

        while (pch) {
            x = atoi(pch);

            if (status == 0) {
                num_cases = x;
                status += 1;
            }
            else if (status == 1) {
                num_students = x;
                students_processed = 0;
                status += 1;
            }
            else if (status == 2) {
                grades[students_processed] = x;
                students_processed += 1;

                if(students_processed == num_students) {
                    cases_processed += 1;

                    ave = 0;
                    for (i = 0; i < num_students; i += 1) {
                        ave += grades[i];
                    }
                    ave /= num_students;

                    for (i = 0, num_above = 0; i < num_students; i += 1) {
                        if (float(grades[i]) > ave) {
                            num_above += 1;
                        }
                    }
                    above_percentage = float(num_above) / float(num_students) * 100;
                    printf("%.3f%\n", above_percentage);

                    if (cases_processed == num_cases) {
                        status = 3;
                        break;
                    }

                    status = 1;
                }
            }

            pch = strtok(NULL, " \t\n");
        }

        if (status == 3) {
            break;
        }
    }

    return 0;
}
