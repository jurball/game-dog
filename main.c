#include <stdio.h>
#include <conio.h>

int main()
{
    char input;

    int set_size_y = 12;
    int set_size_x = 35;

    int random = 20;
    int y = 1;
    int x = 10;
    int yA = 8;
    int xA = 15;
    int cy = 0;
    int cx = 0;

    int cout = 0;

    char size[set_size_y][set_size_x];

    printf("Press E to close a game\n");

    do {
        // Start Place
        sprintf(size[0], "###################################"); // size x

        for(int i = 1; i < set_size_y; i++)
            sprintf(size[i], "#                                 #"); // size y

        sprintf(size[set_size_y-1], "###################################"); // size x

        size[yA][xA] = '*'; // apple
        size[y][x] = '@'; cx = x; cy = y; // player

        // Update
        for(int i = 0; i < set_size_y; i++)
        {
            for(int j = 0; j < set_size_x; j++)
            {
                printf("%c", size[i][j]);
            }
            printf("\n");
        }
        printf("Score: %d\n", cout);

        input = getch();

        if(input == 'w') y--;
        if(input == 'a') x--;
        if(input == 's') y++;
        if(input == 'd') x++;

        if(size[y][x] == '*') {
            do {
                yA = rand()%random; xA = rand()%random;
            } while(size[yA][xA] == '#');
            cout++;
        }

        if(size[y][x] == '#') { x = cx; y = cy; }

       system("cls");
    } while(input != 'e');
}
