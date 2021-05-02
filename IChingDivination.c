//  I Ching divination: yarrow stalk method

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int yao(void)
{
    int more = 0;
    int yarrow = 50;
    yarrow -= 1;
    
    for(int i = 0; i < 3; i++){
        yarrow -= 1;
        int bundle1 = rand() % (yarrow - 1) + 1;
        int bundle2 = yarrow - bundle1;
        bundle1 %= 4;
        if (bundle1 == 0)
            bundle1 = 4;
        bundle2 %= 4;
        if (bundle2 == 0)
            bundle2 = 4;
        yarrow -= bundle1 + bundle2;

        switch(bundle1 + bundle2 + 1){
        case 4:
        case 5:
            break;
        case 8:
        case 9:
            more++;
            break;
        }
    }
    switch(more){
    case 0:
        //printf("olg yang\n");
        break;
    case 1:
        //printf("young yin\n");
        break;
    case 2:
        //printf("young yang\n");
        break;
    case 3:
        //printf("olg yin\n");
        break;
    }
    
    return more;
}

int main(void)
{
    srand(time(NULL));
    int prob[4] = {0};
    for(int i = 0; i < 100000; i++){
        prob[yao()]++;
    }
    for(int i = 0; i < 4; i++){
        printf("%.2f\n", prob[i] / 100000.);
    }
    return 0;
}
