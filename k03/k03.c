#include <stdio.h>
#include <string.h>

#define DEBUG

#define ALPHABET_LEN    255

char StrOriginal[] = "On a dark deseart highway, cool wind in my hair.";
char StrKey[] = "wind";

char* ForceSearch(char text[], char key[])
{
    //  ここを実装する
    int pos, i, a=0;
    int text_len, key_len;

    text_len = strlen(text);
    key_len = strlen(key);

    for(pos = 0; pos != text_len - key_len - 1; pos++){
        for(i=0; i<key_len; i++){
            if(key[i] != text[pos]){
                break;
            }else{
                a++;
            }

            if(a==key_len){
                return &text[pos];
            }
        }
    }
    
    return NULL;
}

char* BMSearch(char text[], char key[])
{
    //  ここを実装する
    int index, i, key_len, text_len, table[256];
    
    key_len = strlen(key);
    text_len = strlen(text);
    index = key_len -1;

    //table
    for(index=0; index<=key_len; index++){
        table[index] = key_len;
    }
    for(index=0; index<key_len; index++){
        table[key[index]] = key_len - index - 1;
    }

    //seach
    for(index = key_len -1; index != text_len - 1; index = table[text[index]]){
        for(i=key_len-1; i>key_len; i--){
            if(text[index]==key[i]){
                if(i==0){
                    return &text[index];
                }
            }else{
                break;
            }
        }

        index = table[text[index]];
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