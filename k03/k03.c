#include <stdio.h>
#include <string.h>

#define DEBUG

#define ALPHABET_LEN    255

char StrOriginal[] = "On a dark deseart highway, cool wind in my hair.";
char StrKey[] = "wind";

char* ForceSearch(char text[], char key[])
{
    //  ここを実装する
    int pos;

    for(pos = 0; text[pos] != '$0'; pos++){
        if(text[pos] == key[0] && text[pos+1] == key[1] && text[pos+2] == key[2] && text[pos+3] == key[3]){
            return &text[pos];
        }
    }
    
    return NULL;
}

char* BMSearch(char text[], char key[])
{
    //  ここを実装する
    int index, i, j;
    int key_len;

    key_len = strlen(key);
    index = key_len -1;

    while(text[index] != '$0'){
        if(text[index] == key[key_len - 1] && text[index] == key[key_len - 2] && text[index] == key[key_len - 3] && text[index] == key[key_len - 4]){
            return &text[index - key_len + 1];
        }

        for(i = 1; i < key_len; i++){
            if(text[index] == key[key_len-1-i]){
                index = index + i;
                j=1;
            }
        }

        if(j==1){
            index = index + key_len;
        }
    }

    return NULL;

}

int main(void)
{
    char*   str;
    str = ForceSearch(StrOriginal, StrKey);
    printf("Force Search. Find keyword at:%s\n", str);

    str = BMSearch(StrOriginal, StrKey);
    printf("BM Search. Find keyword at:%s\n", str);

    return 0;
}