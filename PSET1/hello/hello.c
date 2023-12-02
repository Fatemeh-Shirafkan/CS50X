#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get username
    string name = get_string("What's your name? ");

    // Say hello to the username
    printf("hello, %s\n", name);
}