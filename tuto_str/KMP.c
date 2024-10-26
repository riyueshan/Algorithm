//
// Created by riyueshan on 10/25/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int*getNext(const char*pattern) {
    const int len=(int)strlen(pattern);
    int*next=(int*)malloc(sizeof(int)*len);
    if(!next)return NULL;

    next[0]=-1;
    int i=0,j=-1;
    while(i<len) {
        if(j==-1||pattern[i]==pattern[j]) {
            i++;
            j++;
            next[i]=j;
        }
        else {
            j=next[j];
        }
    }

    return next;
}

int* KMP_next(const char*string,const char*pattern,const int*next) {
    const int len_s=(int)strlen(string);
    const int len_p=(int)strlen(pattern);

    int*result=(int*)malloc(sizeof(int)*len_s);
    if(!result)return NULL;

    int i=0,j=0;
    while(i<len_s) {
        if(j==-1||string[i]==pattern[j]) {
            if(j==len_p-1) {
                result[i-j]=1;
                j=next[j];
                continue;
            }
            i++;
            j++;
        }
        else {
            j=next[j];
        }
    }

    return result;
}

int *getPMT(const char *pattern) {
    const int len = (int) strlen(pattern);
    int *pmt = (int *) malloc(sizeof(int) * len);
    if (!pmt)return NULL;

    pmt[0] = 0;

    // i for 'string', which is actually pattern;j for pattern
    int i = 1, j = 0;
    while (i < len) {
        if (pattern[i] == pattern[j]) {
            // increment 1 than previous 'string[i-1]'
            pmt[i] = pmt[i - 1] + 1;
            i++;
            j++;
        } else {
            if (j == 0) {
                pmt[i] = 0;
                i++;
            } else {
                // backward j to last pmt
                j = pmt[j - 1];
            }
        }
    }

    return pmt;
}

int *KMP_pmt(const char *string, const char *pattern, const int *pmt) {
    const int len_s = (int) strlen(string);
    const int len_p = (int) strlen(pattern);

    int *result = (int *) malloc(sizeof(int) * len_s);
    if (!result)return NULL;

    int i = 0, j = 0;
    while (i < len_s) {
        if (string[i] == pattern[j]) {
            if (j == len_p-1) {
                result[i-j] =1;
                j = pmt[j - 1];
                continue;
            }
            i++;
            j++;
        } else {
            if(j==0) {
                i++;
            }
            else {
                j = pmt[j - 1];
            }
        }
    }

    return result;
}

int main(void) {
    const char string[] = "aaaaaaaaabc";
    const char pattern[] = "aaaa";
    int *pmt = getNext(pattern);
    if(!pmt) {
        return -1;
    }
    int *result = KMP_next(string, pattern, pmt);

    const int len_s=(int)strlen(string);
    for(int i=0;i<len_s;i++) {
        if(result[i]) {
            printf("%d ",i);
        }
    }
    free(pmt);
    free(result);

    return 0;
}
