#include <stdio.h>
#include <string.h>

int firstUniqChar(char * s)
{
    int counts[26];
    memset(counts, 0, sizeof(int) * 26);

    int i;
    int slen = strlen(s);
    for (i = 0; i < slen; i++)
    {
        char c = s[i];
        counts[c - 'a'] += 1;
    }

    for (i = 0; i < slen; i++) {
        char c = s[i];
        if (counts[c - 'a'] == 1)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    char *string = {"leetcode"};
    firstUniqChar(string);
}
