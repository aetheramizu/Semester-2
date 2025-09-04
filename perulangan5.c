#include <stdio.h>

int main()
{
    for (int x = 0; x <= 25; x++)
    {
        for (int y = 0; y <= 25; y++)
        {
            for (int z = 25; z >= 0; z--)
            {
                if (x + y + z == 25)
                    printf("%d + %d + %d = 25 \n", x, y, z);
            }
        }
    }
}