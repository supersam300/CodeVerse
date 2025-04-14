#include <stdio.h>
#include <string.h>

// Function to convert a single Roman character to its integer value
int romanToInt(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}
int rti(char *s) {
    int total = 0;
    int length = strlen(s);//get the length of sting

    for (int i = 0; i < length; i++) {
        int current = romanToInt(s[i]); //get the val from the function and assign it to current
        
        // Check if next character is larger for the case of subtraction
        if (i + 1 < length && current < romanToInt(s[i + 1])) {
            total = total-current; 
        } else {
            total = total + current;
        }
    }
    
    return total;
}

int main() {
    char roman[] = "IV";  // Example Roman numeral
    int result = rti(roman);
    printf("Roman numeral %s is equal to %d\n", roman, result);
    return 0;
}
