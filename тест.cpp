#include <stdio.h>
#include <ctype.h>
#include <string.h>

double find_a_b_c(char str[])
{
    double x = 0;
    int counter = 0;
    while (str[counter] != ' ')
    {
        x = x*10 + str[counter] - 48;
        printf("%d \n", str[counter]);
        printf("%d \n", x);
        counter += 1;
    }
    return x;
}

int is_it_correct(char x)
{
    return isdigit(x) or isspace(x);
}

bool is_it_space(char x)
{
    return isspace(x);
}

int main()
{
    char str[1000] = {};
    int counter = 0, space_counter = 0;
    bool checker = true;
    str[counter] = getchar();
    checker = is_it_correct(str[counter]);
    while (str[counter] != '\n' && checker == true)
    {
        counter += 1;
        str[counter] = getchar();
        if (str[counter] == '\n')
            break;
        checker = is_it_correct(str[counter]);
        space_counter += is_it_space(str[counter]);
    }
    if (checker and (space_counter == 2))
    {
        printf("Correct\n %d", find_a_b_c(str));

    }
    else
    {
        printf("Ups... Input in incorrect, repeat\n");

    }
}
