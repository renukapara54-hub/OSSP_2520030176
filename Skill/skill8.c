#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[200], output[500];
    int i = 0, j = 0;

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    while (input[i] != '\0') {
        if (input[i] == '$') {
            i++;
            char var[100];
            int k = 0;

            while (isalnum(input[i]) || input[i] == '_') {
                var[k++] = input[i++];
            }
            var[k] = '\0';

            char *value = getenv(var);

            if (value != NULL) {
                strcpy(&output[j], value);
                j += strlen(value);
            } else {
                strcpy(&output[j], "[UNDEFINED]");
                j += strlen("[UNDEFINED]");
            }
        } else {
            output[j++] = input[i++];
        }
    }

    output[j] = '\0';

    printf("\nExpanded Output:\n%s", output);

    return 0;
}
