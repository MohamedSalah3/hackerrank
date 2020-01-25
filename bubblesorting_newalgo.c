#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

// Complete the maximumToys function below.
int maximumToys(int prices_count, int* prices, int k) {
int items=0,sum=0;
for(int i=0;i<prices_count-1;i++)
{
	for(int i=0,j=1;i<prices_count-1,j<prices_count;i++,j++)
	{int temp=0;
		if(prices[i]>prices[j]){
		temp=prices[i];
		prices[i]=prices[j];
		prices[j]=temp;
		}
	}
}

for(int i=0;i<prices_count-1;i++)
{
if(sum<k)
	{
	items++;
	sum += prices[i];
	if(sum >k)
	{
	sum -= prices[i];
	items--;
	}
	}	
else{
	break;
	}
}
printf("sum=%d\n",sum);

printf("%d",items);
return items;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** nk = split_string(readline());

    char* n_endptr;
    char* n_str = nk[0];
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char* k_endptr;
    char* k_str = nk[1];
    int k = strtol(k_str, &k_endptr, 10);

    if (k_endptr == k_str || *k_endptr != '\0') { exit(EXIT_FAILURE); }

    char** prices_temp = split_string(readline());

    int* prices = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        char* prices_item_endptr;
        char* prices_item_str = *(prices_temp + i);
        int prices_item = strtol(prices_item_str, &prices_item_endptr, 10);

        if (prices_item_endptr == prices_item_str || *prices_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(prices + i) = prices_item;
    }

    int prices_count = n;

    int result = maximumToys(prices_count, prices, k);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
