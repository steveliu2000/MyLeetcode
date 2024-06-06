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
// find substring such that the return index % n == 0
char* findSubstringAtN(char* s, char* word, int n) {
    int i;
    while (1) {
        i = 0;
        for (i = 0; i < n; ++i)
            if (s[i] != word[i]) break;
        if (i == n) return s;
        // not found
        s+=i;
        while (*s != '\0' && i < n) {
            ++s;
            ++i;
        }
        if (i != n) return NULL;
    }
}

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    int wordLen = strlen(words[0]), sLen = strlen(s);
    *returnSize = 0;
    if (wordLen > sLen) return NULL;
    int* ans = (int*)malloc(sizeof(int) * sLen);
    
    int i, j, k;
    char* ptr;

    struct pair index[wordsSize], temp;
    for (i = 0; i < wordLen; ++i) {
        //if (start[i] == 0) continue;
        char* s1 = s + i;
        char* s2 = s1 + wordLen;
        int skip = 0;

        for (j = 0; j < wordsSize; ++j) {
            ptr = findSubstringAtN(s1+skip, words[j], wordLen);
            if (ptr) {
                index[j].word = j;
                index[j].indexInS = ptr - s1;
                if (index[j].indexInS == skip) skip += wordLen;
            }
            else break;
        }
        if (ptr == NULL) continue;
        qsort(index, wordsSize, sizeof(struct pair), cmp);
        while (1) {
            for (j = 0; j < wordsSize - 1; ++j) {
                // words = ["aa","aa", ...]
                if (index[j].indexInS == index[j + 1].indexInS) {
                    ptr = findSubstringAtN(s2+index[j].indexInS, words[index[j].word], wordLen);
                    if (ptr) {
                        index[j+1].indexInS = ptr - s1;
                        temp = index[j + 1];
                        for (k = j+2; k<wordsSize; ++k) {
                            if (index[k].indexInS < temp.indexInS)
                                index[k-1] = index[k];
                            else break;
                        }
                        index[k-1] = temp;
                        --j;
                        continue;
                    }
                    else break;
                }

                if (index[j].indexInS + wordLen != index[j + 1].indexInS) {
                    ptr = findSubstringAtN(s2+index[j].indexInS, words[index[0].word], wordLen);
                    if (ptr) {
                        index[0].indexInS = ptr - s1;
                        temp = index[0];
                        for (k = 1; k<wordsSize; ++k) {
                            if (index[k].indexInS < temp.indexInS)
                                index[k-1] = index[k];
                            else break;
                        }
                        index[k-1] = temp;
                        if (j == 0) j = -1;
                        else j = (j-2 < k-2)? j-2:k-2;
                        continue;
                    }
                    break;
                }
            }
            if (ptr == NULL) break;
            while (ptr) {
                ans[*returnSize] = index[0].indexInS + i;
                (*returnSize)++;
                // find next concatenated string
                ptr = findSubstringAtN(s2+index[wordsSize-1].indexInS, words[index[0].word], wordLen);
                if (ptr) index[0].indexInS = ptr - s1;
                else break; // no more concatenated string
                temp = index[0];
                for (k = 1; k<wordsSize; ++k) {
                    index[k-1] = index[k];
                }
                index[k-1] = temp;
                if (index[wordsSize-2].indexInS+wordLen != index[wordsSize-2].indexInS) break;
            }
        }
    }
    return ans;
}
