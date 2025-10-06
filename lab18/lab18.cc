#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// ฟังก์ชันต้นฉบับตามโจทย์
void loadScores(char *filename, int student_ids[], int scores[], int *count);
void findMinMax(int scores[], int count, int *min, int *max);
void sortScores(int student_ids[], int scores[], int count);
int binarySearch(int student_ids[], int scores[], int count, int student_id);

int main() {
    int student_ids[MAX];
    int scores[MAX];
    int count = 0;
    int choice;
    int minScore, maxScore;
    int student_id, index;

    do {
        printf("\nStudent Score Management\n");
        printf("1. Load Scores from File\n");
        printf("2. Show Min and Max Scores\n");
        printf("3. Sort Scores in Ascending Order\n");
        printf("4. Search Score by Student ID\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                loadScores("scores.txt", student_ids, scores, &count);
                printf("Scores loaded successfully!\n");
                break;

            case 2:
                if (count == 0) {
                    printf("No data loaded.\n");
                } else {
                    findMinMax(scores, count, &minScore, &maxScore);
                    printf("Minimum Score: %d\n", minScore);
                    printf("Maximum Score: %d\n", maxScore);
                }
                break;

            case 3:
                if (count == 0) {
                    printf("No data loaded.\n");
                } else {
                    sortScores(student_ids, scores, count);
                    printf("Sorted Scores:\n");
                    for (int i = 0; i < count; i++) {
                        printf("Student ID: %d, Score: %d\n", student_ids[i], scores[i]);
                    }
                }
                break;

            case 4:
                if (count == 0) {
                    printf("No data loaded.\n");
                } else {
                    printf("Enter Student ID to Search: ");
                    scanf("%d", &student_id);
                    index = binarySearch(student_ids, scores, count, student_id);
                    if (index != -1) {
                        printf("Score for Student ID %d: %d\n", student_id, scores[index]);
                    } else {
                        printf("Student ID %d not found.\n", student_id);
                    }
                }
                break;

            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}

// โหลดข้อมูลจากไฟล์
void loadScores(char *filename, int student_ids[], int scores[], int *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Cannot open file %s\n", filename);
        return;
    }

    *count = 0;
    while (fscanf(file, "%d %d", &student_ids[*count], &scores[*count]) == 2) {
        (*count)++;
        if (*count >= MAX) break;
    }

    fclose(file);
}

// หาค่า min และ max โดยใช้ pointer
void findMinMax(int scores[], int count, int *min, int *max) {
    int *ptr = scores; // ใช้ pointer เข้าถึง array
    *min = *ptr;
    *max = *ptr;
    for (int i = 1; i < count; i++) {
        ptr++;
        if (*ptr < *min) *min = *ptr;
        if (*ptr > *max) *max = *ptr;
    }
}

// เรียงลำดับคะแนนจากน้อยไปมาก พร้อมเรียง student_ids ไปด้วย
void sortScores(int student_ids[], int scores[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (scores[j] > scores[j + 1]) {
                // swap scores
                int tempScore = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = tempScore;
                // swap ids ให้ตรงกัน
                int tempID = student_ids[j];
                student_ids[j] = student_ids[j + 1];
                student_ids[j + 1] = tempID;
            }
        }
    }
}

// ค้นหาคะแนนนักเรียนด้วย binary search (ใช้ student_ids ที่เรียงแล้ว)
int binarySearch(int student_ids[], int scores[], int count, int student_id) {
    int left = 0, right = count - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (student_ids[mid] == student_id) {
            return mid; // เจอ
        } else if (student_ids[mid] < student_id)  {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // ไม่เจอ
}
