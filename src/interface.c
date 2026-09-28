#include "interface.h"
#include "utils.h"
#include "aisort.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


static int parse()
{
    char input[INPUT_MAX];
    printf("> ");
    fgets(input, sizeof(input), stdin);
    tolower(input);

    input[strcspn(input, "\n")] = '\0';

    if(strcmp(input, "claude"))
    {
        return 1;
    }
    else if(strcmp(input, "gpt"))
    {
        return 2;
    }
    else if(strcmp(input, "gemini"))
    {
        return 3;
    }
    else if(strcmp(input, "exit"))
    {
        return 4;
    }

    else return 5;



}


void interface()
{   
    bool run = true;

    while(run)
    {   
        
        printf("=== Sorting algorithm testing\n");
        printf("1. Claude\n");
        printf("2. GPT\n");
        printf("3. Gemini\n");
        printf("4. End session\n");

        int option = parse();

        switch(option)
        {
            case 1:
            {
                printf("Running tests with Claude written algorithms...\n");
                printf("Bubble sort: \n");
                test_random(claude_bubble_sort);
                test_reverse(claude_bubble_sort);
                exec_time(claude_bubble_sort);

                printf("Merge sort: \n");
                test_random(claude_merge_sort);
                test_reverse(claude_merge_sort);
                exec_time(claude_merge_sort);

                printf("Quick sort: \n");
                test_random(claude_quick_sort);
                test_reverse(claude_quick_sort);
                exec_time(claude_quick_sort);

            }

            case 2:
            {
                printf("Running tests with GPT written algorithms...\n");
            }

            case 3:
            {
                printf("Running tests with Gemini written algorithms...\n");
            }

            case 4:
            {
                printf("Terminating session...\n");
                run = false;
            }

            default: 
            {
                printf("Unknown input\n");
                break;
            }
        }

    }
}