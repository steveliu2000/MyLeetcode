/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct pair{
    int word;
    int indexInS;
};

int cmp(const void* a, const void* b) {
    return (((struct pair*)a)->indexInS - ((struct pair*)b)->indexInS);
}
void findSubstringHelper(char* s, char** words, int wordsSize, int* returnSize, int* ans, struct pair* index2, int j) {
    int wordLen = strlen(words[0]), continue_flag;
    struct pair index[wordsSize];
    for (int k = 0; k < wordsSize; ++k)
        index[k] = index2[k];
    char* ptr;
    for (int k = 0; k <= j; ++k) {
        ptr = strstr(s+index[k].indexInS+1, words[index[k].word]);
        if (ptr) {
            index[k].indexInS = ptr - s;
        }
        else return;
    }
    while(1) {
        continue_flag = 0;
        qsort(index, wordsSize, sizeof(struct pair), cmp);
        for (j = 0; j < wordsSize - 1; ++j) {
            // words = ["aa","aa", ...]
            if (index[j].indexInS == index[j + 1].indexInS) {
                ptr = strstr(s+index[j].indexInS+wordLen, words[index[j].word]);
                if (ptr) {
                    index[j].indexInS = ptr - s;
                    qsort(index, wordsSize, sizeof(struct pair), cmp);
                    --j;
                    continue;
                }
                else return;
            }
            // s = "baaa", words = ["ba", "aa"]
            // s = "abaab", words = ["ab","ba"]
            if (index[j].indexInS + wordLen > index[j + 1].indexInS) {
                findSubstringHelper(s, words, wordsSize, returnSize, ans, index, j);
                ptr = strstr(s+index[j + 1].indexInS+1, words[index[j + 1].word]);
                if (ptr) {
                    index[j + 1].indexInS = ptr - s;
                    qsort(index, wordsSize, sizeof(struct pair), cmp);
                    --j;
                    continue;
                }
                else return;
            }
            if (index[j].indexInS + wordLen != index[j + 1].indexInS) return;
        }
        if (continue_flag == 1) continue;
        for (int i = 0; i < *returnSize; ++i)
            if (index[0].indexInS == ans[i]) return;
        ans[*returnSize] = index[0].indexInS;
        (*returnSize)++;
        return;
    }
}


int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    char* ptr;
    struct pair index[wordsSize];
    int wordLen = strlen(words[0]);
    int* ans = (int*)malloc(sizeof(int) * strlen(s));
    *returnSize = 0;
    for (int i = 0; i < wordsSize; ++i) {
        ptr = strstr(s, words[i]);
        if (ptr) {
            index[i].word = i;
            index[i].indexInS = ptr - s;
        }
        else return NULL;
    }

    int j, continue_flag, allWordsSame = 0;
    while (1) {
        continue_flag = 0;
        qsort(index, wordsSize, sizeof(struct pair), cmp);
        if (index[0].indexInS == index[wordsSize-1].indexInS) {
            // all words the same
            allWordsSame = 1;
            break;
        }
        for (j = 0; j < wordsSize - 1; ++j) {
            // words = ["aa","aa", ...]
            if (index[j].indexInS == index[j + 1].indexInS) {
                for (int i = wordsSize - 1; i >= 0; --i)
                    if (strcmp(words[index[j].word], words[index[i].word]) == 0)
                        ptr = strstr(s+index[i].indexInS+1, words[index[j].word]);
                //ptr = strstr(s+index[j].indexInS+wordLen, words[index[j].word]);
                if (ptr) {
                    index[j].indexInS = ptr - s;
                    qsort(index, wordsSize, sizeof(struct pair), cmp);
                    --j;
                    continue;
                }
                break;
            }
            // s = "baaa", words = ["ba", "aa"]
            // s = "abaab", words = ["ab","ba"]
            if (index[j].indexInS + wordLen > index[j + 1].indexInS) {
                findSubstringHelper(s, words, wordsSize, returnSize, ans, index, j);
                for (int i = wordsSize - 1; i >= 0; --i)
                    if (strcmp(words[index[j+1].word], words[index[i].word]) == 0)
                        ptr = strstr(s+index[i].indexInS+1, words[index[j+1].word]);
                //ptr = strstr(s+index[j + 1].indexInS+1, words[index[j + 1].word]);
                if (ptr) {
                    index[j + 1].indexInS = ptr - s;
                    qsort(index, wordsSize, sizeof(struct pair), cmp);
                    --j;
                    continue;
                }
                break;
            }
            if (index[j].indexInS + wordLen != index[j + 1].indexInS) {
                ptr = strstr(s+index[0].indexInS+1, words[index[0].word]);
                if (ptr) {
                    index[0].indexInS = ptr - s;
                    continue_flag = 1;
                }
                break;
            }
        }
        if (ptr == NULL) break;
        if (continue_flag == 1) continue;
        // find concatenated string
        for (int i = 0; i < *returnSize; ++i)
            if (index[0].indexInS == ans[i]) {
                continue_flag = 1;
                ptr = strstr(s+index[0].indexInS+1, words[index[0].word]);
                if (ptr) {
                    index[0].indexInS = ptr - s;
                }
                break;
            }
        if (continue_flag == 1) continue;
        ans[*returnSize] = index[0].indexInS;
        (*returnSize)++;
        // find next concatenated string
        for (int i = wordsSize - 1; i >= 0; --i)
            if (strcmp(words[index[0].word], words[index[i].word]) == 0)
                ptr = strstr(s+index[i].indexInS+1, words[index[0].word]);
        if (ptr) index[0].indexInS = ptr - s;
        else break; // no more concatenated string
    }
    
    if (allWordsSame == 1) {
        char allWord[wordLen * wordsSize + 1];
        memset(allWord, '\0', wordLen * wordsSize + 1);
        for (int i = 0; i < wordsSize; ++i)
            strcat(allWord, words[0]);
        allWord[wordLen * wordsSize] = '\0';
        ptr = strstr(s, allWord);
        while (ptr) {
            ans[*returnSize] = ptr - s;
            (*returnSize)++;
            ptr = strstr(ptr + 1, allWord);
        }
    }
    return ans;
}
