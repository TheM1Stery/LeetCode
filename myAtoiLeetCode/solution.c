#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myAtoi(char* s);

int main(int argc, char *argv[]) {
    int answer = myAtoi("-42");
    printf("%d\n", answer);
}

char *trim_lead_whitespaces(char *str) {
    while (*str == ' ')
        str++;
    return str;
}

char *get_digits(char *str) {
    int count_of_digits = 0;
    char *s = str;
    while (*s != '\0' && isdigit(*s)) {
        count_of_digits++;
        s++;
    }
    if (count_of_digits == 0){
        return NULL;
    }
    printf("s=%s\ncount - %d\n", str, count_of_digits);
    char *digit_string = (char*)calloc(count_of_digits + 1, sizeof(char));
    strncpy(digit_string, str, count_of_digits);
    return digit_string;
}

int myAtoi(char *s) {
    char *str = trim_lead_whitespaces(s);
    int answer = 1;
    if (*str == '-'){
        answer *= -1;
    }
    if (*str == '-' || *str == '+'){
        str++;
    }
    char *digits = get_digits(str);
    if (digits == NULL)
        return 0;
    long atol_r = answer * atol(digits);
    if (atol_r < INT_MIN){
        answer = INT_MIN;
    }else if (atol_r > INT_MAX){
        answer = INT_MAX;
    }else {
        answer = atol_r;
    }
    free(digits);
    return answer;
}
