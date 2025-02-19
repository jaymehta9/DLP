#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STATES 100
#define MAX_SYMBOLS 100

void finite_automata() {
    int num_inputs, num_states, initial_state, num_accepting_states;
    int accepting_states[MAX_STATES];
    char input_symbols[MAX_SYMBOLS];
    int transition_table[MAX_STATES][MAX_SYMBOLS];
    char input_string[100];

    printf("Finite Automata Setup\n");

    
    printf("Number of input symbols: ");
    scanf("%d", &num_inputs);
    printf("Enter the input symbols (space-separated): ");
    for (int i = 0; i < num_inputs; i++) {
        scanf(" %c", &input_symbols[i]);
    }

    printf("Number of states: ");
    scanf("%d", &num_states);

    printf("Initial state: ");
    scanf("%d", &initial_state);

    printf("Number of accepting states: ");
    scanf("%d", &num_accepting_states);
    printf("Enter the accepting states (space-separated): ");
    for (int i = 0; i < num_accepting_states; i++) {
        scanf("%d", &accepting_states[i]);
    }

        printf("\nEnter the transition table:\n");
    for (int i = 1; i <= num_states; i++) {
        for (int j = 0; j < num_inputs; j++) {
            printf("State %d on input '%c' transitions to: ", i, input_symbols[j]);
            scanf("%d", &transition_table[i][j]);
        }
    }

    while (1) {
        printf("\nEnter input string: ");
        scanf("%s", input_string);

        int current_state = initial_state;
        bool valid = true;

        
        for (int i = 0; input_string[i] != '\0'; i++) {
            char input_char = input_string[i];
            int symbol_index = -1;

           
            for (int j = 0; j < num_inputs; j++) {
                if (input_symbols[j] == input_char) {
                    symbol_index = j;
                    break;
                }
            }

            if (symbol_index == -1) {
                printf("Invalid symbol '%c' in input string.\n", input_char);
                valid = false;
                break;
            }

            current_state = transition_table[current_state][symbol_index];
        }

        if (valid) {
            
            bool accepted = false;
            for (int i = 0; i < num_accepting_states; i++) {
                if (current_state == accepting_states[i]) {
                    accepted = true;
                    break;
                }
            }

            if (accepted) {
                printf("\nInput string is ACCEPTED by the finite automaton.\n");
            } else {
                printf("\nInput string is REJECTED by the finite automaton.\n");
            }
        }

        printf("\nDo you want to test another string? Press 1 for Yes or 0 for Exit: ");
        int choice;
        scanf("%d", &choice);
        if (choice != 1) {
            printf("Exiting...\n");
            break;
        }
    }
}

int main() {
    finite_automata();
    return 0;
}
