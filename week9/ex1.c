#include <stdio.h>
#include <stdlib.h>

struct Page {
    int id;
    int bits;
};

char *binString(int n)
{
    static char bin[17];
    int mask = 256;
    for(int x=0;x<16;x+=2)
    {
        bin[x] = n & mask ? '1' : '0';
        bin[x + 1] = ' ';
        mask >>= 1;
    }
    bin[16] = '\0';

    return(bin);
}

void print_stack(struct Page* pages, int num) {
    for (int i = 0; i < num; i++) {
        char* num = binString(pages[i].bits);
        printf("%s\n", num);
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    int number_of_pages = atoi(argv[1]);
    double hit_counter = 0;
    double miss_counter = 0;
    struct Page* pages = malloc(sizeof(struct Page) * number_of_pages);
    for (int i = 0; i < number_of_pages; i++) {
        struct Page page;
        page.id = -1;
        page.bits = 0b000000000;
        pages[i] = page;
    }
    FILE* inputFile = fopen("input.txt", "r");
    int num;
    int temp = 0b000000000;
    temp = temp >> 1;
    while (!feof(inputFile)) {
        fscanf(inputFile, "%d", &num);
        int flag_found = 0;
        int free_space_page_index = -1;
        int minimal_number = 0b111111111;
        int index_of_minimal = -1;
        for (int i = 0; i < number_of_pages; i++) {
            pages[i].bits >>= 1;
            if (pages[i].id == num) {
                hit_counter++;
                pages[i].bits += 0b100000000;
                flag_found = 1;
            }
            if (pages[i].bits < minimal_number) {
                minimal_number = pages[i].bits;
                index_of_minimal = i;
            }
            if (pages[i].id == -1 && free_space_page_index == -1) {
                free_space_page_index = i;
            }
        }
        if (flag_found == 0 && num != -1) {
            if (free_space_page_index != -1) {
                miss_counter++;
                pages[free_space_page_index].id = num;
                pages[free_space_page_index].bits = 0b100000000;
            } else {
                miss_counter++;
                pages[index_of_minimal].id = num;
                pages[index_of_minimal].bits = 0b100000000;
            }
        }
        if (feof(inputFile)) {
            break;
        }
    }
    printf("Number of hits: %.0f\n", hit_counter);
    printf("Number of misses: %.0f\n", miss_counter);
    printf("Hit/miss ratio is: %f\n", hit_counter / (miss_counter));
    return 0;
}