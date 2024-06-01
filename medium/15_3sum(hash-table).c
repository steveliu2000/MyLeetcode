/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define TABLE_SIZE 30

struct hashNode {
    int num;
    int count;
    struct hashNode *next;
};

int hash_function(int val) {
    return (val % TABLE_SIZE + TABLE_SIZE) % TABLE_SIZE; // Handle negative values
}

struct hashNode* find_hash_table(struct hashNode** hash_table, int val) {
    int index = hash_function(val);
    struct hashNode* ptr = hash_table[index];
    while (ptr) {
        if (ptr->num == val) return ptr;
        ptr = ptr->next;
    }
    return NULL;
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    //initialize the hash table to NULL
    struct hashNode* ht[TABLE_SIZE] = {NULL};
    struct hashNode* ptr, * ptr2, * ptr3;
    int index, i, j;

    for (i = 0; i < numsSize; ++i) {
        ptr = find_hash_table(ht, nums[i]);
        if (ptr != NULL) ptr->count++; //count+1;
        else {
            ptr = malloc(sizeof(struct hashNode));
            ptr->num = nums[i];
            ptr->count = 1;
            index = hash_function(nums[i]);
            ptr->next = ht[index];
            ht[index] = ptr;
        }
    }
    
    *returnSize = 0;
    int **out = (int**)malloc(sizeof(int*) * 10);
    
    for (i = 0; i < TABLE_SIZE; ++i) {
        ptr = ht[i];
        while (ptr != NULL) {
            ptr->count--;
            for (j = i; j < TABLE_SIZE; ++j) {
                ptr2 = ht[j];
                while (ptr2 != NULL) {
                    if (ptr2->count <= 0) {
                        ptr2 = ptr2->next;
                        continue;
                    }
                    int target = 0 - ptr->num - ptr2->num;
                    if (target < ptr2->num) { // Ensures unique triplet order
                        ptr2 = ptr2->next;
                        continue;
                    }
                    ptr2->count--;
                    ptr3 = find_hash_table(ht, target);
                    if (ptr3 != NULL && ptr3->count > 0) {
                        if (*returnSize > 0 && *returnSize % 10 == 0)
                            out = (int**)realloc(out, (*returnSize + 10) * sizeof(int*));
                        out[*returnSize] = (int*) malloc(sizeof(int) * 3);
                        out[*returnSize][0] = ptr->num;
                        out[*returnSize][1] = ptr2->num;
                        out[*returnSize][2] = ptr3->num;
                        (*returnSize)++;
                    }
                    ptr2->count++;
                    ptr2 = ptr2->next;
                }
            }
            ptr->count = 0;
            ptr = ptr->next;
        }
    }
    
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; ++i)
        (*returnColumnSizes)[i] = 3;
    
    // Free the allocated memory for the hash table nodes
    for (int i = 0; i < TABLE_SIZE; ++i) {
        struct hashNode* current = ht[i];
        while (current != NULL) {
            struct hashNode* temp = current;
            current = current->next;
            free(temp);
        }
    }
    return out;
}
