// function that validaes if a triangle is correct

#include <stdio.h>
#include <cs50.h>
#include <math.h>

bool valid_triangle(double x, double y, double z);

int main(void)
{
    double x = get_double("Insert first side: \n");
    double y = get_double("Insert second side: \n");
    double z = get_double("Insert third side: \n");
}

bool valid_triangle(double x, double y, double z)
{
    if (x <= 0 && y <= 0 && z <= 0)
    {
        return false;
    }
    if (x + y <= z || y + z <= x || z + x <= y)
    {
        return false;
    }
    return true;
    printf("VALID\n");
}
