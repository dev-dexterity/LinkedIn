#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>

bool validity_checker(long long ccnum);
int find_length_cc(long long ccnum);
bool checksum(long long ccnum);
void print_credit_card_name(long long ccnum);

int main()
{
    long long ccnum;

    do
    {
        ccnum = get_long("Enter your credit card number: \n");
    }
    while (ccnum <= 0);

    if (validity_checker(ccnum))
    {
        print_credit_card_name(ccnum);
    }
    else
    {
        printf("INVALID\n");
    }
}

bool validity_checker(long long ccnum)
{
    int len = find_length_cc(ccnum);
    return ((len == 13 || len == 15 || len == 16) && checksum(ccnum)); // this will return if true
}

int find_length_cc(long long ccnum)
{
    int len = 0;
    while (ccnum != 0)
    {
        ccnum = ccnum / 10;
        len++;
    }
    return len;
}

bool checksum(long long ccnum)
{
    int sum = 0;
    long long tempccnum = ccnum;

    while (tempccnum > 0)
    {
        int lastdigit = tempccnum % 10;
        sum = sum + lastdigit;
        tempccnum = tempccnum / 100;
    }

    tempccnum = ccnum / 10;
    while (tempccnum > 0)
    {
        int secondlastdigit = (tempccnum % 10);
        int tempmultiply = secondlastdigit * 2;

        sum = sum + (tempmultiply % 10) + (tempmultiply / 10);

        tempccnum = tempccnum / 100;
    }

    return (sum % 10) == 0;
}

void print_credit_card_name(long long ccnum)
{

    if ((ccnum >= 34e13 && ccnum < 35e13) || (ccnum >= 37e13 && ccnum < 38e13))
    {
        printf("AMEX\n");
    }

    else if (ccnum >= 51e14 && ccnum < 56e14)
    {
        printf("MASTERCARD\n");
    }

    else if ((ccnum >= 4e12 && ccnum < 5e12) || (ccnum >= 4e15 && ccnum < 5e15))
    {
        printf("VISA\n");
    }

    else
    {
        printf("INVALID\n");
    }
}
