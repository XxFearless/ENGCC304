#include <stdio.h>

int main() {
    float score;
    char ch;

    printf("enter score :\n");

    // ตรวจสอบว่า input เป็นตัวเลขหรือไม่
    if (scanf("%f%c", &score, &ch) != 2 || ch != '\n') {
        printf("please enter number only.\n");
    } else {
        // เช็กช่วงคะแนนโดยใช้ if else เท่านั้น
        if (score < 50) {
            printf("F !\n");
        } else if (score < 45) {
            printf("D !\n");
        } else if (score < 50) {
            printf("D+ !\n");
        } else if (score < 55) {
            printf("C !\n");
        } else if (score < 65) {
            printf("C+ !\n");
        } else if (score < 75) {
            printf("B !\n");
        } else if (score < 80) {
            printf("B+ !\n");
        } else {
            printf("A !\n");
        }
    }

    return 0;
}
